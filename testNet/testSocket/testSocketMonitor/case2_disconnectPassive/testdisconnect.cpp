#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "SocketMonitor.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
    void onSocketMessage(st(Net)::Event event,Socket,ByteArray) {
        if(event == st(Net)::Event::Disconnect) {
            latch->countDown();
        }
    }
};

void testDisconnect() {
    int port = getEnvPort();
    MyListener l = createMyListener();
    SocketMonitor monitor = createSocketMonitor();
    //create server
    InetAddress addr = createInet4Address(port);
    auto server = createSocketBuilder()->setAddress(addr)->newServerSocket();
    int result = server->bind();
    monitor->bind(server,l);
    
    usleep(1000*100);
    server->close();
    
    latch->await(1000*10);
    if(latch->getCount() != 0) {
        TEST_FAIL("Test SocketMonitor Disconnect passive case1,latch is %d",latch->getCount());
    }
    setEnvPort(++port);
    monitor->close();
    TEST_OK("Test SocketMonitor Disconnect passive case100");
}
