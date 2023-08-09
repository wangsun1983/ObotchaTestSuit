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

FileOutputStream stream = createFileOutputStream("./tmp/file");
long filesize = 0;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    switch(event) {
      case st(NetEvent)::Message:
        //printf("i get a data,data size is %d \n",data->size());
        stream->write(data);
        filesize-= data->size();
        if(filesize == 0) {
          mCond->notify();
        }
        s->getOutputStream()->write(createString(" ")->toByteArray());
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
    File file = createFile("./tmp/testdata");
    
    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(OutputStream)::Append);
        String data = createString("");
        for(int i = 0;i < 1024;i++) {
          data = data->append(createString(st(System)::CurrentTimeMillis()));
        }
        stream->write(data->toByteArray());
        stream->close();
      }
    }
    filesize = file->length();
    
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
    String v1 = md5->encodeFile(createFile("./tmp/testdata"));
    String v2 = md5->encodeFile(createFile("./tmp/file"));

    if(v1 != v2) {
      TEST_FAIL("TestDataGramSocket Server case3_simple_send_file test1 ,v1 is %s,v2 is %s ",v1->toChars(),v2->toChars());
      return 0;
    }

    port++;
    setEnvPort(port);

    TEST_OK("TestDataGramSocket Server case3_simple_send_file test100");
    return 0;
}