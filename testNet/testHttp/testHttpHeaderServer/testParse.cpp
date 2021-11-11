#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServer.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderServer match = createHttpHeaderServer();
    match->import("Apache/2.4.1 (Unix)");
    if(!match->get()->equals("Apache/2.4.1 (Unix)")) {
        printf("---[HttpHeaderServer test Parse case2] [FAILED]--- \n");
    }
    break;
  }

  printf("---[HttpHeaderServer test Parse case100] [OK]--- \n");
}
