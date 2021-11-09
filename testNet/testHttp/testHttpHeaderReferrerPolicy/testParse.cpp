#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderReferrerPolicy.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderReferrerPolicy match = createHttpHeaderReferrerPolicy();
    match->import("no-referrer, strict-origin-when-cross-origin");

    ArrayList<String> list = match->get();
    if(list->size() != 2) {
      printf("---[HttpHeaderReferrerPolicy test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(0)->equals("no-referrer") || !list->get(1)->equals("strict-origin-when-cross-origin")) {
      printf("---[HttpHeaderReferrerPolicy test Parse case2] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderReferrerPolicy test Parse case100] [OK]--- \n");
}
