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
  int port = getEnvPort();
  String url = String::New("http://127.0.0.1:")->append(String::New(port),"/test");
  HttpConnection c = HttpConnection::New(url);
  int ret = c->connect();
  
  HttpPost post = HttpPost::New(url);
  HttpMultiPart part= HttpMultiPart::New();
  part->addContent(String::New("value_1"),String::New("this is value1,abc"));
  part->addContent(String::New("value_2"),String::New("this is value2,efg"));
  post->getEntity()->setMultiPart(part);
  auto response = c->execute(post);
  
  if(response == nullptr) {
      TEST_FAIL("HttpConnection simple multipart case1");
  }
  
  auto response_data = response->getEntity()->getContent()->toString();
  if(!response_data->sameAs("this is value1,abc;this is value2,efg")) {
      TEST_FAIL("HttpConnection simple multipart case2");
  }
  
  TEST_OK("HttpConnection simple multipart case100");
  port++;
  setEnvPort(port);
  return 0;

}
