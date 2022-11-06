#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

extern void testSocketOptions();

int main() {
    testSocketOptions();
    return 0;
}
