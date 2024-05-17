#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAllow.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAllow c = HttpHeaderAllow::New();
    c->load("POST, GET, OPTIONS");
    auto list = c->get();
    if(list[0] != st(HttpMethod)::Id::Post) {
      TEST_FAIL("[HttpHeaderAllow test Parse case1]");
      break;
    }

    if(list[1] != st(HttpMethod)::Id::Get) {
      TEST_FAIL("[HttpHeaderAllow test Parse case2]");
      break;
    }

    if(list[2] != st(HttpMethod)::Id::Options) {
      TEST_FAIL("[HttpHeaderAllow test Parse case3]");
      break;
    }
    break;
  }


  TEST_OK("[HttpHeaderAllow test Parse case100]");

}
