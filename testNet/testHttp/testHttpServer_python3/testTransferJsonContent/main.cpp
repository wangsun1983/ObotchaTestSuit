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
#include "Enviroment.hpp"
#include "HttpMethod.hpp"
#include "NetEvent.hpp"
#include "JsonValue.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "Reflect.hpp"
#include "JsonReader.hpp"

using namespace obotcha;

bool testResult = false;

CountDownLatch latch = createCountDownLatch(2);

DECLARE_CLASS(MyData) {
public:
    int value1;
    String value2;
    DECLARE_REFLECT_FIELD(MyData,value1,value2);
};

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
      printf("countdownlatch is %d \n",latch->getCount());
      this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {
              //connectlatch->countDown();
          }
          break;

          case st(Net)::Event::Message:: {
              if(msg->getHeader()->getMethod() == st(HttpMethod)::Get) {
                HttpResponse response = createHttpResponse();
                HttpEntity entity = createHttpEntity();
                MyData data = createMyData();
                data->value1 = 100;
                data->value2 = createString("this is server");
                JsonValue value = createJsonValue();
                value->importFrom(data);
                
                entity->setContent(value->toString()->toByteArray());
                response->setEntity(entity);
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                w->write(response);
                latch->countDown();
              } else if(msg->getHeader()->getMethod() == st(HttpMethod)::Post) {
                String str = msg->getEntity()->getContent()->toString();
                //JsonValue value = createJsonValue();
                JsonReader reader = createJsonReader(str);
                auto value = reader->get();
                MyData data = createMyData();
                value->reflectTo(data);
                if(data->value1 != 100) {
                    TEST_FAIL("TestHttpServer SimpleClientConnect test1");
                }
                
                if(!data->value2->sameAs("this is server")) {
                    TEST_FAIL("TestHttpServer SimpleClientConnect test2");
                }
                latch->countDown();
                testResult = true;
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
  int port = getEnvPort();
  MyHttpListener listener = createMyHttpListener();
  HttpServer server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(port))
                    ->setListener(listener)
                    ->build();
  //printf("thread num is %d \n",st(Enviroment)::DefaultgHttpServerThreadsNum);
  server->start();
  MyHandler h = createMyHandler();
  h->sendEmptyMessageDelayed(0,10*1024);
  latch->await();
  server->close();
  
  if(testResult) {
    TEST_OK("TestHttpServer SimpleClientConnect test100");
  } else {
    TEST_FAIL("TestHttpServer SimpleClientConnect test2");
  }

  port++;
  setEnvPort(port);
  
}
