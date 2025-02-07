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

void testEquals() {
    InetAddress addr1 = Inet4Address::New("192.168.1.1",12);
    InetAddress addr2 = Inet4Address::New("192.168.1.1",13);
    if(addr1->equals(addr2)) {
        TEST_OK("InetAddress equals case1");
    }
    
    InetAddress addr3 = Inet4Address::New("192.168.1.12",12);
    InetAddress addr4 = Inet4Address::New("192.168.1.12",12);
    if(!addr3->equals(addr4)) {
        TEST_OK("InetAddress equals case2");
    }
    
    InetAddress addr5 = Inet4Address::New("192.168.1.12",12);
    InetAddress addr6 = Inet6Address::New("",12);
    if(addr5->equals(addr6)) {
        TEST_OK("InetAddress equals case3");
    }
    
    TEST_OK("InetAddress equals case100");
}