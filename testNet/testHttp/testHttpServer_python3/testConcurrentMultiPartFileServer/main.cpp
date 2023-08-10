#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpPacketWriter.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "Md.hpp"
#include "ForEveryOne.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(16*32);
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

  void onHttpMessage(int event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
      switch(event) {
          case st(NetEvent)::Connect: {
              //TODO
              //TEST_FAIL("Connect !!!! \n");
          }
          break;

          case st(NetEvent)::Message: {
              //TEST_FAIL("i get a message \n");
              HttpEntity entity = msg->getEntity();
              HttpMultiPart multiPart = entity->getMultiPart();
              auto contents = multiPart->getContents();
//              if(contents != nullptr) {
//                contents->foreach([](Pair<String,String> pair){
//                  //TEST_FAIL("key is %s,value is %s \n",pair->getKey()->toChars(),pair->getValue()->toChars());
//                  return 1;
//                });
//              }

              auto files = multiPart->getFiles();
              if(files != nullptr) {
                  //files->foreach([](HttpMultiPartFile file){
                  ForEveryOne(file,files) {
                    File f = file->getFile();
                    //start md5 check
                    Md md5 = createMd();
                    String v1 = md5->encodeFile(createFile("data"));
                    String v2 = md5->encodeFile(createFile(f->getAbsolutePath()->toChars()));
                    if(v1 != v2) {
                      TEST_FAIL("TestHttpServer MultiPartFileServer test error,path is %s",f->getAbsolutePath()->toChars());
                    }
                  }
              }

              HttpResponse response = createHttpResponse();
              response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
              int len = w->write(response);
              latch->countDown();
          }
          break;

          case st(NetEvent)::Disconnect:{
              //disConnectCount->incrementAndGet();
              //TEST_FAIL("disconnect !!!! \n");
          }
          break;
      }
  }

};

int main() {
  //create testfile
  //prepare file
  File file = createFile("data");
  long prepareFilesize = file->length();

  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<128;i++) {
      FileOutputStream stream = createFileOutputStream(file);
      stream->open(st(OutputStream)::Append);
      String data = createString("");
      for(int j = 0;j < 512;j++) {
        data = data->append(createString(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }

  MyHandler h = createMyHandler();
  h->sendEmptyMessageDelayed(0,10*1024);

  int port = getEnvPort();

  MyHttpListener listener = createMyHttpListener();
  HttpServer server = createHttpServerBuilder()
                    ->setAddress(createInet4Address(port))
                    ->setListener(listener)
                    ->build();
  server->start();

  latch->await();

  server->close();

  //md5 sum
  File f = createFile("tmp");
  Md md5sum = createMd();

  String base = md5sum->encodeFile(createFile("data"));

  auto files = f->listFiles();
  auto iterator = files->getIterator();
  while(iterator->hasValue()) {
    File f1 = iterator->getValue();
    if(!md5sum->encodeFile(f1)->equals(base)) {
      TEST_FAIL("TestHttpServer MultiPartFileServer test1,file is %s \n",f1->getAbsolutePath()->toChars());
    }
    iterator->next();
  }

  port++;
  setEnvPort(port);

  TEST_OK("TestHttpServer MultiPartFileServer test100");
  
}
