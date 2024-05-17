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
#include "AtomicNumber.hpp"
#include "CountDownLatch.hpp"
#include "WebSocketServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "Handler.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"


using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1024*32);

AtomicInteger messageCount = AtomicInteger::New(0);
AtomicInteger connectCount = AtomicInteger::New(0);
AtomicInteger disconnectCount = AtomicInteger::New(0);

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
        if(!message->getData()->toString()->sameAs("Hello, World")) {
            TEST_FAIL("WebSocketServer Simple Count test10");
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
    MyWsListener l = MyWsListener::New();

    int port = getEnvPort();
    InetAddress address = Inet4Address::New(port);
    
    WebSocketServer server = WebSocketServerBuilder::New()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->build();

    server->start();
    MyHandler h = MyHandler::New();
    h->sendEmptyMessageDelayed(0,10*1024);
    
    latch->await();
    server->close();
    if(connectCount->get() != 1024*32) {
        TEST_FAIL("WebSocketServer Simple Count test1 [FAILED],connectCount is %d",connectCount->get());
    }

    if(disconnectCount->get() != 1024*32) {
        TEST_FAIL("WebSocketServer Simple Count test2 [FAILED],disconnectCount is %d",disconnectCount->get());
    }

    if(messageCount->get() != 1024*32) {
        TEST_FAIL("WebSocketServer Simple Count test3 [FAILED],messageCount is %d",messageCount->get());
    }

    port++;
    setEnvPort(port);


    TEST_OK("WebSocketServer Simple Count test100");
}
