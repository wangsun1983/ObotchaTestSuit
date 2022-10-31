#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ExecutorBuilder.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Math.hpp"
#include "ExecutorResult.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPriorityPoolExecutor_Cancel() {

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newPriorityThreadPool();

      int value = 100;
      Future f1 = pool->preempt(st(Executor)::High,[&value](){
        usleep(200*1000);
        value = 222;
        st(ExecutorResult)::set(333);
      });

      Future f2 = pool->preempt(st(Executor)::High,[](){
        st(ExecutorResult)::set(100);
      });

      usleep(100*1000);
      f1->cancel();
      f2->cancel();
      usleep(150*1000);
      if(value != 222) {
        TEST_FAIL("[Future PriorityPoolExecutor Cancel case2");
      }

      bool isException = false;
      try {
        int v = f2->getResult<int>();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("[Future PriorityPoolExecutor Cancel case3");
      }
      pool->shutdown();
      pool->awaitTermination();
      break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newPriorityThreadPool();

    int value = 123;
    Future f1 = pool->preempt(st(Executor)::High,[&value](){
      value = 222;
      st(ExecutorResult)::set(333);
    });
    usleep(100*1000);
    f1->cancel();

    if(value != 222) {
      TEST_FAIL("[Future PriorityPoolExecutor Cancel case4");
    }

    if(f1->getResult<int>() != 333) {
      TEST_FAIL("[Future PriorityPoolExecutor Cancel case5");
    }
    pool->shutdown();
    pool->awaitTermination();
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(1)
                ->newPriorityThreadPool();
    pool->preempt(st(Executor)::High,[]{
      usleep(100*1000);
    });

    ArrayList<Future> lists = createArrayList<Future>();
    for(int i = 0;i < 1024;i++) {
      Future f = pool->preempt(st(Executor)::High,[] {

      });
      lists->add(f);
    }

    pool->shutdown();
    pool->awaitTermination();

    auto iterator = lists->getIterator();
    while(iterator->hasValue()) {
      auto f = iterator->getValue();
      if(f->getStatus() != st(ExecutorTask)::Cancel) {
        TEST_FAIL("[Future PriorityPoolExecutor Cancel case6");
        break;
      }
      iterator->next();
    }
    break;
  }

  while(1) {
    auto pool = createExecutorBuilder()
                ->setDefaultThreadNum(12)
                ->newPriorityThreadPool();
    pool->preempt(st(Executor)::High,[]{
      usleep(100*1000);
    });

    ArrayList<Future> lists = createArrayList<Future>();
    for(int i = 0;i < 1024*32;i++) {
      Future f = pool->preempt(st(Executor)::High,[] {
        usleep(1*1000);
      });
      lists->add(f);
    }

    Thread t = createThread([&lists] {
      auto iterator = lists->getIterator();
      while(iterator->hasValue()) {
        auto f = iterator->getValue();
        f->cancel();
        iterator->next();
      }
    });
    t->start();
    t->join();

    pool->shutdown();
    pool->awaitTermination();

    int count = 0;
    auto iterator = lists->getIterator();
    while(iterator->hasValue()) {
      auto f = iterator->getValue();
      if(f->getStatus() == st(ExecutorTask)::Cancel) {
        count++;
      }
      iterator->next();
    }

    TEST_OK("[Future PriorityPoolExecutor Cancel case7");
    break;
  }

  TEST_OK("[Future PriorityPoolExecutor Cancel case100");
}
