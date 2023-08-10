#include <atomic>

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

ConcurrentHashMap<int,String> disconnectMessages 
    = createConcurrentHashMap<int,String>();
    
int count = 0;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    int fd = s->getFileDescriptor()->getFd();
    switch(event) {
      case st(NetEvent)::Message: {
        if(data != nullptr && data->toString()->sameAs("hello world")) {
          latch->countDown();
        }
        disconnectMessages->put(fd,createString("OK"));
      } break;
      
      case st(NetEvent)::Disconnect: {
          if(disconnectMessages->remove(fd) == nullptr) {
            AutoLock l(mMutex);
            count++;
            printf("Disconnect before message,fd is %d \n",fd);
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
      printf("count is %d,fail count is %d \n",latch->getCount(),count);
    }
  });
  t->start();
  latch->await();
  monitor->close();

  sock->close();
  sleep(5);
  port++;
  setEnvPort(port);
  
  if(count != 0) {
      TEST_OK("Test Tcp Server case5_simple_multi_client case1,count is %d",count);
  }
  
  if(latch->getCount() != 0) {
          TEST_OK("Test Tcp Server case5_simple_multi_client case2,latch count is %d",latch->getCount());
  }
  TEST_OK("Test Tcp Server case5_simple_multi_client test100");

}
