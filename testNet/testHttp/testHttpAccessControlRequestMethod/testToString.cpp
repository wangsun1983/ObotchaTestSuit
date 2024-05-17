#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlRequestMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlRequestMethod c = HttpHeaderAccessControlRequestMethod::New();
    c->load("POST");
    if(!c->toString()->sameAs("POST")) {
      TEST_FAIL("[HttpHeaderAccessControlRequestMethod test toString case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAccessControlRequestMethod test toString case100]");

}
