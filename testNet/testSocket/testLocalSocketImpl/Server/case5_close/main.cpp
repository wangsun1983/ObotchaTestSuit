#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet4Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "InetLocalAddress.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
  auto addr = createInetLocalAddress("case1_socket");
  auto option = createSocketOption();
  option->setReUseAddr(st(SocketOption)::Ability::Enable);
  auto sock = createSocketBuilder()
              ->setAddress(addr)
              ->setOption(option)
              ->newServerSocket();
  sock->close();
  if(!sock->isClosed()) {
      TEST_FAIL("TestLocalSocket Server case5_close case1");
  }
  
  if(sock->bind() == 0) {
      TEST_FAIL("TestLocalSocket Server case5_close case2");
  }
  
  TEST_OK("TestLocalSocket Server case5_close case100");

}