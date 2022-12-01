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

Mutex mMutex = createMutex();
Condition mCond = createCondition();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    switch(event) {
      case st(NetEvent)::Disconnect:
        printf("disconnect \n");
        mCond->notify();
      break;
    }
  }
};

int main() {
    //prepare file
    File file = createFile("./tmp/testdata");

    int port = getEnvPort();

    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(OutputStream)::Append);
        String data = createString("");
        for(int i = 0;i < 1024;i++) {
          data = data->append(createString(st(System)::currentTimeMillis()));
        }
        stream->write(data->toByteArray());
        stream->close();
      }
    }

    InetAddress addr = createInet4Address(port);
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();

    int ret = client->connect();
    SocketMonitor monitor = createSocketMonitor();
    int bindret = monitor->bind(client,createMyListener());
    
    ByteArray fileBuff = createByteArray(1024*4);
    FileInputStream stream = createFileInputStream(file);
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
    
    Md md5 = createMd();
    String v1 = md5->encrypt(createFile("./tmp/testdata"));
    String v2 = md5->encrypt(createFile("./tmp/file"));

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