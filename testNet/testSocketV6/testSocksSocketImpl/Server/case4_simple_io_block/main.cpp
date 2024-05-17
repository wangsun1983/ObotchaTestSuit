#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet6Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "TimeWatcher.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"

using namespace obotcha;

bool isFirst = true;

int main() {
  int port = getEnvPort();
  InetAddress addr = Inet6Address::New(port);
  ServerSocket sock = SocketBuilder::New()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  auto client = sock->accept();
  TimeWatcher watch = TimeWatcher::New();

  while(1) {
    auto stream = client->getInputStream();
    ByteArray data = ByteArray::New(32);
    watch->start();
    int len = stream->read(data);
    long result = watch->stop();
    //printf("result is %ld \n",result);
    if(len == 0) {
      break;
    }
    
    if(result < 90 || result > 105) {
      TEST_FAIL("TestSocketV6 SocksSocketImpl case4_block_io test1,result is %ld",result);
    }
  }

  client->close();
  sock->close();
  sock = nullptr;
  sleep(1);
  port++;
  setEnvPort(port);

  TEST_OK("TestSocketV6 SocksSocketImpl case4_block_io test100");

}