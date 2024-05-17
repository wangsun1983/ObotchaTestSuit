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
#include "Handler.hpp"
#include "Inet4Address.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

AtomicInteger connectCount = AtomicInteger::New(0);
AtomicInteger disconnectCount = AtomicInteger::New(0);
AtomicInteger messageCount = AtomicInteger::New(0);
CountDownLatch latch = CountDownLatch::New(1024*10);

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("messageLatch is %d,connectCount is %d,disconnectCount is %d \n",latch->getCount(),connectCount->get(),disconnectCount->get());
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};


DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        
    }

    int onData(WebSocketFrame message,WebSocketLinker client) {
        messageCount->incrementAndGet();

        if(!message->getData()->toString()->sameAs("Hello, World")) {
            printf("WebSocketServer MultiThread test2 [FAILED],message is %s \n",message->getData()->toString()->toChars());
        }
        return 0;
    }

    int onConnect(WebSocketLinker client) {
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

    if(connectCount->get() != 10*1024 || disconnectCount->get() != 10*1024 || messageCount->get() != 10*1024) {
        TEST_FAIL("WebSocketServer MultiThread test1,connect is %d,disconnect is %d,message is %d",
                connectCount->get(),
                disconnectCount->get(),
                messageCount->get());
    }

    TEST_OK("WebSocketServer MultiThread test100");
}
