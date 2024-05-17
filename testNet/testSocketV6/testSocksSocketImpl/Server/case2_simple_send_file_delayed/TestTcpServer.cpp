#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet6Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"


using namespace obotcha;

Mutex mMutex = Mutex::New();
Condition mCond = Condition::New();

FileOutputStream stream = FileOutputStream::New("./tmp/file");

long filesize = 0;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message:
        //printf("i get a data,data size is %d \n",data->size());
        stream->write(data);
        filesize -= data->size();
        if(filesize == 0) {
          mCond->notify();
        }
      break;

      case st(Net)::Event::Disconnect:
      //printf("disconnect!!!! \n");
      //mCond->notify();
      break;
    }
  }
};

int main() {
    //prepare file
    File file = File::New("./tmp/testdata");
    
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
    filesize = file->length();
    stream->open();

    int port = getEnvPort();
    InetAddress addr = Inet6Address::New(port);

    ServerSocket server = SocketBuilder::New()->setAddress(addr)->newServerSocket();
    server->bind();

    stream->open(st(IO)::FileControlFlags::Append);

    SocketMonitor monitor = SocketMonitor::New();
    int bindret = monitor->bind(server,MyListener::New());

    AutoLock l(mMutex);
    mCond->wait(mMutex);
    usleep(1000*1000);
    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/testdata"));
    String v2 = md5->encodeFile(File::New("./tmp/file"));

    if(v1 != v2) {
      TEST_FAIL("TestSocketV6 SocksSocketImpl case2_simple_send_file test1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
    }

    port++;
    setEnvPort(port);

    TEST_OK("TestSocketV6 SocksSocketImpl case2_simple_send_file test100");
    return 0;
}