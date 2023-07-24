#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderConnection.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConnectionParse() {
  while(1) {
    HttpHeaderConnection connection = createHttpHeaderConnection();
    connection->load(" keep-alive");
    if(!connection->get()->sameAs("keep-alive")) {
      TEST_FAIL("[HttpHeaderConnection test Parse case1]");
    }
    break;
  }

  while(1) {
    HttpHeaderConnection connection = createHttpHeaderConnection();
    connection->load("close");
    if(!connection->get()->sameAs("close")) {
      TEST_FAIL("[HttpHeaderConnection test Parse case2]");
    }
    break;
  }


  TEST_OK("[HttpHeaderConnection test Parse case100]");

}
