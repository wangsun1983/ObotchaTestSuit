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
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

Mutex mMutex = createMutex();
Condition mCond = createCondition();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message:: 
      mCond->notify();
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

    int port = getEnvPort();

    InetAddress addr = createInet6Address(port);
    Socket client = createSocketBuilder()->setAddress(addr)->newDatagramSocket();
    
    SocketMonitor monitor = createSocketMonitor();
    int bindret = monitor->bind(client,createMyListener());

    int ret = client->connect();
    ByteArray fileBuff = createByteArray(1024*4);
    FileInputStream stream = createFileInputStream(file);
    stream->open();
    long index = 0;
    long filesize = file->length();
    while(1) {
      long length = stream->read(fileBuff);
      int ret = client->getOutputStream()->write(fileBuff);
      AutoLock l(mMutex);
      mCond->wait(mMutex,200);
      
      filesize -= length;
      if(filesize == 0) {
        break;
      }
    }
    stream->close();
    
    Md md5 = createMd();
    String v1 = md5->encodeFile(createFile("./tmp/testdata"));
    String v2 = md5->encodeFile(createFile("./tmp/file"));

    if(v1 != v2) {
      TEST_FAIL("TestDataGramSocket case2_simple_send_file test1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
      return 0;
    }

    TEST_OK("TestDataGramSocket case2_simple_send_file test100");
    return 0;
}