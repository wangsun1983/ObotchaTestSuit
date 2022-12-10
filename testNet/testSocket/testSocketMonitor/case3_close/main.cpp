#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "SocketMonitor.hpp"

using namespace obotcha;
extern void testSocketMonitorClose();

int main() {
    testSocketMonitorClose();   
    return 0;
}
