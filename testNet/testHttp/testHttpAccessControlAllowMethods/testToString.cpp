#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAccessControlAllowMethods.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAccessControlAllowMethods c = createHttpHeaderAccessControlAllowMethods();
    c->import("POST, GET, OPTIONS");
    if(!c->toString()->equals("POST, GET, OPTIONS")) {
      printf("---[HttpHeaderAccessControlAllowMethods test toString case1] [FAILED]--- ,str is %s\n",c->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlAllowMethods test toString case100] [OK]--- \n");

}
