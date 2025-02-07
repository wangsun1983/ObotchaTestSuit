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
    option->setRcvTimeout(1000);
    
    Socket client = SocketBuilder::New()
                    ->setAddress(addr)
                    ->setOption(option)
                    ->newSocket();
    TimeWatcher watcher = TimeWatcher::New();
    int ret = client->connect();
    watcher->start();
    ByteArray data = ByteArray::New(32);
    ret = client->getInputStream()->read(data);
    auto cost = watcher->stop();
    if(cost<995 || cost > 1050) {
        TEST_FAIL("TestLocalSocket Client case8_recv_timeout case1,cost is %d",cost);
    }
    
    if(ret != -1) {
        TEST_FAIL("TestLocalSocket Client case8_recv_timeout case2,ret is %d",ret);
    }
    
    
    TEST_OK("TestLocalSocket Client case8_recv_timeout case100");
    return 0;
}