#include <signal.h>

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
    signal(SIGPIPE, SIG_IGN);
    InetAddress addr = createInetLocalAddress("case1_socket");
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();

    int ret = client->connect();
    
    Thread t = createThread([&]{
        String resp = createString("hello server");
        while(1) {
            int ret = client->getOutputStream()->write(resp->toByteArray());
            if( ret == -1) {
                break;
            }
            usleep(1000*1000);
        }
    });
    t->start();
    
    TimeWatcher watcher = createTimeWatcher();
    watcher->start();
    t->join(1000*12);
    auto cost = watcher->stop();
    
    if(cost > 11900) {
        TEST_FAIL("TestLocalSocket Client case12_simple_sync case1,cost is %ld",cost);
    }

    TEST_OK("TestLocalSocket Client case12_simple_sync case100");
    return 0;
}