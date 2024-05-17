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
#include "SocketMonitor.hpp"

using namespace obotcha;

void testCloseSocket() {
    SocketMonitor monitor = SocketMonitor::New();
    
    while(1) {
        InetAddress addr = Inet4Address::New("10.0.0.1",12);
        SocksSocketImpl impl = SocksSocketImpl::New(addr,nullptr);
        Socket s = Socket::New(impl);
        monitor->bind(s,nullptr);
        s->close();
        break;
    }
    
    while(1) {
        InetAddress addr = Inet4Address::New("10.0.0.1",12);
        DatagramSocketImpl impl = DatagramSocketImpl::New(addr,nullptr);
        Socket s = Socket::New(impl);
        monitor->bind(s,nullptr);
        s->close();
        break;
    }
    
    while(1) {
        InetAddress addr = Inet4Address::New("10.0.0.1",12);
        SSLSocksSocketImpl impl = SSLSocksSocketImpl::New(addr,nullptr);
        Socket s = Socket::New(impl);
        monitor->bind(s,nullptr);
        s->close();
        break;
    }
    monitor->close();
    TEST_OK("Socket Close Socket case100");
}
