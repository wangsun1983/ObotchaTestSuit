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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAllow c = createHttpHeaderAllow();
    c->import("POST, GET, OPTIONS");
    auto list = c->get();
    if(list->get(0)->toValue() != st(HttpMethod)::Post) {
      printf("---[HttpHeaderAllow test Parse case1] [FAILED]--- \n");
      break;
    }

    if(list->get(1)->toValue() != st(HttpMethod)::Get) {
      printf("---[HttpHeaderAllow test Parse case2] [FAILED]--- \n");
      break;
    }

    if(list->get(2)->toValue() != st(HttpMethod)::Options) {
      printf("---[HttpHeaderAllow test Parse case3] [FAILED]--- \n");
      break;
    }
    break;
  }


  printf("---[HttpHeaderAllow test Parse case100] [OK]--- \n");

}
