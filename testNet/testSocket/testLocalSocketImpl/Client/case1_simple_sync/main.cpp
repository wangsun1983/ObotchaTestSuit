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

Mutex disconnectMutex = Mutex::New();
Condition disconnectCond = Condition::New();

String message = String::New("");

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(sp<_Message> msg) {
    AutoLock l(disconnectMutex);
    disconnectCond->notify();
  }
};

MyHandler h = MyHandler::New();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener){
public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message:
          h->removeMessages(1);
          message = message->append(data->toString());
          messageCount++;
          h->sendEmptyMessageDelayed(1,100);
      break;

      case st(Net)::Event::Disconnect:
          //disconnectCount++;
          //AutoLock l(disconnectMutex);
          //disconnectCond->notify();
      break;
    }
  }
};


int main() {
    //signal(SIGPIPE, SIG_IGN);
    InetAddress addr = InetLocalAddress::New("case1_socket");
    Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();

    int ret = client->connect();
    
    String resp = String::New("hello server");
    client->getOutputStream()->write(resp->toByteArray());
    
    SocketMonitor monitor = SocketMonitor::New();
    int bindret = monitor->bind(client,MyListener::New());
    AutoLock l(disconnectMutex);
    disconnectCond->wait(disconnectMutex);
    
    int count = message->counts("hello server");
    if(message->counts("hello server") != 50) {
      TEST_FAIL("TestLocalSocket Client case1_simple_sync test2 count is %d,message is %s",count,message->toChars());
    }

    TEST_OK("TestLocalSocket Client case1_simple_sync test3");
    return 0;
}