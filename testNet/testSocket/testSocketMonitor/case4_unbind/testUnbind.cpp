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
    void onSocketMessage(st(Net)::Event,Socket,ByteArray) {
        //DoNothing
    }
};

BlockingQueue<Socket> socketQueue = BlockingQueue<Socket>::New();
MyListener listener = MyListener::New();
CountDownLatch latch = CountDownLatch::New(2);

void testUnbind() {
    while(1) {
        SocketMonitor monitor = SocketMonitor::New();
        Thread t1 = Thread::New([&monitor]{
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
        
        Thread t2 = Thread::New([&monitor]{
            for(int i = 0;i <1024*128;i++) {
                auto addr = Inet4Address::New(i%4096 + 4096);
                auto socket = SocketBuilder::New()
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
        usleep(1000*100);
        if(!monitor->isPendingTasksEmpty()) {
            TEST_FAIL("SocketMonitor testUnbind case1,size is %d",monitor->getPendingTaskSize());
        }
        
        if(!monitor->isMonitorSocketEmpty()) {
            TEST_FAIL("SocketMonitor testUnbind case2");
        }

//        if(!monitor->isClientSocketsEmpty()) {
//            TEST_FAIL("SocketMonitor testUnbind case2");
//        }
//        
//        if(!monitor->isServerSocksEmpty()) {
//            TEST_FAIL("SocketMonitor testUnbind case3");
//        }
        break;
    }
    
    
    TEST_OK("Test SocketMonitor close case100");
}
