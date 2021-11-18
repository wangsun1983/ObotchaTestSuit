#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderAcceptCh acceptCh = createHttpHeaderAcceptCh();
    acceptCh->import("DPR, Viewport-Width, Width");
    auto list = acceptCh->get();
    if(list->size() != 3) {
      printf("---[HttpHeaderAcceptCh test Parse case1] [FAILED]--- \n");
      break;
    }

    if(!list->get(0)->equals("DPR")) {
      printf("---[HttpHeaderAcceptCh test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!list->get(1)->equals("Viewport-Width")) {
      printf("---[HttpHeaderAcceptCh test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!list->get(2)->equals("Width")) {
      printf("---[HttpHeaderAcceptCh test Parse case4] [FAILED]--- \n");
      break;
    }
    break;
  }

  printf("---[HttpHeaderAcceptCh test Parse case100] [OK]--- \n");

}
