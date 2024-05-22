#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "HttpPacketWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;


CountDownLatch connectlatch = CountDownLatch::New(1);
int step = 0;

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {
              
          }
          break;

          case st(Net)::Event::Message: {
              printf("write response connect!!! \n");
              if(step == 0) {
                HttpResponse response = HttpResponse::New();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                response->getEntity()->setContent(String::New("hello this is server")->toByteArray());
                w->write(response);
                step = 1;
              } else {
                String entity = msg->getEntity()->getContent()->toString();
                if(!entity->sameAs("hello this is server")) {
                  printf("---TestHttpServer SimpleClientContent test1 [FAILED]---,entity is %s\n",entity->toChars());
                }
                connectlatch->countDown();
              }
          }
          break;

          case st(Net)::Event::Disconnect:{
          }
          break;
      }
  }
};

int main() {
  MyHttpListener listener = MyHttpListener::New();
  HttpOption option = HttpOption::New();
  option->setSSLCertificatePath("server.crt");
  option->setSSLKeyPath("server.key");
  
  HttpServer server = HttpServerBuilder::New()
                    ->setAddress(Inet4Address::New(9260))
                    ->setListener(listener)
                    ->setOption(option)
                    ->build();
  //printf("thread num is %d \n",st(Enviroment)::DefaultgHttpServerThreadsNum);
  server->start();
  connectlatch->await();
  server->close();

  TEST_OK("TestHttpServer SimpleClientContent test100");

  return 0;
}
