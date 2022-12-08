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

Mutex mMutex = createMutex();
Condition mCond = createCondition();

FileOutputStream stream = createFileOutputStream("./tmp/file");
long filesize = 0;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    switch(event) {
      case Message:
        //printf("i get a data,data size is %d \n",data->size());
        stream->write(data);
        filesize-= data->size();
        if(filesize == 0) {
          mCond->notify();
        }
        s->getOutputStream()->write(createString(" ")->toByteArray());
      break;

      case Disconnect:
      //printf("disconnect!!!! \n");
      //mCond->notify();
      break;
    }
  }
};

int main() {
    //prepare file
    File file = createFile("./tmp/testdata");
    filesize = file->length();

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

    stream->open();

    int port = getEnvPort();
    InetAddress addr = createInet6Address(port);

    ServerSocket server = createSocketBuilder()->setAddress(addr)->newServerSocket();
    server->bind();

    stream->open(st(OutputStream)::Append);

    SocketMonitor monitor = createSocketMonitor();
    int bindret = monitor->bind(server,createMyListener());

    AutoLock l(mMutex);
    mCond->wait(mMutex);
    usleep(1000*1000);
    Md md5 = createMd();
    String v1 = md5->encrypt(createFile("./tmp/testdata"));
    String v2 = md5->encrypt(createFile("./tmp/file"));

    if(v1 != v2) {
      TEST_FAIL("TestSocketV6 SocksSocketImpl case3_simple_send_file test1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
    }

    port++;
    setEnvPort(port);

    TEST_OK("TestSocketV6 SocksSocketImpl case3_simple_send_file test100");
    return 0;
}