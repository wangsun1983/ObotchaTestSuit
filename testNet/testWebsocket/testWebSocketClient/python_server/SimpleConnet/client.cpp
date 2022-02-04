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

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:    

    int onData(WebSocketFrame data) {
        String message = data->getData()->toString();
        if(!message->equals("i am server")) {
            TEST_FAIL("WebSocketClient SimpleConnect wrong response: %s",message->toChars());
        }
        printf("message is %s \n",message->toChars());

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

    int onPong(String) {
        //printf("111111 onPong fd \n");
        return 0;
    }

    int onPing(String) {
        //printf("111111 onPing fd \n");
        return 0;
    }
};



int main() {
    MyWsListener l = createMyWsListener();

    WebSocketClient client = createWebSocketClient();
    int port = getEnvPort();
    String url = createString("ws://127.0.0.1:")->append(createString(port));
    client->connect(url,l);
    client->sendTextMessage(createString("hello server"));

    latch->await();
    TEST_OK("WebSocketClient SimpleConnect case100");
}
