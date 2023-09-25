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
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPriorityPoolExecutor_Multithread() {
  while(1) {
    auto pool = createExecutorBuilder()
              ->setDefaultThreadNum(32)
              ->newPriorityThreadPool();

    CountDownLatch latch = createCountDownLatch(32*1024);
    ArrayList<Future> lists = createArrayList<Future>();
    for(int i = 0;i<32*1024;i++) {
      Future t = pool->preempt(st(Concurrent)::TaskPriority::High,[&latch,i]{
        st(ExecutorResult)::Set(i);
        latch->countDown();
      });
      lists->add(t);
    }

    latch->await();
    auto iterator = lists->getIterator();
    int sum = 0;
    while(iterator->hasValue()) {
      sum += iterator->getValue()->getResult<int>();
      iterator->next();
    }

    int expectSum = 0;
    for(int i = 0;i <32*1024;i++) {
      expectSum += i;
    }

    if(sum != expectSum) {
      TEST_FAIL("[Future PriorityPoolExecutor Multithread case1");
    }

    pool->shutdown();
    pool->awaitTermination();
    break;
  }
  TEST_OK("[Future PriorityPoolExecutor Multithread case100");
}
