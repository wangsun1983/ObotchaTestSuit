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
  File file = createFile("./tmp/testdata");
  
  if(!file->exists()) {
    file->createNewFile();
    for(int i = 0;i<32*1024;i++) {
          FileOutputStream stream = createFileOutputStream(file);
          stream->open(st(IO)::FileControlFlags::Append);
          String data = createString("");
          for(int j = 0;j < 32;j++) {
            data = data->append(createString(st(System)::CurrentTimeMillis()));
          }
          stream->write(data->toByteArray());
          stream->close();
    }
  }
  
  int port = getEnvPort();
  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpConnection c = createHttpConnection(url);
  int ret = c->connect();
  
  HttpPost post = createHttpPost(url);
  HttpMultiPart part= createHttpMultiPart();
  part->addFile(file);
  post->getEntity()->setMultiPart(part);
  auto response = c->execute(post);
  
  if(response == nullptr) {
      TEST_FAIL("HttpConnection simple file multipart case1");
  }
  
  Md md = createMd();
  
  auto md1 = md->encodeFile(createFile("./tmp/getdata"));
  auto md2 = md->encodeFile(createFile("./tmp/testdata"));
  if(!md1->sameAs(md2)) {
      TEST_FAIL("HttpConnection simple file multipart case2,md1 is [%s],md2 is [%s]",md1->toChars(),md2->toChars());
  }
  TEST_OK("HttpConnection simple file multipart case100");
  port++;
  setEnvPort(port);
  return 0;

}
