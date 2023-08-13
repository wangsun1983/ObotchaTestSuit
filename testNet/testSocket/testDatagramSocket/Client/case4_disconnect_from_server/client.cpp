#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;


int main() {
    //prepare file
    int port = getEnvPort();

    InetAddress addr = createInet4Address(port);
    Socket client = createSocketBuilder()->setAddress(addr)->newDatagramSocket();
    int ret = client->connect();
    if(ret != 0) {
        TEST_FAIL("TestDataGramSocket case4_disconnect_from_server case1,ret is %d",ret);
    }
    
    String hello = createString("abc");
    client->getOutputStream()->write(hello->toByteArray());
    client->close();
    
    if(client->getOutputStream() != nullptr) {
       TEST_FAIL("TestDataGramSocket case4_disconnect_from_server case5");
    }
    
    ByteArray indata = createByteArray(4);
    if(client->getInputStream() != nullptr) {
       TEST_FAIL("TestDataGramSocket case4_disconnect_from_server case6");
    }
    
    port++;
    setEnvPort(port);

    TEST_OK("TestDataGramSocket case4_disconnect_from_server case100");
    return 0;
}