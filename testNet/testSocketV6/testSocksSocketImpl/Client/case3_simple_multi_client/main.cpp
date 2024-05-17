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
#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;


CountDownLatch latch = CountDownLatch::New(128);
long array[128] = {0};

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
  _MyListener(int i) {
    index = i;
  }

  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message: {
        //printf("i get a message ,data is %s,fd is %d\n",data->toString()->toChars(),s->getFileDescriptor()->getFd());
        array[index] += data->toString()->toBasicLong();
        s->getOutputStream()->write(String::New("abc")->toByteArray());
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
    SocketMonitor monitor = SocketMonitor::New();
    long sum = 0;
    for(int i = 0;i<1024*32;i++) {
      sum+=i;
    }

    int port = getEnvPort();
    for(int i = 0;i<128;i++) {
      InetAddress addr = Inet6Address::New(port);
      Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();
      if(client->connect() != 0) {
        TEST_FAIL("TestTcpSocket case3_simple_multi_test case1,i is %d\n",i);
        return 1;
      }
      array[i] = 0;
      monitor->bind(client,MyListener::New(i));
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