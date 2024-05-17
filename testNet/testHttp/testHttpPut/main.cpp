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
#include "HttpPut.hpp"
#include "HttpPut.hpp"
#include "HttpMultiPart.hpp"
#include "FileOutputStream.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"
#include "HttpPut.hpp"
#include "Md.hpp"

using namespace obotcha;

int main() {
  int port = getEnvPort();
  String url = String::New("http://127.0.0.1:")->append(String::New(port),"/test");
  HttpConnection c = HttpConnection::New(url);
  int ret = c->connect();
  
  HttpPut get = HttpPut::New(url);
  
  if(!get->getMethodName()->sameAs("PUT")) {
      TEST_FAIL("HttpPut test case1");
  }
  
  auto response = c->execute(get);
  
  if(response == nullptr) {
      TEST_FAIL("HttpPut test case2");
  }
  
  auto response_data = response->getEntity()->getContent()->toString();
  if(!response_data->sameAs("PUT")) {
      TEST_FAIL("HttpPut test case3");
  }
  
  TEST_OK("HttpPut test case100");
  port++;
  setEnvPort(port);
  return 0;

}
