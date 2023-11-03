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
#include "Http2Server.hpp"
#include "NetEvent.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "Net.hpp"

using namespace obotcha;

// curl -v --http2 http://127.0.0.1:1234/aaa

// curl -v -d '12345abc' --http2 http://127.0.0.1:1234/aaa

//    curl -v -d '{"aps":{"alert":"Test Push","sound":"default"}}' \
    --cert /path/to/cert/cert.pem:SECURE_PASSWORD \
    -H "apns-topic: com.app.identifier" --http2 \
    https://api.development.push.apple.com/3/device/DEVICE_ID

int count = 0;
String respStr;
CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(Http2Listener) {
  void onHttpMessage(st(Net)::Event event,HttpLinker client,Http2ResponseWriter w,Http2Packet msg){
    
      switch(event) {
          case st(Net)::Event::Connect: {
              
          }
          break;

          case st(Net)::Event::Message: {
              printf("i get a message \n");
                HttpResponse response = createHttpResponse();
                response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                HttpChunk chunk = createHttpChunk(createFile("./tmp/testdata"));
                response->getEntity()->setChunk(chunk);
                w->write(response);
                latch->countDown();
          }
          break;

          case st(Net)::Event::Disconnect:{
          }
          break;
      }
      
  }
};

int main() {
    File file = createFile("./tmp/testdata");
    long prepareFilesize = file->length();

    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Append);
        String data = createString("");
        for(int j = 0;j < 256;j++) {
          data = data->append(createString(st(System)::CurrentTimeMillis()));
        }
        stream->write(data->toByteArray());
        stream->close();
      }
    }

  int port = getEnvPort();
  MyHttpListener listener = createMyHttpListener();
  Http2Server server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(8080))
                    ->setHttp2Listener(listener)
                    ->buildHttp2Server();
  server->start();
  latch->await();
  while(1) {
    usleep(1000*5000);
  }
  server->close();
  port++;
  setEnvPort(port);
  TEST_OK("TestHttp2Server SimpleConnect case100");

  return 0;
}
