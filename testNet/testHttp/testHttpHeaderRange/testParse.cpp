#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderRange.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderRange range = createHttpHeaderRange();
    range->import("bytes=200-1000, 2000-6576, 19000-");
    if(!range->getUnit()->equals("bytes")) {
      printf("---[HttpHeaderRange test Parse case1] [FAILED]--- \n");
      break;
    }

    auto list = range->getRanges();
    if(list->size() != 3) {
      printf("---[HttpHeaderRange test Parse case2] [FAILED]--- \n");
      break;
    }

    auto item0 = list->get(0);
    if(item0->start != 200) {
      printf("---[HttpHeaderRange test Parse case3] [FAILED]---,item0->start is %d\n",item0->start);
      break;
    }

    if(item0->end != 1000) {
      printf("---[HttpHeaderRange test Parse case4] [FAILED]--- \n");
      break;
    }

    auto item1 = list->get(1);
    if(item1->start != 2000) {
      printf("---[HttpHeaderRange test Parse case5] [FAILED]--- \n");
      break;
    }

    if(item1->end != 6576) {
      printf("---[HttpHeaderRange test Parse case6] [FAILED]--- \n");
      break;
    }

    auto item2 = list->get(2);
    if(item2->start != 19000) {
      printf("---[HttpHeaderRange test Parse case7] [FAILED]--- \n");
      break;
    }

    if(item2->end != -1) {
      printf("---[HttpHeaderRange test Parse case8] [FAILED]--- \n");
      break;
    }

    break;
  }

  printf("---[HttpHeaderRange test Parse case100] [OK]--- \n");

}
