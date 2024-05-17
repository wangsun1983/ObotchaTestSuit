#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServerTiming.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderServerTiming timing = HttpHeaderServerTiming::New();
    timing->load("cache;desc=\"Cache Read\";dur=23.3,db;dur=53, app;dur=47.2");
    if(!timing->toString()->sameAs("cache;desc=\"Cache Read\";dur=23.3, db;dur=53, app;dur=47.2")) {
      TEST_FAIL("[HttpHeaderServerTiming test toString case1],str is %s \n",timing->toString()->toChars());
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderServerTiming timing = HttpHeaderServerTiming::New();
    timing->add(String::New("cache"),
                String::New("23.3"),
                String::New("Cache Read"));
                
    timing->add(String::New("db"),
                String::New("53"),
                nullptr);
                
    timing->add(String::New("app"),
                String::New("47.2"),
                nullptr);
                
    if(!timing->toString()->sameAs("cache;desc=\"Cache Read\";dur=23.3, db;dur=53, app;dur=47.2")) {
        TEST_FAIL("[HttpHeaderServerTiming test toString case2],str is %s \n",timing->toString()->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderServerTiming test toString case100]");

}
