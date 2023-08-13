#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet4Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

String message = createString("");
bool isFirst = true;

Mutex mMutex = createMutex();
Condition mCond = createCondition();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message: {
        if(isFirst) {
          int len = s->getOutputStream()->write(createString("hello client")->toByteArray());
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
  int port = getEnvPort();
  InetAddress addr = createInet4Address(port);
  ServerSocket sock = createSocketBuilder()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  SocketMonitor monitor = createSocketMonitor();
  MyListener l = createMyListener();
  monitor->bind(sock,l);
  AutoLock ll(mMutex);
  mCond->wait(mMutex);

  sleep(1);
  int count = message->counts(createString("hello client"));
    
  if(message->counts(createString("hello client")) != 50) {
    TEST_FAIL("---TestDataGramSocket Server case1_simple_sync test2 [FAILED]--- count is %d,message is %s \n",count,message->toChars());
  }
  monitor->close();

  port++;
  setEnvPort(port);
  TEST_OK("---TestDataGramSocket Server case1_simple_sync test3");

}