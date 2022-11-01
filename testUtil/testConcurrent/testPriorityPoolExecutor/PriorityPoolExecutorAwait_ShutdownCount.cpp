#include <stdio.h>
#include <unistd.h>
#include <atomic>

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
#include "TestLog.hpp"

using namespace obotcha;

std::atomic_int priorityInterruptCount{0};

DECLARE_CLASS(PriorityCancelTask) IMPLEMENTS(Runnable){
public:
    void run() {
      usleep(1000*500);
    }

    bool onInterrupt() {
      priorityInterruptCount++;
      return false;
    }
};

void testShutdownCount() {
  TimeWatcher watch = createTimeWatcher();
  while(1) {
    auto pool = createExecutorBuilder()
              ->setDefaultThreadNum(1)
              ->newPriorityThreadPool();

    for(int i = 0;i<32*1024;i++) {
      pool->submit(createPriorityCancelTask());
    }

    usleep(1000*100);
    pool->shutdown();
    pool->awaitTermination();

    if(priorityInterruptCount != 32*1024) {
      int value = priorityInterruptCount;
      TEST_FAIL("[TestPriorityPoolExecutor Shutdown Test case1],value is %d",value);
    }
    break;
  }

  TEST_OK("[TestPriorityPoolExecutor Shutdown Test case100]");

}
