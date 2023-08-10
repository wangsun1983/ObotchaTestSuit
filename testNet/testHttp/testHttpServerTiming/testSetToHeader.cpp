#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServerTiming.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Server-Timing"),
                createString("cache;desc=\"Cache Read\";dur=23.3,db;dur=53, app;dur=47.2"));
    
    auto timing = header->getServerTiming();
    
    auto lists = timing->get();
    if(lists->size() != 3) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case1],size is %d",lists->size());
      break;
    }

    HttpHeaderServerTimingItem item0 = lists->get(0);
    if(!item0->name->sameAs("cache")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case2]");
      break;
    }

    if(!item0->desc->sameAs("Cache Read")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case3]");
      break;
    }

    if(!item0->dur->sameAs("23.3")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case4]");
      break;
    }

    HttpHeaderServerTimingItem item1 = lists->get(1);
    if(!item1->name->sameAs("db")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case5]");
      break;
    }

    if(!item1->dur->sameAs("53")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case6]");
      break;
    }

    HttpHeaderServerTimingItem item2 = lists->get(2);
    if(!item2->name->sameAs("app")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case7]");
      break;
    }

    if(!item2->dur->sameAs("47.2")) {
      TEST_FAIL("[HttpHeaderServerTiming test setToHeader case8]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderServerTiming test setToHeader case100]");

}
