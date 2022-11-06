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

String message = createString("");
bool isFirst = true;

Mutex mMutex = createMutex();
Condition mCond = createCondition();

CountDownLatch latch = createCountDownLatch(1024*12);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    switch(event) {
      case st(NetEvent)::Message: {
        if(data != nullptr && data->toString()->equals("hello world")) {
          latch->countDown();
        }
      }
    }
  }
};

int main() {
  int port = getEnvPort();
  InetAddress addr = createInet4Address(port);
  ServerSocket sock = createSocketBuilder()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  SocketMonitor monitor = createSocketMonitor(16);
  MyListener l = createMyListener();
  monitor->bind(sock,l);

  Thread t = createThread([] {
    while(1) {
      usleep(1000*1000);
      printf("count is %d \n",latch->getCount());
    }
  });
  t->start();
  latch->await();
  monitor->close();

  sock->close();
  sleep(5);
  port++;
  setEnvPort(port);
  TEST_OK("Test Tcp Server case5_simple_multi_client test100");

}
