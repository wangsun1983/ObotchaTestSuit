#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

int main() {
    int port = getEnvPort();
    InetAddress addr = createInet4Address(port);
    Socket client = createSocketBuilder()->setAddress(addr)->newDatagramSocket();

    int ret = client->connect();
    String resp = createString("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    SocketInputStream inputstream = Cast<SocketInputStream>(client->getInputStream());
    String acceptStr = createString("");
    for(int i = 0;i < 50;i++) {
        ByteArray data = createByteArray(128);
        auto server = inputstream->recvDatagram(data);
        acceptStr = acceptStr->append(data->toString());
        if(server == nullptr) {
            TEST_FAIL("TestDataGramSocket case6_recvgram case2");
        }
        
        if(server->getInetAddress() == nullptr) {
            TEST_FAIL("TestDataGramSocket case6_recvgram case3");
        }        
    }
    
    if(acceptStr->counts(createString("hello server")) != 50) {
        TEST_FAIL("TestDataGramSocket case6_recvgram case1,counts is %d",
                acceptStr->counts(createString("hello server")));
    }
    
    port++;
    setEnvPort(port);

    TEST_OK("TestDataGramSocket case6_recvgram case100");
    return 0;
}