#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpPacketParser.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "Md.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(32);
long prepareFilesize = 0;

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
  void handleMessage(Message msg) {
    printf("connect is %d \n",latch->getCount());
    this->sendEmptyMessageDelayed(0,10*1024);
  }
};

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {

public:

  long filesize;
  _MyHttpListener() {
    filesize = prepareFilesize;
  }

  void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(Net)::Event::Connect: {
              //TODO
              //printf("Connect !!!! \n");
          }
          break;

          case st(Net)::Event::Message: {
              HttpEntity entity = msg->getEntity();
              HttpMultiPart multiPart = entity->getMultiPart();
              auto contents = multiPart->getContents();
//              if(multiPart != nullptr && contents != nullptr) {
//                contents->foreach([](Pair<String,String> pair){
//                  //printf("key is %s,value is %s \n",pair->getKey()->toChars(),pair->getValue()->toChars());
//                  return 1;
//                });
//              }

              auto files = multiPart->getFiles();
              if(multiPart != nullptr && files != nullptr) {
                  //files->foreach([](HttpMultiPartFile file){
                  ForEveryOne(file,files) {
                    File f = file->getFile();
                    //start md5 check
                    Md md5 = Md::New();
                    String v1 = md5->encodeFile(File::New("./tmp/testdata"));
                    String v2 = md5->encodeFile(File::New(f->getAbsolutePath()->toChars()));
                    if(v1 != v2) {
                      TEST_FAIL("TestHttpServer MultiPartFileServer test error,path is %s",f->getAbsolutePath()->toChars());
                    } 
                  }
              }

              HttpResponse response = HttpResponse::New();
              response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
              int len = w->write(response);
              latch->countDown();
          }
          break;

          case st(Net)::Event::Disconnect:{
              //disConnectCount->incrementAndGet();
              //printf("disconnect !!!! \n");
          }
          break;
      }
  }

};

int main() {
  //create testfile
  //prepare file
  File file = File::New("./tmp/testdata");
  long prepareFilesize = file->length();

  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<1024;i++) {
      FileOutputStream stream = FileOutputStream::New(file);
      stream->open(st(IO)::FileControlFlags::Append);
      String data = String::New("");
      for(int j = 0;j < 1024;j++) {
        data = data->append(String::New(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }

  MyHandler h = MyHandler::New();
  h->sendEmptyMessageDelayed(0,10*1024);

  int port = getEnvPort();
  printf("port is %d \n",port);

  MyHttpListener listener = MyHttpListener::New();
  HttpServer server = nullptr;
  while(1) {
    server = HttpServerBuilder::New()
                    ->setAddress(Inet4Address::New(port))
                    ->setListener(listener)
                    ->build();
    if(server->start() == -1) {
      port++;
      continue;
    }
    setEnvPort(port);
    break;
  }
  latch->await();

  server->close();

  port++;
  setEnvPort(port);

  TEST_OK("TestHttpServer MultiPartFileServer test100");
  
}
