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
  int port = getEnvPort();
  InetAddress addr = Inet4Address::New(port);
  ServerSocket sock = SocketBuilder::New()->setAddress(addr)->newServerSocket();
  int result = sock->bind();
  SocketMonitor monitor = SocketMonitor::New();
  MyListener l = MyListener::New();
  monitor->bind(sock,l);
  AutoLock ll(mMutex);
  mCond->wait(mMutex);

  sleep(1);
  int count = message->counts(String::New("hello client"));
    
  if(message->counts(String::New("hello client")) != 50) {
    TEST_FAIL("TestSocksSocketImpl case1_simple_sync test2 [FAILED]--- count is %d,message is %s \n",count,message->toChars());
  }
  monitor->close();

  port++;
  setEnvPort(port);
  TEST_OK("TestSocksSocketImpl case1_simple_sync test3");

}