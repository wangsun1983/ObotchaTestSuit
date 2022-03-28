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

void testSubmitPriority() {
  TimeWatcher watch = createTimeWatcher();
  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(32)
              ->setThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Executor)::Medium,[]{
      usleep(100*1000);
    });
    usleep(10*1000);

    long task1time;
    long task2time;
    long task3time;
    pool->preempt(st(Executor)::Medium,[&task1time]{
      task1time = st(System)::currentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Executor)::High,[&task2time]{
      task2time = st(System)::currentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Executor)::High,[&task3time]{
      task3time = st(System)::currentTimeMillis();
      usleep(10*1000);
    });

    usleep(200*1000);
    if(task2time > task1time || (task1time - task2time) > 25 || (task1time - task2time) < 20) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitPriority Test case1]");
      break;
    }

    if(task2time > task3time || (task3time - task2time) > 15) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitPriority Test case2]");
      break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
              ->setQueueSize(32)
              ->setThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Executor)::Medium,[]{
      usleep(100*1000);
    });
    usleep(10*1000);

    long task1time;
    long task2time;
    long task3time;

    pool->preempt(st(Executor)::Low,[&task1time]{
      task1time = st(System)::currentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Executor)::Medium,[&task2time]{
      task2time = st(System)::currentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Executor)::High,[&task3time]{
      task3time = st(System)::currentTimeMillis();
      usleep(10*1000);
    });

    usleep(200*1000);
    if(task2time > task1time || (task1time - task2time) > 15 || (task1time - task2time) < 10) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitPriority Test case2]");
      break;
    }

    if(task3time > task2time || (task2time - task3time) > 15 || (task2time - task3time) < 10) {
      TEST_FAIL("[TestPriorityPoolExecutor SubmitPriority Test case3]");
      break;
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  TEST_OK("[TestPriorityPoolExecutor SubmitPriority Test case100]");

}
