#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchUser.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    save->import("?1");
    if(!save->get()->equals("?1")) {
      printf("---[HttpHeaderSecFetchUser test Parse case1] [FAILED]--- \n");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    save->import("?0");
    if(!save->get()->equals("?0")) {
      printf("---[HttpHeaderSecFetchUser test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderSecFetchUser test Parse case100] [OK]--- \n");

}
