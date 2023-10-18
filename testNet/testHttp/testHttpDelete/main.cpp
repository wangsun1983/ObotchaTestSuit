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
#include "HttpDelete.hpp"
#include "HttpDelete.hpp"
#include "HttpMultiPart.hpp"
#include "FileOutputStream.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"
#include "HttpDelete.hpp"
#include "Md.hpp"

using namespace obotcha;

int main() {
  int port = getEnvPort();
  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpConnection c = createHttpConnection(url);
  int ret = c->connect();
  
  HttpDelete get = createHttpDelete(url);
  
  if(!get->getMethodName()->sameAs("DELETE")) {
      TEST_FAIL("HttpDelete test case1");
  }
  
  auto response = c->execute(get);
  
  if(response == nullptr) {
      TEST_FAIL("HttpDelete test case2");
  }
  
  auto response_data = response->getEntity()->getContent()->toString();
  if(!response_data->sameAs("DELETE")) {
      TEST_FAIL("HttpDelete test case3");
  }
  
  TEST_OK("HttpDelete test case100");
  port++;
  setEnvPort(port);
  return 0;

}
