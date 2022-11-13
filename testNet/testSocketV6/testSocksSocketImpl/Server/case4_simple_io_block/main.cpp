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
  InetAddress addr = createInet6Address(port);
  ServerSocket sock = createSocketBuilder()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  auto client = sock->accept();
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto stream = client->getInputStream();
    ByteArray data = createByteArray(32);
    watch->start();
    int len = stream->read(data);
    long result = watch->stop();
    //printf("result is %ld \n",result);
    if(len == 0) {
      break;
    }
    
    if(result < 90 || result > 105) {
      TEST_FAIL("Test Tcp Server case4_block_io test1,result is %ld",result);
    }
  }

  client->close();
  sock->close();
  sock = nullptr;
  sleep(1);
  port++;
  setEnvPort(port);

  TEST_OK("Test Tcp Server case4_block_io test100");

}