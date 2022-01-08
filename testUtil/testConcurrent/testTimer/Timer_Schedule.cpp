#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "Timer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testTimerSchedule() {
  TimeWatcher watch = createTimeWatcher();
  while(1) {
    Timer timer = createTimer();
    long now = st(System)::currentTimeMillis();
    long finish = 0;
    timer->schedule(100,[&finish]{
      finish = st(System)::currentTimeMillis();
    });

    usleep(150*1000);
    if(finish - now < 100 || finish - now > 105) {
      TEST_FAIL("[TestTimer Schedule Test case1]");
      break;
    }

    break;
  }

  while(1) {
    Timer timer = createTimer();
    long now = st(System)::currentTimeMillis();
    long finish = 0;
    timer->schedule(200,[&finish]{
      finish = st(System)::currentTimeMillis();
    });

    usleep(250*1000);
    if(finish - now < 200 || finish - now > 205) {
      TEST_FAIL("[TestTimer Schedule Test case2]");
      break;
    }

    break;
  }

  TEST_OK("[TestTimer Schedule Test case100]");

}
