#include <stdio.h>
#include <unistd.h>
#include <atomic>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Long.hpp"
#include "TimeWatcher.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

std::atomic_int scheduleShutdownCount{0};

DECLARE_CLASS(ScheduleShutDownTask) IMPLEMENTS(Runnable){
public:
    void run() {
      usleep(1000 * 5000);
    }

    bool onInterrupt() {
      scheduleShutdownCount++;
      return true;
    }
};

void testShutdownCount() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxThreadNum(3)
              ->newScheduledThreadPool();

    for(int i = 0;i<32*1024;i++) {
      pool->submit(30000,createScheduleShutDownTask());
    }

    usleep(1000*100);

    pool->shutdown();
    pool->awaitTermination();

    if(scheduleShutdownCount != 32*1024) {
      int count = scheduleShutdownCount;
      TEST_FAIL("[ScheduledThreadPoolExecutor Shutdown case1],count is %d",count);
    }
    break;
  }

  TEST_OK("[ScheduledThreadPoolExecutor Shutdown case100]");
}
