#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

Mutex mMutex = createMutex();
Condition mCond = createCondition();

FileOutputStream stream = createFileOutputStream("file");

long filesize = 0;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    switch(event) {
      case st(NetEvent)::Message:
        stream->write(data);
        filesize -= data->size();
        if(filesize == 0) {
          mCond->notify();
        }
      break;

      case st(NetEvent)::Disconnect:
      //printf("disconnect!!!! \n");
      //mCond->notify();
      break;
    }
  }
};

int main() {
    //prepare file
    File file = createFile("data");
    filesize = file->length();

    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream1 = createFileOutputStream(file);
        stream1->open(st(OutputStream)::Append);
        String data = createString("");
        for(int i = 0;i < 1024;i++) {
          data = data->append(createString(st(System)::currentTimeMillis()));
        }
        stream1->write(data->toByteArray());
        stream1->close();
      }
    }

    File f = createFile("file");
    f->removeAll();

    stream->open();

    int port = getEnvPort();
    InetAddress addr = createInet4Address(port);

    Socket client = createSocketBuilder()->setAddress(addr)->newDatagramSocket();
    client->bind();

    stream->open(st(OutputStream)::Append);

    SocketMonitor monitor = createSocketMonitor();
    int bindret = monitor->bind(client,createMyListener());

    AutoLock l(mMutex);
    mCond->wait(mMutex);
    usleep(1000*1000);
    Md md5 = createMd();
    String v1 = md5->encrypt(createFile("data"));
    String v2 = md5->encrypt(createFile("file"));

    if(v1 != v2) {
      TEST_FAIL("TestDataGramSocket Server case2_simple_send_file test1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
    }

    port++;
    setEnvPort(port);

    TEST_OK("TestDataGramSocket Server case2_simple_send_file test100");
    return 0;
}