#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlAllowMethods.hpp"
#include "HttpMethod.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlAllowMethods c = createHttpHeaderAccessControlAllowMethods();
    c->import("POST, GET, OPTIONS");
    auto list = c->getMethods();
    if(list->get(0)->toValue() != st(HttpMethod)::Post) {
      printf("---[HttpHeaderAccessControlAllowMethods test Parse case1] [FAILED]--- \n");
      break;
    }

    if(list->get(1)->toValue() != st(HttpMethod)::Get) {
      printf("---[HttpHeaderAccessControlAllowMethods test Parse case2] [FAILED]--- \n");
      break;
    }

    if(list->get(2)->toValue() != st(HttpMethod)::Options) {
      printf("---[HttpHeaderAccessControlAllowMethods test Parse case3] [FAILED]--- \n");
      break;
    }
    break;
  }


  printf("---[HttpHeaderAccessControlAllowMethods test Parse case100] [OK]--- \n");

}
