#include <stdio.h>
#include <unistd.h>
#include <string.h>
//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "EPollObserver.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "NullPointerException.hpp"
#include "TimeWatcher.hpp"
#include "AutoLock.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include <netinet/in.h>
#include "IO.hpp"


using namespace obotcha;

CountDownLatch latch = createCountDownLatch(50);

DECLARE_CLASS(BaseTestServer1) IMPLEMENTS(Thread) {
public:
    void run() {
        struct sockaddr_in serverAddr;
        int opt = 1;
        int port = getEnvPort();
        sock = socket(AF_INET, SOCK_STREAM, 0);
        serverAddr.sin_family = PF_INET;
        serverAddr.sin_port = htons(port);
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)) < 0) {
            return;
        }

        if(bind(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            return;
        }

        int ret = listen(sock, 1024*64);
        {
            observer = createEPollObserver();
            observer->addObserver(sock,EPOLLIN|EPOLLRDHUP,[](int fd,uint32_t events,int msock) {
                if(fd == msock) {
                    struct sockaddr_in client_address;
                    socklen_t client_addrLength = sizeof(struct sockaddr_in);
                    int clientfd = accept( msock, ( struct sockaddr* )&client_address, &client_addrLength );
                    if(clientfd == -1) {
                        printf("accept fail,error is %s \n",strerror(errno));
                    }
                    latch->countDown();
                }
                return st(IO)::Epoll::Result::Ok;
            },sock);
        }
    }

    EPollObserver getObserver() {
        return observer;
    }

    int getSock() {
        return sock;
    }


    void dump() {
        //observer->dump();
    }

private:
    EPollObserver observer;
    int sock;
};

int basetest() {
    //test1
    BaseTestServer1 server1 = createBaseTestServer1();
    server1->start();
    latch->await(1000*100);
    if(latch->getCount() != 0) {
        TEST_FAIL("testEpollObserver case1,count is %d",latch->getCount());
    }
    TEST_OK("testEpollObserver case100");
    
    int port = getEnvPort();
    port++;
    setEnvPort(port);
    return 0;
    //server1->dump();
}
