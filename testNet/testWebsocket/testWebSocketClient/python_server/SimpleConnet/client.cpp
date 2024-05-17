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

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:

    int onData(WebSocketFrame data) {
        String message = data->getData()->toString();
        if(!message->sameAs("i am server")) {
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
    MyWsListener l = MyWsListener::New();
    WebSocketClient client = WebSocketClient::New();
    int port = getEnvPort();
    String url = String::New("ws://127.0.0.1:")->append(String::New(port));
    client->connect(url,l);
    client->sendTextMessage(String::New("hello server"));
    latch->await();
    port++;
    setEnvPort(port);
    TEST_OK("WebSocketClient SimpleConnect case100");
}
