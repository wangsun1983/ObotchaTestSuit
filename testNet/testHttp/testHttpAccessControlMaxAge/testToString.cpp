#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlMaxAge.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlMaxAge c = createHttpHeaderAccessControlMaxAge();
    c->import("600");
    if(!c->toString()->equals("600")) {
      printf("---[HttpHeaderAccessControlMaxAge test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlMaxAge test toString case100] [OK]--- \n");

}
