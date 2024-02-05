#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadCachedPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ExecutorBuilder.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void CachedPoolSubmit_AwaitTermination() {
  TimeWatcher watch = createTimeWatcher();

  while(1) {
    auto pool = createExecutorBuilder()
              ->setMaxPendingTaskNum(1)
              ->setMaxThreadNum(3)
              ->setMaxNoWorkingTime(200)
              ->newCachedThreadPool();

    Future f1 = pool->submit([]{
      usleep(100*1000);
    });
    usleep(1000*50);
    pool->shutdown();
    watch->start();
    pool->awaitTermination();
    long result = watch->stop();
    if(result < 50 || result > 55) {
      TEST_FAIL("[TestCachedPoolExecutor AwaitTermination test1],result is %d",result);
      break;
    }
    break;
  }
  
  TEST_OK("[TestCachedPoolExecutor AwaitTermination test100] ");
}
