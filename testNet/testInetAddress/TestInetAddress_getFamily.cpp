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

void testGetFamily() {
    InetAddress addr1 = Inet4Address::New("192.168.1.1",12);
    if(addr1->getFamily() != st(Net)::Family::Ipv4) {
        TEST_FAIL("InetAddress GetFamily case1");
    }
    
    InetAddress addr2 = Inet6Address::New(12);
    if(addr2->getFamily() != st(Net)::Family::Ipv6 ) {
        TEST_FAIL("InetAddress GetFamily case2");
    }
    
    InetAddress addr3 = InetLocalAddress::New("aabbcc");
    if(addr3->getFamily() != st(Net)::Family::Local ) {
        TEST_FAIL("InetAddress GetFamily case3");
    }
    
    TEST_OK("InetAddress GetFamily case100");
}