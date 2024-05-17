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

String message = String::New("");
bool isFirst = true;

Mutex mMutex = Mutex::New();
Condition mCond = Condition::New();

CountDownLatch latch = CountDownLatch::New(1024*12);

ConcurrentHashMap<int,String> disconnectMessages 
    = ConcurrentHashMap<int,String>::New();
    
int count = 0;

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    int fd = s->getFileDescriptor()->getFd();
    switch(event) {
      case st(Net)::Event::Message: {
        if(data != nullptr && data->toString()->sameAs("hello world")) {
          latch->countDown();
        }
        disconnectMessages->put(fd,String::New("OK"));
      } break;
      
      case st(Net)::Event::Disconnect: {
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
  InetAddress addr = Inet4Address::New(port);
  ServerSocket sock = SocketBuilder::New()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  SocketMonitor monitor = SocketMonitor::New(16);
  MyListener l = MyListener::New();
  monitor->bind(sock,l);

  Thread t = Thread::New([] {
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
