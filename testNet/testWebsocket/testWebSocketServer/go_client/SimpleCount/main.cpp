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
#include "Inet4Address.hpp"
#include "Handler.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"


using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1024*16);

AtomicInteger messageCount = createAtomicInteger(0);
AtomicInteger connectCount = createAtomicInteger(0);
AtomicInteger disconnectCount = createAtomicInteger(0);

WebSocketServer server;

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("messageLatch is %d,messageCount is %d,connectCount is %d,disconnectCount is %d \n",
        latch->getCount(),
        messageCount->get(),
        connectCount->get(),
        disconnectCount->get());
    //server->dump();
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        
    }

    int onData(WebSocketFrame message,sp<_WebSocketLinker> client) {
        messageCount->incrementAndGet();
        if(!message->getData()->toString()->equals("Hello, World")) {
            TEST_FAIL("WebSocketServer Simple Count test10");
        } else {
            //TEST_FAIL("good!! \n");
        }
        return 0;
    }

    int onConnect(WebSocketLinker client) {
        //TEST_FAIL("onConnect \n");
        connectCount->incrementAndGet();
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
        disconnectCount->incrementAndGet();
        latch->countDown();
        return 0;
    }

    int onPong(WebSocketLinker client) {
        return 0;
    }

    int onPing(WebSocketLinker client) {
        return 0;
    }   
};



int main() {
    MyWsListener l = createMyWsListener();

    int port = getEnvPort();

    InetAddress address = createInet4Address(port);
    
    server = createWebSocketServerBuilder()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->build();

    server->start();

    MyHandler h = createMyHandler();
    h->sendEmptyMessageDelayed(0,10*1024);

    latch->await();
    server->close();
    if(connectCount->get() != 1024*16) {
        TEST_FAIL("WebSocketServer Simple Count test1,connectCount is %d",connectCount->get());
    }

    if(disconnectCount->get() != 1024*16) {
        TEST_FAIL("WebSocketServer Simple Count test2,disconnectCount is %d",disconnectCount->get());
    }

    if(messageCount->get() != 1024*16) {
        TEST_FAIL("WebSocketServer Simple Count test3,messageCount is %d",messageCount->get());
    }

    port++;
    setEnvPort(port);

    TEST_OK("WebSocketServer Simple Count test100");
}
