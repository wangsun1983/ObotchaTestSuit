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
#include "WebSocketServerBuilder.hpp"
#include "CountDownLatch.hpp"
#include "Inet4Address.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        
    }

    int onData(WebSocketFrame message,sp<_WebSocketLinker> client) {
        String data = message->getData()->toString();
        //printf("data is %s \n",data->toChars());
        if(!data->equals("Hello, World")) {
            TEST_FAIL("WebSocketServer Simple Connect By Golang test1");
        }
        latch->countDown();

        return 0;
    }

    int onConnect(WebSocketLinker client) {
        //connectCount->incrementAndGet();
        //printf("on connect \n");
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
        //printf("on disconnect \n");
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
    WebSocketServer server = createWebSocketServerBuilder()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->addListener("mytest2",l)
                            ->build();

    server->start();

    latch->await();
    
    TEST_OK("WebSocketServer Simple Connect By Golang test100");
    
    port++;
    setEnvPort(port);
     TEST_OK("WebSocketServer Simple Connect By Golang test101");

    server->close();
}
