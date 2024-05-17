#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "InetLocalAddress.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
    //signal(SIGPIPE, SIG_IGN);
    InetAddress addr = InetLocalAddress::New("case5_socket");
    Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();

    int ret = client->connect();
    
    String resp = String::New("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    String result = String::New("");
    for(int i = 0;i < 50;i++) {
        ByteArray data = ByteArray::New(128);
        client->getInputStream()->read(data);
        result = result->append(data->toString());
    }
    
    int count = result->counts("hello server");
    if(result->counts("hello server") != 50) {
      TEST_FAIL("TestLocalSocket Client case5_inputstream case1 count is %d,message is %s",count,result->toChars());
    }

    TEST_OK("TestLocalSocket Client case5_inputstream case100");
    return 0;
}