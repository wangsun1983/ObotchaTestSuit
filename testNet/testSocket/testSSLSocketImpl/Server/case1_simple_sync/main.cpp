#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet4Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "SSLServerSocketImpl.hpp"

using namespace obotcha;

//openssl genrsa -out server.key 2048
//openssl req -new -key server.key -out server.csr
//openssl x509 -req -days 3650 -in server.csr -CA ca.crt -CAkey server.key -CAcreateserial -out server.crt -extensions v3_req

String message = createString("");
bool isFirst = true;

Mutex mMutex = createMutex();
Condition mCond = createCondition();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(int event,Socket s,ByteArray data) {
    printf("onSocketMessage,event is %d \n",event);
    switch(event) {
      case Message: {
        printf("message is %s \n",data->toString()->toChars());
        s->getOutputStream()->write(createString("hello")->toByteArray());
      }
    }
  }

};

int main() {
  InetAddress addr = createInet4Address(1222);
  ServerSocket sock = createSocketBuilder()
                        ->setAddress(addr)
                        ->setSSLCretificatePath("server.crt")
                        ->setSSLKeyPath("server.key")
                        ->newSSLServerSocket();

  int result = sock->bind();
  printf("result is %d \n",result);
  SocketMonitor monitor = createSocketMonitor();
  MyListener l = createMyListener();
  monitor->bind(sock,l);
  AutoLock ll(mMutex);
  mCond->wait(mMutex);

  sleep(1);
  int count = message->counts(createString("hello client"));
    
  if(message->counts(createString("hello client")) != 50) {
    printf("---TestDataGramSocket Server case1_simple_sync test2 [FAILED]--- count is %d,message is %s \n",count,message->toChars());
  }

  printf("---TestDataGramSocket Server case1_simple_sync test3 [OK]--- \n");

}