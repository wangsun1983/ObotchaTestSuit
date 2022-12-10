#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "SocksSocketImpl.hpp"
#include "Socket.hpp"
#include "SSLSocksSocketImpl.hpp"
#include "SocketOption.hpp"

using namespace obotcha;

void testSocketOptions() {
    //_SocketOption* setReUseAddr(int);
    SocketOption option = createSocketOption();
    option->setReUseAddr(1);
    if(option->getReUseAddr() != 1) {
        TEST_FAIL("[SocketOption ReUseAddr test case1]");
    }

    //_SocketOption* setDnotRoute(int);
    option->setDnotRoute(2);
    if(option->getDnotRoute() != 2) {
        TEST_FAIL("[SocketOption DnotRoute test case1]");
    }

    //_SocketOption* setBroadcast(int);
    option->setBroadcast(3);
    if(option->getBroadcast() != 3) {
        TEST_FAIL("[SocketOption Broadcast test case1]");
    }

    //_SocketOption* setSndBuffSize(int);
    option->setSndBuffSize(4);
    if(option->getSndBuffSize() != 4) {
        TEST_FAIL("[SocketOption SndBuffSize test case1]");
    }

    //_SocketOption* setRcvBuffSize(int);
    option->setRcvBuffSize(4);
    if(option->getRcvBuffSize() != 4) {
        TEST_FAIL("[SocketOption RcvBuffSize test case1]");
    }

    //_SocketOption* setKeepAlive(int);
    option->setKeepAlive(5);
    if(option->getKeepAlive() != 5) {
        TEST_FAIL("[SocketOption KeepAlive test case1]");
    }

    //_SocketOption* setOobInline(int);
    option->setOobInline(6);
    if(option->getOobInline() != 6) {
        TEST_FAIL("[SocketOption OobInline test case1]");
    }

    //_SocketOption* setNoCheck(int);
    option->setNoCheck(7);
    if(option->getNoCheck() != 7) {
        TEST_FAIL("[SocketOption NoCheck test case1]");
    }

    //_SocketOption* setLinger(int,int);
    option->setLinger(8,9);
    if(option->getLingerOnOFF() != 8 || option->getLingerValue() != 9) {
        TEST_FAIL("[SocketOption Linger test case1]");
    }

    //_SocketOption* setReUsePort(int);
    option->setReUsePort(10);
    if(option->getReUsePort() != 10) {
        TEST_FAIL("[SocketOption ReUsePort test case1]");
    }

    //_SocketOption* setPassCred(int);
    option->setPassCred(11);
    if(option->getPassCred() != 11) {
        TEST_FAIL("[SocketOption PassCred test case1]");
    }

    //_SocketOption* setPeerCred(int);
    option->setPeerCred(12);
    if(option->getPeerCred() != 12) {
        TEST_FAIL("[SocketOption PeerCred test case1]");
    }

    //_SocketOption* setRcvLoWat(int);
    option->setRcvLoWat(13);
    if(option->getRcvLoWat() != 13) {
        TEST_FAIL("[SocketOption RcvLoWat test case1]");
    }

    //_SocketOption* setSndLoWat(int);
    option->setSndLoWat(14);
    if(option->getSndLoWat() != 14) {
        TEST_FAIL("[SocketOption SndLoWat test case1]");
    }

    //_SocketOption* setRcvTimeout(int);
    option->setRcvTimeout(14);
    if(option->getRcvTimeout() != 14) {
        TEST_FAIL("[SocketOption RcvTimeout test case1]");
    }

    //_SocketOption* setSndTimeout(int);
    option->setSndTimeout(15);
    if(option->getSndTimeout() != 15) {
        TEST_FAIL("[SocketOption SndTimeout test case1]");
    }

    //_SocketOption* setBindToDevice(struct ifreq *);
    {
        struct ifreq *p = (struct ifreq *)malloc(sizeof(struct ifreq));
        memset(p,15,sizeof(ifreq));

        option->setBindToDevice(p);

        struct ifreq q;
        option->getBindToDevice(&q);
        if(memcmp(p,&q,sizeof(struct ifreq)) != 0) {
            TEST_FAIL("[SocketOption BindToDevice test case1]");
        }
        free(p);
    }

    //_SocketOption* setAttachFilter(struct sock_fprog *);
    {
        struct sock_fprog *p = (struct sock_fprog *)malloc(sizeof(struct sock_fprog));
        memset(p,16,sizeof(sock_fprog));

        option->setAttachFilter(p);

        struct sock_fprog q;
        option->getAttachFilter(&q);
        if(memcmp(p,&q,sizeof(struct sock_fprog)) != 0) {
            TEST_FAIL("[SocketOption AttachFilter test case1]");
        }
        free(p);
    }

    //_SocketOption* setDetachFilter(int);
    option->setDetachFilter(17);
    if(option->getDetachFilter() != 17) {
        TEST_FAIL("[SocketOption DetachFilter test case1]");
    }

    //_SocketOption* setTimeStamp(int);
    option->setTimeStamp(18);
    if(option->getTimeStamp() != 18) {
        TEST_FAIL("[SocketOption TimeStamp test case1]");
    }

    //_SocketOption* setTimeStampNs(int);
    option->setTimeStampNs(19);
    if(option->getTimeStampNs() != 19) {
        TEST_FAIL("[SocketOption TimeStampNs test case1]");
    }

    //_SocketOption* setTimeStampIng(int);
    option->setTimeStampIng(19);
    if(option->getTimeStampIng() != 19) {
        TEST_FAIL("[SocketOption TimeStampIng test case1]");
    }    

    //_SocketOption* setBusyPoll(int);
    option->setBusyPoll(20);
    if(option->getBusyPoll() != 20) {
        TEST_FAIL("[SocketOption BusyPoll test case1]");
    }    

    //_SocketOption* setMaxPacingRate(unsigned int);
    option->setMaxPacingRate(21);
    if(option->getMaxPacingRate() != 21) {
        TEST_FAIL("[SocketOption MaxPacingRate test case1]");
    }

    //_SocketOption* setReusePortCbpf(struct sock_fprog*);
    {
        struct sock_fprog *p = (struct sock_fprog *)malloc(sizeof(struct sock_fprog));
        memset(p,22,sizeof(sock_fprog));

        option->setReusePortCbpf(p);

        struct sock_fprog q;
        option->getReusePortCbpf(&q);
        if(memcmp(p,&q,sizeof(struct sock_fprog)) != 0) {
            TEST_FAIL("[SocketOption ReusePortCbpf test case1]");
        }
        free(p);
    }

    //_SocketOption* setReusePortEbpf(int);
    option->setReusePortEbpf(23);
    if(option->getReusePortEbpf() != 23) {
        TEST_FAIL("[SocketOption ReusePortEbpf test case1]");
    }

    //_SocketOption* setZeroCopy(int);
    option->setZeroCopy(24);
    if(option->getZeroCopy() != 24) {
        TEST_FAIL("[SocketOption ZeroCopy test case1]");
    }

    //_SocketOption* setConnectionNum(int);
    option->setConnectionNum(25);
    if(option->getConnectionNum() != 25) {
        TEST_FAIL("[SocketOption ConnectionNum test case1]");
    }

    //_SocketOption* setBuffSize(int)
//    option->setBuffSize(26);
//    if(option->getBuffSize() != 26) {
//        TEST_FAIL("[SocketOption ConnectionNum test case1]");
//    }
    
    TEST_OK("SocketOption case100");
}
