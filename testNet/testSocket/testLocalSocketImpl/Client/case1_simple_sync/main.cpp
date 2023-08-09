#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "InetLocalAddress.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int messageCount = 0;
int disconnectCount = 0;

Mutex disconnectMutex = createMutex();
Condition disconnectCond = createCondition();

String message = createString("");

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(sp<_Message> msg) {
    AutoLock l(disconnectMutex);
    disconnectCond->notify();
  }
};

MyHandler h = createMyHandler();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    switch(event) {
      case st(NetEvent)::Message:
          h->removeMessages(1);
          message = message->append(data->toString());
          messageCount++;
          h->sendEmptyMessageDelayed(1,100);
      break;

      case st(NetEvent)::Disconnect:
          //disconnectCount++;
          //AutoLock l(disconnectMutex);
          //disconnectCond->notify();
      break;
    }
  }
};


int main() {
    //signal(SIGPIPE, SIG_IGN);
    InetAddress addr = createInetLocalAddress("case1_socket");
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();

    int ret = client->connect();
    
    String resp = createString("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    SocketMonitor monitor = createSocketMonitor();
    int bindret = monitor->bind(client,createMyListener());
    AutoLock l(disconnectMutex);
    disconnectCond->wait(disconnectMutex);
    
    int count = message->counts("hello server");
    if(message->counts("hello server") != 50) {
      TEST_FAIL("TestLocalSocket Client case1_simple_sync test2 count is %d,message is %s",count,message->toChars());
    }

    TEST_OK("TestLocalSocket Client case1_simple_sync test3");
    return 0;
}