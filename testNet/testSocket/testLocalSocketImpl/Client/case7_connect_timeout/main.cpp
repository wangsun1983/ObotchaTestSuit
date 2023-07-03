#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "InetLocalAddress.hpp"
#include "TimeWatcher.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
    //signal(SIGPIPE, SIG_IGN);
    InetAddress addr = createInetLocalAddress("case6_socket");
    SocketOption option = createSocketOption();
    option->setConnectTimeout(1000);
    
    Socket client = createSocketBuilder()
                    ->setAddress(addr)
                    ->setOption(option)
                    ->newSocket();
    
    TimeWatcher watcher = createTimeWatcher();
    watcher->start();
    int ret = client->connect();
    auto cost = watcher->stop();
    if(ret != -1) {
        TEST_FAIL("TestLocalSocket Client case7_connect_timeout case1");
    } else {
        printf("error no is %s \n",strerror(errno));
    }
    
    if(cost<995 || cost > 1005) {
        TEST_FAIL("TestLocalSocket Client case7_connect_timeout case2,cost is %d",cost);
    }
    
    TEST_OK("TestLocalSocket Client case7_connect_timeout case100");
    return 0;
}