#include <stdio.h>
#include <unistd.h>

#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "WebSocketServer.hpp"
#include "WebSocketListener.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "AutoLock.hpp"
#include "WebSocketProtocol.hpp"
#include "WebSocketComposer.hpp"
#include "File.hpp"
#include "FileOutputStream.hpp"
#include "AtomicInteger.hpp"
#include "CountDownLatch.hpp"
#include "WebSocketServerBuilder.hpp"
#include "System.hpp"
#include "Md.hpp"
#include "Inet4Address.hpp"
#include "Handler.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
    void handleMessage(Message msg) {
        auto client = Cast<WebSocketLinker>(msg->data);
        client->sendTextMessage(createString("hello"));
    }
};

MyHandler handler = createMyHandler();

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        
    }

    int onData(WebSocketFrame message,WebSocketLinker client) {
        //client->sendPingMessage(createString("hello")->toByteArray());
        return 0;
    }

    int onConnect(WebSocketLinker client) {
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
        latch->countDown();
        return 0;
    }

    void onPong(String msg,WebSocketLinker client) {
        //if(!msg->sameAs("hello")) {
        //    TEST_FAIL("WebSocketServer SimplePing test1");
        //}
        //latch->countDown();
    }

    int onPing(String msg,WebSocketLinker client) {
        printf("i receive a message,it is %s \n",msg->toChars());
        if(!msg->sameAs("abc")) {
            TEST_FAIL("WebSocketServer SimplePingByClient test1");
        }
        
        Message myMessage = createMessage();
        myMessage->data = Cast<Object>(client);
        handler->sendMessage(myMessage);
        return 1;
    }

private:
    FileOutputStream stream;
};

int main() {
    MyWsListener l = createMyWsListener();

    int port = getEnvPort();
    InetAddress address = createInet4Address(port);
    WebSocketServer server = createWebSocketServerBuilder()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->build();

    server->start();
    
    latch->await();
    port++;
    setEnvPort(port);
    server->close();
    
    TEST_OK("WebSocketServer SimplePing test100");
}
