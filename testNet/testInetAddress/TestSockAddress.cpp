#include <stdio.h>
#include <unistd.h>

#include "InetAddress.hpp"
#include "ArrayList.hpp"
#include "Log.hpp"
#include "InetAddress.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSockAddress() {
    SockAddress sockAddr = createSockAddress(st(Net)::Family::Ipv4,
                                         createString("127.1.2.1"),
                                         12);
    if(sockAddr->port() != 12) {
      TEST_FAIL("InetAddress sockAddress case1,port is %d",sockAddr->port());
    }

    if(sockAddr->family() != AF_INET) {
      TEST_FAIL("InetAddress sockAddress case2,sockAddr->family() is %d",sockAddr->family());
    }

    FetchRet(size,addr) = sockAddr->get();

    String ip = createString(inet_ntoa(((sockaddr_in *)addr)->sin_addr));
    if(!ip->sameAs("127.1.2.1")) {
      TEST_FAIL("InetAddress sockAddress case4");
    }

    TEST_OK("InetAddress sockAddress case6");
}
