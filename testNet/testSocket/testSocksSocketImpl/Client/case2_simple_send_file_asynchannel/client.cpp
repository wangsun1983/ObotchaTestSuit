#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

Mutex mMutex = Mutex::New();
Condition mCond = Condition::New();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Disconnect:
        printf("disconnect \n");
        mCond->notify();
      break;
    }
  }
};

int main() {
    //prepare file
    File file = File::New("./tmp/testdata");

    int port = getEnvPort();

    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream = FileOutputStream::New(file);
        stream->open(st(IO)::FileControlFlags::Append);
        String data = String::New("");
        for(int i = 0;i < 1024;i++) {
          data = data->append(String::New(st(System)::CurrentTimeMillis()));
        }
        stream->write(data->toByteArray());
        stream->close();
      }
    }

    InetAddress addr = Inet4Address::New(port);
    Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();

    int ret = client->connect();
    SocketMonitor monitor = SocketMonitor::New();
    int bindret = monitor->bind(client,MyListener::New());
    
    ByteArray fileBuff = ByteArray::New(1024*4);
    FileInputStream stream = FileInputStream::New(file);
    stream->open();
    long index = 0;
    long filesize = file->length();
    printf("start test,filesize is %d \n",filesize);
    while(1) {
      long length = stream->read(fileBuff);
      int ret = client->getOutputStream()->write(fileBuff);
      filesize -= length;
      if(filesize == 0) {
        break;
      }
    }
    
    printf("start trace2 \n");
      
    AutoLock l(mMutex);
    mCond->wait(mMutex);
    printf("start trace3 \n");
    
    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/testdata"));
    String v2 = md5->encodeFile(File::New("./tmp/file"));

    if(v1 != v2) {
      TEST_FAIL("TestTcpSocket case2_simple_send_file test1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
      return 0;
    }

    port++;
    setEnvPort(port);
    monitor->close();
    TEST_OK("TestTcpSocket case2_simple_send_file test100");
    return 0;
}