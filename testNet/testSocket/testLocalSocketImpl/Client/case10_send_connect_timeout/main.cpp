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
    option->setSndTimeout(1000);
    printf("start trace1 \n");

    Socket client = SocketBuilder::New()
                    ->setAddress(addr)
                    ->setOption(option)
                    ->newSocket();
    printf("start trace2 \n");
    TimeWatcher watcher = TimeWatcher::New();
    int ret = client->connect();
    printf("ret is %d \n",ret);
    ByteArray data = ByteArray::New(1024*1024);
    for(int i = 0;i < 1024*1024;i++) {
        data[i] = 1;
    }
    watcher->start();
    ret = client->getOutputStream()->write(data);
    auto cost = watcher->stop();
    if(cost<995 || cost > 1050) {
        TEST_FAIL("TestLocalSocket Client case9_snd_recv_timeout case1,cost is %d",cost);
    }
    
    if(ret == 1024*1024) {
        TEST_FAIL("TestLocalSocket Client case9_snd_recv_timeout case2,ret is %d",ret);
    }
    
    watcher->start();
    ret = client->getOutputStream()->write(data);
    cost = watcher->stop();
    if(cost<995 || cost > 1050) {
        TEST_FAIL("TestLocalSocket Client case9_snd_recv_timeout case3,cost is %d",cost);
    }
    
    if(ret != -1) {
        TEST_FAIL("TestLocalSocket Client case9_snd_recv_timeout case4,ret is %d,error is %s",ret,strerror(errno));
    }
    
    TEST_OK("TestLocalSocket Client case9_snd_recv_timeout case100");
    return 0;
}