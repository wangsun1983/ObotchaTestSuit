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
    InetAddress addr = createInetLocalAddress("case6_socket");
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();

    int ret = client->connect();
    
    String resp = createString("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    client->close();
    
    if(client->getOutputStream()->write(resp->toByteArray()) != -1) {
        TEST_FAIL("TestLocalSocket Client case6_close case1");
    }
    
    ByteArray data = createByteArray(32);
    if(client->getInputStream()->read(data) != -1) {
        TEST_FAIL("TestLocalSocket Client case6_close case2");
    }
    
    TEST_OK("TestLocalSocket Client case6_close case100");
    return 0;
}