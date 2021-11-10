#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlRequestMethod.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlRequestMethod c = createHttpHeaderAccessControlRequestMethod();
    c->import("POST");
    if(!c->toString()->equals("POST")) {
      printf("---[HttpHeaderAccessControlRequestMethod test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlRequestMethod test toString case100] [OK]--- \n");

}
