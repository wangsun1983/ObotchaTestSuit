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
#include "InetLocalAddress.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

#include <signal.h>
using namespace obotcha;

#define TEST_COUNT 1024

Condition mwaitcond = Condition::New();
Mutex mMutex = Mutex::New();

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    mwaitcond->notify();
  }
};

CountDownLatch latch = CountDownLatch::New(TEST_COUNT);
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
    signal(SIGPIPE, SIG_IGN);
    SocketMonitor monitor = SocketMonitor::New();
    long sum = 0;

    for(int i = 0;i<TEST_COUNT;i++) {
          InetAddress addr = InetLocalAddress::New("case4_socket");
          Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();
          
          if(client->connect() != 0) {
            TEST_FAIL("TestLocalSocket Client case4_simple_multi_test test1,i is %d,fd is %d",i,client->getFileDescriptor()->getFd());
            continue;
          }

          monitor->bind(client,MyListener::New(i));
    }
    
    {
      AutoLock l(mMutex);
      mwaitcond->wait(mMutex);
    }
    usleep(1000*100);
    if(latch->getCount() != 0) {
      TEST_FAIL("TestLocalSocket Client case4_simple_multi_test test2 cout is %d",latch->getCount());
    }

    TEST_OK("TestLocalSocket Client case4_simple_multi_test test100");
    return 0;
}