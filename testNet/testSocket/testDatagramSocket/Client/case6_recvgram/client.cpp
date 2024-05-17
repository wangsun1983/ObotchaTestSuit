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
    InetAddress addr = Inet4Address::New(port);
    Socket client = SocketBuilder::New()->setAddress(addr)->newDatagramSocket();

    int ret = client->connect();
    String resp = String::New("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    SocketInputStream inputstream = Cast<SocketInputStream>(client->getInputStream());
    String acceptStr = String::New("");
    for(int i = 0;i < 50;i++) {
        ByteArray data = ByteArray::New(128);
        auto server = inputstream->recvDatagram(data);
        acceptStr = acceptStr->append(data->toString());
        if(server == nullptr) {
            TEST_FAIL("TestDataGramSocket case6_recvgram case2");
        }
        
        if(server->getInetAddress() == nullptr) {
            TEST_FAIL("TestDataGramSocket case6_recvgram case3");
        }        
    }
    
    if(acceptStr->counts(String::New("hello server")) != 50) {
        TEST_FAIL("TestDataGramSocket case6_recvgram case1,counts is %d",
                acceptStr->counts(String::New("hello server")));
    }
    
    port++;
    setEnvPort(port);

    TEST_OK("TestDataGramSocket case6_recvgram case100");
    return 0;
}