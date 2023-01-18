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
#include "TestLog.hpp"

using namespace obotcha;

void testPendingTask() {
  while(1) {
    auto pool = createExecutorBuilder()
              ->setDefaultThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Executor)::Low,[]{
        usleep(1000*50);
    });
    
    pool->preempt(st(Executor)::High,[]{
        usleep(1000*50);
    });
    
    usleep(1000*10);
    if(pool->getPendingTaskNum() != 1) {
        TEST_FAIL("[TestPriorityPoolExecutor PendingTask Test case1],num is %d",pool->getPendingTaskNum());  
    }
    
    usleep(1000*100);
    
    if(pool->getPendingTaskNum() != 0) {
        TEST_FAIL("[TestPriorityPoolExecutor PendingTask Test case2]");  
    }
    
    break;
  }
  
  TEST_OK("[TestPriorityPoolExecutor PendingTask Test case100]");

}
