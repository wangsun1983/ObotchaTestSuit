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

CountDownLatch latch = CountDownLatch::New(32);

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
            File file = File::New("./tmp/testdata");
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
  File file = File::New("./tmp/testdata");
  long prepareFilesize = file->length();
  signal(SIGPIPE,SIG_IGN);
  fprintf(stderr,"chunck server start!!!! \n");
  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<32*1024;i++) {
      FileOutputStream stream = FileOutputStream::New(file);
      stream->open(st(IO)::FileControlFlags::Append);
      String data = String::New("");
      for(int j = 0;j < 32;j++) {
        data = data->append(String::New(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }
  fprintf(stderr,"chunck server trace1!!!! \n");
  int port = getEnvPort();
  fprintf(stderr,"chunck server bind port %d\n",port);
  MyHttpListener listener = MyHttpListener::New();
  HttpServer server;
  while(1) {
    auto server1 = HttpServerBuilder::New()
                      ->setAddress(Inet4Address::New(port))
                      ->setListener(listener)
                      ->build();
    server = server1;
    if(server->start() == -1) {
      fprintf(stderr,"chunck server bind fail %d\n",port);
      port++;
      continue;
    }
    fprintf(stderr,"chunck server bind ok %d\n",port);
    setEnvPort(port);
    break;
  }
  fprintf(stderr,"chunck server trace2");
  latch->await();

  Md md5 = Md::New();
  String base = md5->encodeFile(File::New("./tmp/testdata"));

  File tmpDir = File::New("tmp");
  ArrayList<File> files = tmpDir->listFiles();
  auto iter = files->getIterator();
  while(iter->hasValue()) {
    auto f = iter->getValue();

    String v1 = md5->encodeFile(f);
    if(!base->equals(v1)) {
      TEST_FAIL("TestHttpServer testChunckFileServer test1 ,path is %s",f->getAbsolutePath()->toChars());
    }

    iter->next();
  }

  server->close();

  port++;
  setEnvPort(port);
  TEST_OK("TestHttpServer testChunckFileServer test100");

}
