#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Inet4Address.hpp"
#include "AutoLock.hpp"
#include "Condition.hpp"
#include "SSLServerSocketImpl.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"
#include "SocketOption.hpp"

using namespace obotcha;

//openssl genrsa -out server.key 2048
//openssl req -new -key server.key -out server.csr
//openssl x509 -req -days 3650 -in server.csr -CA ca.crt -CAkey server.key -CAcreateserial -out server.crt -extensions v3_req

String message = String::New("");
bool isFirst = true;

Mutex mMutex = Mutex::New();
Condition mCond = Condition::New();

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {

public:
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    printf("onSocketMessage,event is %d \n",event);
    switch(event) {
      case st(Net)::Event::Message: {
        if(isFirst) {
          s->getOutputStream()->write(String::New("hello i am server")->toByteArray());
          isFirst = false;
        } else {
          if(!data->toString()->sameAs("hello i am server")) {
            TEST_FAIL("testSSLSocketImpl simple sync case1");
          }
          mCond->notify();
        }
      }
    }
  }

};

int main() {
  int port = getEnvPort();
  InetAddress addr = Inet4Address::New(port);
  SocketOption option = SocketOption::New();
  option->setSSLCertificatePath(String::New("server.crt"))
        ->setSSLKeyPath("server.key");
        
  ServerSocket sock = SocketBuilder::New()
                        ->setAddress(addr)
                        ->setOption(option)
                        ->newSSLServerSocket();

  int result = sock->bind();
  SocketMonitor monitor = SocketMonitor::New();
  MyListener l = MyListener::New();
  monitor->bind(sock,l);
  AutoLock ll(mMutex);
  mCond->wait(mMutex);

  port++;
  setEnvPort(port);
  monitor->close();
  
  TEST_OK("testSSLSocketImpl simple sync case100");

}
