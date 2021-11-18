#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchMode.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->import("navigate");
    if(!save->get()->equals("navigate")) {
      printf("---[HttpHeaderSecFetchMode test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchMode save = createHttpHeaderSecFetchMode();
    save->import("nested-navigate");
    if(!save->get()->equals("nested-navigate")) {
      printf("---[HttpHeaderSecFetchMode test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecFetchMode test Parse case100] [OK]--- \n");

}
