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

CountDownLatch latch = CountDownLatch::New(128);

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
    MyListener l = MyListener::New(true,String::New("server"));
    //create server
    InetAddress addr = Inet4Address::New(port);

    auto server = SocketBuilder::New()->setAddress(addr)->newServerSocket();
    server->bind();
    SocketMonitor monitor = SocketMonitor::New();
    monitor->bind(server,l);
    
    ArrayList<Socket> list = ArrayList<Socket>::New();
    
    MyListener l2 = MyListener::New(false,String::New("client"));
    SocketMonitor monitor2 = SocketMonitor::New();
    
    for(int i = 0;i < 128;i++) {
      InetAddress addr2 = Inet4Address::New(port);
      auto sock = SocketBuilder::New()->setAddress(addr2)->newSocket();
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
