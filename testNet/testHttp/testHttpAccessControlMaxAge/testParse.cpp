#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAccessControlMaxAge.hpp"
#include "HttpMethod.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAccessControlMaxAge c = createHttpHeaderAccessControlMaxAge();
    c->import("600");
    if(c->get() != 600) {
      printf("---[HttpHeaderAccessControlMaxAge test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAccessControlMaxAge test Parse case100] [OK]--- \n");
}
