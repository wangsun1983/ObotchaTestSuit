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
                                    ->setTimeout(1000)
                                    ->newCachedThreadPool();
    while(1) {
        //start test 1
        int testNum = 1024*32;
        //int maxThreadNum = 0;
        for(int i = 0;i < testNum;i++) {
            MyRunTest5 run1 = createMyRunTest5();
            pool->execute(run1);
            usleep(1000);
        }
        sleep(1);
        int maxThreadNum = pool->getThreadsNum();
        if(maxThreadNum != 4) {
            pool->shutdown();
            printf("---[TestCachedPoolExecutor NumTest {case2,maxThreadNum is %d] [FAIL]--- \n",maxThreadNum);
            break;
        }
        pool->shutdown();
        sleep(5);

        //test6
        pool = createExecutorBuilder()->newCachedThreadPool();
        for(int i = 0;i < testNum;i++) {
            MyRunTest6 run2 = createMyRunTest6();
            pool->execute(run2);
        }

        sleep(16);
        int threadsize = pool->getThreadsNum();
        if(threadsize != 0) {
            printf("---[TestCachedPoolExecutor NumTest {case3] [FAIL]---,thread size is  %d \n",threadsize);
            break;
        }

        if(test6Num != testNum) {
            printf("---[TestCachedPoolExecutor NumTest {case4] [FAIL]---,thread size is  %d \n",threadsize);
            break;
        }
        pool->shutdown();

        printf("---[TestCachedPoolExecutor NumTest {case4] [Success]--- \n");
        break;
    }
}
