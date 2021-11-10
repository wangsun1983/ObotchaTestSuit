#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAge.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAge c = createHttpHeaderAge();
    c->import("600");
    if(!c->toString()->equals("600")) {
      printf("---[HttpHeaderAge test toString case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAge test toString case100] [OK]--- \n");

}
