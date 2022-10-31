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

void testThreadPoolExecutor_GetResult_Error() {
  auto pool = createExecutorBuilder()
              ->setDefaultThreadNum(1)
              ->newThreadPool();
  while(1) {
      int value = 100;
      Future f1 = pool->submit([&value](){
        usleep(200*1000);
        value = 222;
        st(ExecutorResult)::set(333);
      });

      bool isException = false;
      try {
        f1->getResult<bool>();
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult Error case1");
        break;
      }
      break;
  }

  while(1) {
      int value = 100;
      Future f1 = pool->submit([&value](){
        usleep(200*1000);
        value = 222;
        st(ExecutorResult)::set(createInteger(100));
      });

      int result = f1->getResult<int>();

      if(result != 100 || value != 222) {
        TEST_FAIL("[Future ThreadPoolExecutor GetResult Error case2");
        break;
      }
      break;
  }

  pool->shutdown();
  pool->awaitTermination();

  TEST_OK("[Future ThreadPoolExecutor GetResult Error case100");
}
