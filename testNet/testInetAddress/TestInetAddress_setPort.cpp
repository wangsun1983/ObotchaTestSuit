#include <stdio.h>
#include <unistd.h>

#include "InetAddress.hpp"
#include "Inet4Address.hpp"
#include "Inet6Address.hpp"
#include "InetLocalAddress.hpp"
#include "ArrayList.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSetPort() {
    InetAddress addr1 = createInet4Address("192.168.1.1",12);
    if(addr1->getPort() != 12) {
        TEST_FAIL("InetAddress SetPort case1");
    }
    addr1->setPort(22);
    if(addr1->getPort() != 22) {
        TEST_FAIL("InetAddress SetPort case2");
    }

    TEST_OK("InetAddress GetFamily case100");
}