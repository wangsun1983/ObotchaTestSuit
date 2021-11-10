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

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlRequestMethod c = createHttpHeaderAccessControlRequestMethod();
    c->import("POST");
    if(c->get() != st(HttpMethod)::Post){
      printf("---[HttpHeaderAccessControlRequestMethod test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlRequestMethod test Parse case100] [OK]--- \n");

}
