#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet4Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"
#include "CountDownLatch.hpp"

using namespace obotcha;

String message = String::New("");
bool isFirst = true;

Mutex mMutex = Mutex::New();
Condition mCond = Condition::New();

CountDownLatch latch = CountDownLatch::New(1024*12);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message: {
        if(data != nullptr && data->toString()->sameAs("hello world")) {
          latch->countDown();
        }
      }
    }
  }
};

int main() {
  int port = getEnvPort();
  InetAddress addr = Inet4Address::New(port);
  ServerSocket sock = SocketBuilder::New()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  SocketMonitor monitor = SocketMonitor::New(4);
  MyListener l = MyListener::New();
  monitor->bind(sock,l);

  Thread t = Thread::New([] {
    while(1) {
      usleep(1000*1000);
      printf("count is %d \n",latch->getCount());
    }
  });
  t->start();

  latch->await();
  monitor->close();

  port++;
  setEnvPort(port);
  TEST_OK("Test Tcp Server case5_simple_multi_client test100");

}
