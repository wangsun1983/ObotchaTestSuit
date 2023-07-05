#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet4Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "InetLocalAddress.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "Thread.hpp"
#include "AutoLock.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"

using namespace obotcha;

int count = 0;

Mutex mu = createMutex();
Condition cond = createCondition();

int main() {
  auto addr = createInetLocalAddress("case1_socket");
  auto option = createSocketOption();
  option->setReUseAddr(true);
  option->setWaitAcceptQueueSize(1);
  auto sock = createSocketBuilder()
              ->setAddress(addr)
              ->setOption(option)
              ->newServerSocket();

  int result = sock->bind();
  
  usleep(1000*10000);
    
  File file = createFile("./tmp/connectNum.txt");
  if(!file->exists()) {
      TEST_FAIL("TestLocalSocket Server case4_connect_num case1");
  }
  
  FileInputStream stream = createFileInputStream(file);
  stream->open();
  ByteArray connectData = createByteArray();
  stream->read(connectData);
  String cc = connectData->toString();
  if(cc == nullptr || !cc->trim()->equals(createString("2"))) {
      TEST_FAIL("TestLocalSocket Server case4_connect_num case3");
  }
  stream->close();
  file->removeAll();
  
  if(file->exists()) {
      TEST_FAIL("TestLocalSocket Server case4_connect_num case5");
  }
  TEST_OK("TestLocalSocket Server case4_connect_num case100");
}