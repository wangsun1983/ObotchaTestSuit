#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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
#include "Md.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;


CountDownLatch latch = CountDownLatch::New(128*16);

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener) {


void onHttpMessage(st(Net)::Event event,HttpLinker client,HttpResponseWriter w,HttpPacket msg){
    switch(event) {
        case st(Net)::Event::Connect: {
            //connectCount->incrementAndGet();
        }
        break;

        case st(Net)::Event::Message: {
            //messageCount->incrementAndGet();
            HttpResponse response = HttpResponse::New();
            response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
            File file = File::New("data");
            response->getEntity()->setChunk(file);
            w->write(response);
            latch->countDown();
        }
        break;

        case st(Net)::Event::Disconnect:{
            //disConnectCount->incrementAndGet();
        }
        break;
    }
}

};

int main() {
  File file = File::New("data");
  long prepareFilesize = file->length();
  signal(SIGPIPE,SIG_IGN);
  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<1;i++) {
      FileOutputStream stream = FileOutputStream::New(file);
      stream->open(st(IO)::FileControlFlags::Append);
      String data = String::New("");
      for(int j = 0;j < 1;j++) {
        data = data->append(String::New(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }
  int port = getEnvPort();
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
  sleep(5);

  Md md5 = Md::New();
  String base = md5->encodeFile(File::New("data"));

  File tmpDir = File::New("./tmp");
  ArrayList<File> files = tmpDir->listFiles();
  if(files->size() != 128 *16) {
    TEST_FAIL("TestHttpServer testConcurrentChunckFileServer test1,download file num is %d",files->size());
  }

  auto iter = files->getIterator();
  while(iter->hasValue()) {
    auto f = iter->getValue();

    String v1 = md5->encodeFile(f);
    if(!base->equals(v1)) {
      TEST_FAIL("TestHttpServer testConcurrentChunckFileServer test1,path is %s",f->getAbsolutePath()->toChars());
    }

    iter->next();
  }

  TEST_OK("TestHttpServer testConcurrentChunckFileServer test100");

  port++;
  setEnvPort(port);
  return 0;
}
