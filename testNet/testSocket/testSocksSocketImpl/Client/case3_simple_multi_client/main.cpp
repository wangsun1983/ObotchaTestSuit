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
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;


CountDownLatch latch = createCountDownLatch(128);
long array[128] = {0};

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
  _MyListener(int i) {
    index = i;
  }

  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message:: {
        //printf("i get a message ,data is %s,fd is %d\n",data->toString()->toChars(),s->getFileDescriptor()->getFd());
        array[index] += data->toString()->toBasicLong();
        s->getOutputStream()->write(createString("abc")->toByteArray());
      }
      break;

      case st(Net)::Event::Disconnect: {
        latch->countDown();
      }
      break;
    }
  }

private:
  int index;
};


int main() {
    SocketMonitor monitor = createSocketMonitor();
    int port = getEnvPort();

    long sum = 0;
    for(int i = 0;i<1024*32;i++) {
      sum+=i;
    }

    for(int i = 0;i<128;i++) {
      InetAddress addr = createInet4Address(port);
      Socket client = createSocketBuilder()->setAddress(addr)->newSocket();
      if(client->connect() != 0) {
        TEST_FAIL("TestTcpSocket case3_simple_multi_test test1,i is %d",i);
        return 1;
      }
      array[i] = 0;
      monitor->bind(client,createMyListener(i));
    }
    
    latch->await();
    for(int i = 0;i <128;i++) {
      if(array[i] != sum) {
        TEST_FAIL("TestTcpSocket case3_simple_multi_test test2,index is %d,array is %d,sum is %d",i,array[i],sum);
      }
    }
    
    port++;
    setEnvPort(port);
    TEST_OK("TestTcpSocket case3_simple_multi_test test100");
    return 0;
}