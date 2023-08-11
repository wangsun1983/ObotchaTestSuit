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

CountDownLatch latch = createCountDownLatch(128);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
    _MyListener(bool v,String name) {
        isServer = v;
        mName = name;
    }
    
    void onSocketMessage(st(Net)::Event event,Socket,ByteArray) {
        printf("wangsl message!!!!! event is %d,name is %s \n",event,mName->toChars());;
        
        if(isServer) {
            return;
        }
        
        if(event == st(Net)::Event::Disconnect) {
            latch->countDown();
        }
    }
    
private:
    bool isServer;
    String mName;
};

void testDisconnect() {
    int port = getEnvPort();
    MyListener l = createMyListener(true,createString("server"));
    //create server
    InetAddress addr = createInet4Address(port);

    auto server = createSocketBuilder()->setAddress(addr)->newServerSocket();
    server->bind();
    SocketMonitor monitor = createSocketMonitor();
    monitor->bind(server,l);
    
    ArrayList<Socket> list = createArrayList<Socket>();
    
    MyListener l2 = createMyListener(false,createString("client"));
    SocketMonitor monitor2 = createSocketMonitor();
    
    for(int i = 0;i < 128;i++) {
      InetAddress addr2 = createInet4Address(port);
      auto sock = createSocketBuilder()->setAddress(addr2)->newSocket();
      int ret = sock->connect();
      //printf("ret is %d,sock fd is %d \n",ret,sock->getFileDescriptor()->getFd());
      monitor2->bind(sock,l2);
      list->add(sock);
    }
    
    setEnvPort(++port);

    usleep(1000*100);
    ForEveryOne(soc,list) {
        soc->close();
    }

    latch->await(1000*2);
    if(latch->getCount() != 0) {
        TEST_FAIL("Test SocketMonitor Disconnect initiavie case1,count is %d",latch->getCount());
    }
    
    monitor->close();
    monitor2->close();
    TEST_OK("Test SocketMonitor Disconnect initiavie case100");
}
