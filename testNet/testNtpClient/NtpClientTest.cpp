#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "NtpClient.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
    printf("wangsl trace1 \n");
    NtpClient c = createNtpClient();
    c->bind("ntp.aliyun.com",123);
    long int t = c->get();
    long interval = st(System)::currentTimeMillis() - t;
    if(interval < -100 || interval > 100) {
        TEST_FAIL("testNtpClient case1,interval is %ld",interval);
    }
    
    TEST_OK("testNtpClient case100");
}
