#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "InetLocalAddress.hpp"
#include "TimeWatcher.hpp"
#include "ForEveryOne.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
    //signal(SIGPIPE, SIG_IGN);
    InetAddress addr = InetLocalAddress::New("case6_socket");
    SocketOption option = SocketOption::New();
    option->setConnectTimeout(1000);
    
    //connect 1:
    ConcurrentQueue<Socket> clients = ConcurrentQueue<Socket>::New();
    ArrayList<Thread> threads = ArrayList<Thread>::New();    
    for(int i = 0; i < 32;i++) {
        Thread t = Thread::New([&] {
            Socket client1 = SocketBuilder::New()
                    ->setAddress(addr)
                    ->newSocket();
            client1->connect();
            clients->add(client1);
        });
        t->start();
        threads->add(t);
    }
    
    usleep(1000*100);
    
    Socket client = SocketBuilder::New()
                    ->setAddress(addr)
                    ->setOption(option)
                    ->newSocket();
    TimeWatcher watcher = TimeWatcher::New();
    watcher->start();
    int ret = client->connect();
    auto cost = watcher->stop();
    if(ret != -1) {
        TEST_FAIL("TestLocalSocket Client case7_connect_timeout case1,ret is %d",ret);
    }
    if(cost<995 || cost > 1040) {
        TEST_FAIL("TestLocalSocket Client case7_connect_timeout case2,cost is %d",cost);
    }
    
    ForEveryOne(c,clients) {
        c->close();
    }
    
    ForEveryOne(t,threads) {
        t->join();
    }
    
    TEST_OK("TestLocalSocket Client case7_connect_timeout case100");
    return 0;
}