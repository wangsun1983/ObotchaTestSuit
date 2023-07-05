#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "InetLocalAddress.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
    //signal(SIGPIPE, SIG_IGN);
    InetAddress addr = createInetLocalAddress("case1_socket");
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();
    int ret = client->connect();  
    String resp = createString("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    auto fd = client->getFileDescriptor();
    SocketImpl impl = createSocketImpl(fd);
    ByteArray data1 = impl->read();
    if(!data1->toString()->equals("hello")) {
        TEST_FAIL("TestLocalSocket Client case14_read_disconnect case1");
    }
    
    usleep(1000*2000);
    ByteArray data2 = impl->read();
    if(data2 != nullptr) {
        TEST_FAIL("TestLocalSocket Client case14_read_disconnect case2");
    }
    
    TEST_OK("TestLocalSocket Client case14_read_disconnect case100");
    return 0;
}