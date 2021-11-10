#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAllow.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAllow c = createHttpHeaderAllow();
    c->import("POST, GET, OPTIONS");
    if(!c->toString()->equals("POST, GET, OPTIONS")) {
      printf("---[HttpHeaderAllow test toString case1] [FAILED]--- ,str is %s\n",c->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderAllow test toString case100] [OK]--- \n");

}
