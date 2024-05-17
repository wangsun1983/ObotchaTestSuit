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
  TimeWatcher watch = TimeWatcher::New();
  while(1) {
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(32)
              ->setDefaultThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Concurrent)::TaskPriority::Medium,[]{
      usleep(100*1000);
    });
    usleep(10*1000);

    long task1time;
    long task2time;
    long task3time;
    pool->preempt(st(Concurrent)::TaskPriority::Medium,[&task1time]{
      task1time = st(System)::CurrentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Concurrent)::TaskPriority::High,[&task2time]{
      task2time = st(System)::CurrentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Concurrent)::TaskPriority::High,[&task3time]{
      task3time = st(System)::CurrentTimeMillis();
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
    auto pool = ExecutorBuilder::New()
              ->setMaxPendingTaskNum(32)
              ->setDefaultThreadNum(1)
              ->newPriorityThreadPool();

    pool->preempt(st(Concurrent)::TaskPriority::Medium,[]{
      usleep(100*1000);
    });
    usleep(10*1000);

    long task1time;
    long task2time;
    long task3time;

    pool->preempt(st(Concurrent)::TaskPriority::Low,[&task1time]{
      task1time = st(System)::CurrentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Concurrent)::TaskPriority::Medium,[&task2time]{
      task2time = st(System)::CurrentTimeMillis();
      usleep(10*1000);
    });

    pool->preempt(st(Concurrent)::TaskPriority::High,[&task3time]{
      task3time = st(System)::CurrentTimeMillis();
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
