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

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
  int port = getEnvPort();
  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpConnection c = createHttpConnection(url);
  int ret = c->connect();
  printf("ret is %d \n",ret);
  
  HttpGet httpget = createHttpGet(url);
  httpget->getEntity()->setContent(createString("hello")->toByteArray());
  auto response = c->execute(httpget);
  auto response_data = response->getEntity()->getContent()->toString();
  if(!response_data->sameAs("hello")) {
	TEST_FAIL("HttpConnection simple connect case1");
  }
  TEST_OK("HttpConnection simple connect case100");
  port++;
  setEnvPort(port);
  return 0;

}