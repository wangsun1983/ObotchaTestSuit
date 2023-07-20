#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlMaxAge.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlMaxAge c = createHttpHeaderAccessControlMaxAge();
    c->load("600");
    if(c->get() != 600) {
      TEST_FAIL("[HttpHeaderAccessControlMaxAge test Parse case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlMaxAge test Parse case100]");
}
