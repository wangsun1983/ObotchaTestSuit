#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServerTiming.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderServerTiming timing = createHttpHeaderServerTiming();
    timing->load("cache;desc=\"Cache Read\";dur=23.3,db;dur=53, app;dur=47.2");
    auto lists = timing->get();
    if(lists->size() != 3) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case1],size is %d",lists->size());
      break;
    }

    HttpHeaderServerTimingItem item0 = lists->get(0);
    if(!item0->name->equals("cache")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case2]");
      break;
    }

    if(!item0->desc->equals("Cache Read")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case3]");
      break;
    }

    if(!item0->dur->equals("23.3")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case4]");
      break;
    }

    HttpHeaderServerTimingItem item1 = lists->get(1);
    if(!item1->name->equals("db")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case5]");
      break;
    }

    if(!item1->dur->equals("53")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case6]");
      break;
    }

    HttpHeaderServerTimingItem item2 = lists->get(2);
    if(!item2->name->equals("app")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case7]");
      break;
    }

    if(!item2->dur->equals("47.2")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case8]");
      break;
    }

    break;
  }
  
  while(1) {
    HttpHeaderServerTiming timing = createHttpHeaderServerTiming("cache;desc=\"Cache Read\";dur=23.3,db;dur=53, app;dur=47.2");
    auto lists = timing->get();
    if(lists->size() != 3) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case9],size is %d",lists->size());
      break;
    }

    HttpHeaderServerTimingItem item0 = lists->get(0);
    if(!item0->name->equals("cache")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case10]");
      break;
    }

    if(!item0->desc->equals("Cache Read")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case11]");
      break;
    }

    if(!item0->dur->equals("23.3")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case12]");
      break;
    }

    HttpHeaderServerTimingItem item1 = lists->get(1);
    if(!item1->name->equals("db")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case13]");
      break;
    }

    if(!item1->dur->equals("53")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case14]");
      break;
    }

    HttpHeaderServerTimingItem item2 = lists->get(2);
    if(!item2->name->equals("app")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case15]");
      break;
    }

    if(!item2->dur->equals("47.2")) {
      TEST_FAIL("[HttpHeaderServerTiming test Parse case16]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderServerTiming test Parse case100]");

}
