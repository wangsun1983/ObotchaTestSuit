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
#include "BlockingQueue.hpp"
#include "SocketBuilder.hpp"

using namespace obotcha;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
    void onSocketMessage(int,Socket,ByteArray) {
        //DoNothing
    }
};

BlockingQueue<Socket> socketQueue = createBlockingQueue<Socket>();
MyListener listener = createMyListener();
CountDownLatch latch = createCountDownLatch(2);

void testUnbind() {
    while(1) {
        SocketMonitor monitor = createSocketMonitor();
        Thread t1 = createThread([&monitor]{
            while(1) {
                auto socket = socketQueue->takeLast();
                if(socket == nullptr) {
                    latch->countDown();
                    break;
                }
                monitor->unbind(socket);
                socket->close();
            }
            latch->countDown();
        });
        t1->start();
        
        Thread t2 = createThread([&monitor]{
            for(int i = 0;i <1024*128;i++) {
                auto addr = createInet4Address(i%4096 + 4096);
                auto socket = createSocketBuilder()
                            ->setAddress(Cast<InetAddress>(addr))
                            ->newSocket();
                            
                monitor->bind(socket,listener);
                socketQueue->putFirst(socket);
            }
            socketQueue->putFirst(nullptr);
            latch->countDown();
        });
        t2->start();
        
        latch->await();
        
        if(!monitor->isPendingTasksEmpty()) {
            TEST_FAIL("SocketMonitor testUnbind case1");
        }
        
        if(!monitor->isClientSocketsEmpty()) {
            TEST_FAIL("SocketMonitor testUnbind case2");
        }
        
        if(!monitor->isServerSocksEmpty()) {
            TEST_FAIL("SocketMonitor testUnbind case3");
        }
        break;
    }
    
    
    TEST_OK("Test SocketMonitor close case100");
}
