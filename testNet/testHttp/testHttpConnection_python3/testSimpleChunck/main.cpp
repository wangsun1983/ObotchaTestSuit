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
#include "HttpConnection.hpp"
#include "HttpGet.hpp"
#include "HttpPost.hpp"
#include "HttpMultiPart.hpp"
#include "FileOutputStream.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"
#include "Md.hpp"

using namespace obotcha;

int main() {
  File file = File::New("./tmp/testdata");
  
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
  
  int port = getEnvPort();
  String url = String::New("http://127.0.0.1:")->append(String::New(port),"/test");
  HttpConnection c = HttpConnection::New(url);
  int ret = c->connect();
  
  HttpGet get = HttpGet(url);
  auto response = c->execute(get);
  
  auto chunk = response->getEntity()->getChunk()->getData();
  if(!chunk->toString()->sameAs("11111111112222222222333333333344444444445555555555")) {
      TEST_FAIL("HttpConnection simple chunck case1");
  }
  TEST_OK("HttpConnection simple chunck case100");
  
  port++;
  setEnvPort(port);
  return 0;

}
