#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadCachedPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int num = 0;
Mutex mutex;

int test6Num = 0;

DECLARE_CLASS(MyRunTest5) IMPLEMENTS(Runnable) {
public:
   void run() {
      {
          sleep(1);
          AutoLock l(mutex);
          num++;
      }
   }
};

DECLARE_CLASS(MyRunTest6) IMPLEMENTS(Runnable) {
public:
   void run() {
      {
          AutoLock l(mutex);
          test6Num++;
      }
   }
};


int numTest() {
    mutex = createMutex();
    ThreadCachedPoolExecutor pool = createExecutorBuilder()
                                    ->setMaxThreadNum(4)
                                    ->setCacheTimeout(1000)
                                    ->newCachedThreadPool();
    while(1) {
        //start test 1
        int testNum = 1024*32;
        //int maxThreadNum = 0;
        for(int i = 0;i < testNum;i++) {
            MyRunTest5 run1 = createMyRunTest5();
            pool->submit(run1);
            usleep(1000);
        }
        sleep(1);
        int maxThreadNum = pool->getThreadsNum();
        if(maxThreadNum != 4) {
            pool->shutdown();
            TEST_FAIL("[TestCachedPoolExecutor NumTest {case2,maxThreadNum is %d]",maxThreadNum);
            break;
        }
        pool->shutdown();
        sleep(5);

        //test6
        pool = createExecutorBuilder()->newCachedThreadPool();
        for(int i = 0;i < testNum;i++) {
            MyRunTest6 run2 = createMyRunTest6();
            pool->submit(run2);
        }
        sleep(16);
        int threadsize = pool->getThreadsNum();
        if(threadsize != 0) {
            TEST_FAIL("[TestCachedPoolExecutor NumTest {case3],thread size is  %d ",threadsize);
            break;
        }
        if(test6Num != testNum) {
            TEST_FAIL("[TestCachedPoolExecutor NumTest {case4],thread size is  %d ",threadsize);
            break;
        }
        pool->shutdown();
        TEST_OK("[TestCachedPoolExecutor NumTest {case4]");
        break;
    }

    return 0;
}
