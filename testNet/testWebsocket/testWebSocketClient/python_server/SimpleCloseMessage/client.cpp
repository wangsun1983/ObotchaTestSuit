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
        printf("message is %s \n",message->toChars());
        return 0;
    }

    int onConnect() {
        //printf("on connect fd \n");
        return 0;
    }

    int onDisconnect() {
        latch->countDown();
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
    usleep(1000*200);
    printf("start close \n");
    client->close();
    latch->await();
    port++;
    setEnvPort(port);
    TEST_OK("WebSocketClient SimpleCloseMessage case100");
}
