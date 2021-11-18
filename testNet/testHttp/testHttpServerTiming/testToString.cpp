#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderServerTiming.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderServerTiming timing = createHttpHeaderServerTiming();
    timing->import("cache;desc=\"Cache Read\";dur=23.3,db;dur=53, app;dur=47.2");
    if(!timing->toString()->equals("cache;desc=\"Cache Read\";dur=23.3, db;dur=53, app;dur=47.2")) {
      printf("---[HttpHeaderServerTiming test toString case1] [FAILED]---,str is %s \n",timing->toString()->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderServerTiming test toString case100] [OK]--- \n");

}
