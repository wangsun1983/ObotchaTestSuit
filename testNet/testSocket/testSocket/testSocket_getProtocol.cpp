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

using namespace obotcha;

void testSocketGetProtocol() {
    while(1) {
        InetAddress addr = createInet4Address("10.0.0.1",12);
        SocksSocketImpl impl = createSocksSocketImpl(addr,nullptr);
        Socket s = createSocket(impl);
        if(s->getProtocol() != st(Net)::Protocol::Tcp) {
            TEST_FAIL("Socket getProtocol case1");
        }
        s->close();
        break;
    }

    while(1) {
        InetAddress addr = createInet4Address("10.0.0.1",12);
        DatagramSocketImpl impl = createDatagramSocketImpl(addr,nullptr);
        Socket s = createSocket(impl);
        if(s->getProtocol() != st(Net)::Protocol::Udp) {
            TEST_FAIL("Socket getProtocol case2,protocol is %d",s->getProtocol());
        }
        s->close();
        break;
    }

    while(1) {
        InetAddress addr = createInet4Address("10.0.0.1",12);
        SSLSocksSocketImpl impl = createSSLSocksSocketImpl(addr,nullptr);
        Socket s = createSocket(impl);
        if(s->getProtocol() != st(Net)::Protocol::Ssl) {
            TEST_FAIL("Socket getProtocol case3,protocol is %d",s->getProtocol());
        }
        s->close();
        break;
    }

    TEST_OK("Socket getProtocol case100");
}
