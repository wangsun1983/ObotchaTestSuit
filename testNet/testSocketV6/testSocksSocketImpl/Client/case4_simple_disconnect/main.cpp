#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet6Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"
#include "CountDownLatch.hpp"
#include "Message.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

#define TEST_NUM 1024

Condition mwaitcond = createCondition();
Mutex mMutex = createMutex();

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    mwaitcond->notify();
  }
};
CountDownLatch latch = createCountDownLatch(TEST_NUM);

MyHandler h = createMyHandler();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
  _MyListener(int i) {
    index = i;
  }

  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message: {
        
      }
      break;

      case st(Net)::Event::Disconnect: {
        //printf("count is %d \n",latch->getCount());
        latch->countDown();
        h->removeMessages(0);
        h->sendEmptyMessageDelayed(0,2000);
      }
      break;
    }
  }

private:
  int index;
};


int main() {
    SocketMonitor monitor = createSocketMonitor();
    long sum = 0;
    int port = getEnvPort();
    printf("port is %d \n",port);

    for(int i = 0;i<TEST_NUM;i++) {
      InetAddress addr = createInet6Address(port);
      Socket client = createSocketBuilder()->setAddress(addr)->newSocket();
      if(client->connect() != 0) {
        TEST_FAIL("TestTcpSocket case4_simple_multi_test test1,i is %d",i);
        continue;
      }

      monitor->bind(client,createMyListener(i));
    }
    
    {
      AutoLock l(mMutex);
      mwaitcond->wait(mMutex);
    }

    if(latch->getCount() != 0) {
      TEST_FAIL("TestTcpSocket case4_simple_multi_test test2 cout is %d",latch->getCount());
    }

    port++;
    setEnvPort(port);

    TEST_OK("TestTcpSocket case4_simple_multi_test test100");
    return 0;
}