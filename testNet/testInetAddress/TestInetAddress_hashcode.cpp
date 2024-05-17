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

void testHashCode() {
    InetAddress addr1 = Inet4Address::New("192.168.1.1",12);
    InetAddress addr2 = Inet4Address::New("192.168.1.1",13);
    if(addr1->hashcode() == addr2->hashcode()) {
        TEST_OK("InetAddress hashcode case1");
    }
    
    InetAddress addr3 = Inet4Address::New("192.168.1.12",12);
    InetAddress addr4 = Inet4Address::New("192.168.1.12",12);
    if(addr4->hashcode() != addr3->hashcode()) {
        TEST_OK("InetAddress hashcode case2");
    }
    
    TEST_OK("InetAddress hashcode case100");
}