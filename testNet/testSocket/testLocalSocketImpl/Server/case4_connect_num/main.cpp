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

Mutex mu = Mutex::New();
Condition cond = Condition::New();

int main() {
  auto addr = InetLocalAddress::New("case1_socket");
  auto option = SocketOption::New();
  option->setReUseAddr(st(SocketOption)::Ability::Enable);
  option->setWaitAcceptQueueSize(1);
  auto sock = SocketBuilder::New()
              ->setAddress(addr)
              ->setOption(option)
              ->newServerSocket();

  int result = sock->bind();
  
  usleep(1000*10000);
    
  File file = File::New("./tmp/connectNum.txt");
  if(!file->exists()) {
      TEST_FAIL("TestLocalSocket Server case4_connect_num case1");
  }
  
  FileInputStream stream = FileInputStream::New(file);
  stream->open();
  ByteArray connectData = ByteArray::New();
  stream->read(connectData);
  String cc = connectData->toString();
  if(cc == nullptr || !cc->trim()->equals(String::New("2"))) {
      TEST_FAIL("TestLocalSocket Server case4_connect_num case3");
  }
  stream->close();
  file->removeAll();
  
  if(file->exists()) {
      TEST_FAIL("TestLocalSocket Server case4_connect_num case5");
  }
  TEST_OK("TestLocalSocket Server case4_connect_num case100");
}