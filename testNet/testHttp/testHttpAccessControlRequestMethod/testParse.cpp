#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlRequestMethod.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlRequestMethod c = createHttpHeaderAccessControlRequestMethod();
    c->load("POST");
    if(c->get() != st(HttpMethod)::Post){
      TEST_FAIL("[HttpHeaderAccessControlRequestMethod test Parse case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestMethod test Parse case100]");

}
