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

String message = String::New("");
bool isFirst = true;

Mutex mMutex = Mutex::New();
Condition mCond = Condition::New();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message: {
        if(isFirst) {
          int len = s->getOutputStream()->write(String::New("hello client")->toByteArray());
          isFirst = false;
          mCond->notify();
          return;
        }

        message = message->append(data->toString());
      }
    }
  }

};

int main() {
  auto addr = InetLocalAddress::New("case1_socket");
  auto option = SocketOption::New();
  option->setReUseAddr(st(SocketOption)::Ability::Enable);
  auto sock = SocketBuilder::New()
              ->setAddress(addr)
              ->setOption(option)
              ->newServerSocket();

  int result = sock->bind();
  SocketMonitor monitor = SocketMonitor::New();
  MyListener l = MyListener::New();
  monitor->bind(sock,l);
  AutoLock ll(mMutex);
  mCond->wait(mMutex);

  sleep(1);
  int count = message->counts("hello client");
    
  if(message->counts("hello client") != 50) {
    TEST_FAIL("TestLocalSocket Server case1_simple_sync test2 count is %d,message is %s",count,message->toChars());
  }

  TEST_OK("TestLocalSocket Server case1_simple_sync test3");

}