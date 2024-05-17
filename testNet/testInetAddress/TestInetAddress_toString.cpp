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

void testToString() {
    InetAddress addr1 = Inet4Address::New("192.168.1.1",12);
    if(!addr1->toString()->sameAs("ip is 192.168.1.1,port is 12")) {
        TEST_FAIL("InetAddress toString case1,addr is %s",addr1->toString()->toChars());
    }
    
    InetAddress addr2 = Inet6Address::New("AD80:0000:0000:0000:ABAA:0000:00C2:0002",12);
    if(!addr2->toString()->sameAs("ip is ad80::abaa:0:c2:2,port is 12")) {
        TEST_FAIL("InetAddress toString case2,addr is %s",addr2->toString()->toChars());
    }
    
    InetAddress addr3 = InetLocalAddress::New("abcd");
    if(!addr3->toString()->sameAs("local path is abcd")) {
        TEST_FAIL("InetAddress toString case3,addr is %s",addr3->toString()->toChars());
    }
    
    TEST_OK("InetAddress toString case100");
}