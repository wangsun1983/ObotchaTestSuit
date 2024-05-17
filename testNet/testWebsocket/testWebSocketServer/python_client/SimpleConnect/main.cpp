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
#include "WebSocketServerBuilder.hpp"
#include "CountDownLatch.hpp"
#include "Inet4Address.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        
    }

    int onData(WebSocketFrame message,sp<_WebSocketLinker> client) {
        String data = message->getData()->toString();
        //TEST_FAIL("data is %s \n",data->toChars());
        if(!data->sameAs("Hello, World")) {
            TEST_FAIL("WebSocketServer Simple Connect test1");
        }
        latch->countDown();

        return 0;
    }

    int onConnect(WebSocketLinker client) {
        //connectCount->incrementAndGet();
        //TEST_FAIL("on connect \n");
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
        //TEST_FAIL("on disconnect \n");
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
    printf("port is %d \n",port);
    WebSocketServer server = WebSocketServerBuilder::New()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->addListener("mytest2",l)
                            ->build();

    server->start();

    latch->await();
    
    TEST_OK("WebSocketServer Simple Connect test100");

    port++;
    setEnvPort(port);

    server->close();
}
