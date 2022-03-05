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

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

bool isFirst = true;

CountDownLatch connectlatch = createCountDownLatch(1);
int step = 0;

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("connectlatch is %d \n",connectlatch->getCount());
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {
  void onHttpMessage(int event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(NetEvent)::Connect: {
              
          }
          break;

          case st(NetEvent)::Message: {
              if(isFirst) {
                HttpResponse response = createHttpResponse();
                HttpHeader header = createHttpHeader();
                //header->set(st(HttpHeader)::TransferEncoding,"chunked");
                //auto encoding = header->getTransferEncoding();
                //if(encoding == nullptr) {
                //  printf("encoding is nullptr \n");
                //}
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                response->setHeader(header);
                
                HttpEntity entity = createHttpEntity();

                String arg1 = createString("hello1hello2hello3");
                entity->setChunk(arg1->toByteArray());

                response->setEntity(entity);

                w->write(response);
                isFirst = false;
              } else {
                ByteArray arr = msg->getEntity()->getContent();
                if(arr->toString()->equals("failed")) {
                  TEST_FAIL("TestHttpServer_Go SimpleChunkContent test1")
                } else if(arr->toString()->equals("ok")) {
                  TEST_OK("TestHttpServer_Go SimpleChunkContent test2")
                  connectlatch->countDown();
                }
              }
          }
          break;

          case st(NetEvent)::Disconnect:{
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

  connectlatch->await();
  server->close();

  port++;
  setEnvPort(port);

  TEST_OK("TestHttpServer_Go SimpleChunkContent test100");

  return 0;
}
