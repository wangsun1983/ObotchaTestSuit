#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "WebSocketClient.hpp"
#include "WebSocketListener.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "CountDownLatch.hpp"
#include "System.hpp"
#include "Md.hpp"
using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:

    int onData(WebSocketFrame data) {
        String message = data->getData()->toString();
        if(!message->sameAs("closed")) {
            TEST_FAIL("WebSocketClient SimpleConnect wrong response: %s",message->toChars());
        }

        latch->countDown();
        return 0;
    }

    int onConnect() {
        //printf("on connect fd \n");
        return 0;
    }

    int onDisconnect() {
        //printf("111111 on disconnect fd \n");
        return 0;
    }

    void onPong(String) {
        //printf("111111 onPong fd \n");
    }
    
    st(WebSocket)::Response onPing(String) {
        //printf("111111 onPing fd \n");
        return st(WebSocket)::Response::Auto;
    }
};



int main() {
    File file = File::New("./tmp/testdata");

    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream = FileOutputStream::New(file);
        stream->open(st(IO)::FileControlFlags::Append);
        String data = String::New(st(System)::CurrentTimeMillis());
        for(int j = 0;j < 32;j++) {
          data = data->append(String::New(st(System)::CurrentTimeMillis()));
        }
        stream->write(data->toByteArray());
        stream->close();
      }
    }

    MyWsListener l = MyWsListener::New();
    WebSocketClient client = WebSocketClient::New();
    int port = getEnvPort();
    String url = String::New("ws://127.0.0.1:")->append(String::New(port));
    client->connect(url,l);
    File f = File::New("./tmp/testdata");
    client->sendFile(f);
    usleep(1000*200);
    
    Md md5sum = Md::New();
    String base = md5sum->encodeFile(File::New("./tmp/testdata"));

    String newFile = md5sum->encodeFile(File::New("./tmp/file"));

    if(!base->equals(newFile)) {
      TEST_FAIL("WebSocketClient SimpleConnect case100");
    }
    
    port++;
    setEnvPort(port);
    TEST_OK("WebSocketClient SimpleConnect case100");
}
