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
#include "AtomicInteger.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(256);
AtomicInteger connectNum = createAtomicInteger(0);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        
    }

    int onData(WebSocketFrame message,sp<_WebSocketLinker> client) {
        return 0;
    }

    int onConnect(WebSocketLinker client) {
        connectNum->incrementAndGet();
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
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
    WebSocketServer server = createWebSocketServerBuilder()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->addListener("mytest2",l)
                            ->build();

    server->start();
    latch->await();
    
    if(connectNum->get() != 256) {
        TEST_FAIL("WebSocketServer Disconnect Test case1,count is %d",connectNum->get());
    }
    
    TEST_OK("WebSocketServer Disconnect Test case100");

    port++;
    setEnvPort(port);

    server->close();
}
