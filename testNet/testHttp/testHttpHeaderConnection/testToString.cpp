#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderConnection.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConnectionToString() {
  while(1) {
    HttpHeaderConnection connection = createHttpHeaderConnection();
    connection->load(" keep-alive");
    if(!connection->toString()->sameAs("keep-alive")) {
      TEST_FAIL("[HttpHeaderConnection test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderConnection connection = createHttpHeaderConnection();
    connection->set(" keep-alive");
    if(!connection->toString()->sameAs("keep-alive")) {
      TEST_FAIL("[HttpHeaderConnection test toString case2]");
    }
    break;
  }

  TEST_OK("[HttpForwarded test toString case100]");

}
