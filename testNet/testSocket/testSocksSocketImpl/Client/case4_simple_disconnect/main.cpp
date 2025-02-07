#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"
#include "CountDownLatch.hpp"
#include "Message.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

Condition mwaitcond = Condition::New();
Mutex mMutex = Mutex::New();

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    mwaitcond->notify();
  }
};

CountDownLatch latch = CountDownLatch::New(1024);
MyHandler h = MyHandler::New();

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
        //printf("count is %d ",latch->getCount());
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
    SocketMonitor monitor = SocketMonitor::New();
    long sum = 0;
    int port = getEnvPort();

    for(int i = 0;i<1024;i++) {
      InetAddress addr = Inet4Address::New(port);
      Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();
      if(client->connect() != 0) {
        TEST_FAIL("TestTcpSocket case4_simple_multi_test test1,i is %d",i);
        continue;
      }

      monitor->bind(client,MyListener::New(i));
    }
    
    {
      AutoLock l(mMutex);
      mwaitcond->wait(mMutex);
    }

    if(latch->getCount() != 0) {
      TEST_FAIL("TestTcpSocket case4_simple_multi_test test2,cout is %d",latch->getCount());
    }

    port++;
    setEnvPort(port);

    monitor->close();
    TEST_OK("TestTcpSocket case4_simple_multi_test test100");
    return 0;
}