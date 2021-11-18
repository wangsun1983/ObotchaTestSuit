#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServerTiming.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderServerTiming timing = createHttpHeaderServerTiming();
    timing->import("cache;desc=\"Cache Read\";dur=23.3,db;dur=53, app;dur=47.2");
    auto lists = timing->get();
    if(lists->size() != 3) {
      printf("---[HttpHeaderServerTiming test Parse case1] [FAILED]--- ,size is %d\n",lists->size());
      break;
    }

    HttpHeaderServerTimingItem item0 = lists->get(0);
    if(!item0->name->equals("cache")) {
      printf("---[HttpHeaderServerTiming test Parse case2] [FAILED]--- \n");
      break;
    }

    if(!item0->desc->equals("Cache Read")) {
      printf("---[HttpHeaderServerTiming test Parse case3] [FAILED]--- \n");
      break;
    }

    if(!item0->dur->equals("23.3")) {
      printf("---[HttpHeaderServerTiming test Parse case4] [FAILED]--- \n");
      break;
    }

    HttpHeaderServerTimingItem item1 = lists->get(1);
    if(!item1->name->equals("db")) {
      printf("---[HttpHeaderServerTiming test Parse case5] [FAILED]--- \n");
      break;
    }

    if(!item1->dur->equals("53")) {
      printf("---[HttpHeaderServerTiming test Parse case6] [FAILED]--- \n");
      break;
    }

    HttpHeaderServerTimingItem item2 = lists->get(2);
    if(!item2->name->equals("app")) {
      printf("---[HttpHeaderServerTiming test Parse case7] [FAILED]--- \n");
      break;
    }

    if(!item2->dur->equals("47.2")) {
      printf("---[HttpHeaderServerTiming test Parse case8] [FAILED]--- \n");
      break;
    }

    break;
  }

  printf("---[HttpHeaderServerTiming test Parse case100] [OK]--- \n");

}
