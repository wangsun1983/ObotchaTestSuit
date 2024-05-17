#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "SocketMonitor.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testSocketMonitorClose() {
    while(1) {
        SocketMonitor monitor = SocketMonitor::New();
        monitor->close();
        if(monitor->waitForExit() != 0) {
            TEST_FAIL("Test SocketMonitor close case1");
        }        
        break;
    }
    
    while(1) {
        SocketMonitor monitor = SocketMonitor::New();
        usleep(1000*50);
        monitor->close();
        if(monitor->waitForExit() != 0) {
            TEST_FAIL("Test SocketMonitor close case2");
        }        
        break;
    }
    
    TEST_OK("Test SocketMonitor close case100");
}
