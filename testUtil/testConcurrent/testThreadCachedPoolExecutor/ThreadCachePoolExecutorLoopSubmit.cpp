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
#include "ThreadCachedPoolExecutor.hpp"
#include "AtomicNumber.hpp"
#include "ArrayList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

//AtomicInteger submitLoopValue1 = createAtomicInteger(0);
Mutex ttt = createMutex();
int vv = 0;
ArrayList<int> checksubmitList = createArrayList<int>(100001);

DECLARE_CLASS(SubmitLoopRun1) IMPLEMENTS(Runnable) {
public:
   void run() {
      ttt->lock();
      //submitLoopValue1->incrementAndGet();
      //TEST_FAIL("vv is %d ");
      checksubmitList->set(vv,1);
      vv++;
      ttt->unlock();
   }
};


int loopsubmittest() {
    while(1) {
        for(int i = 0; i < 100000;i++) {
          checksubmitList->add(0);
        }

        //ThreadCachedPoolExecutor pool = st(Executors)::newCachedThreadPool(100,0,20,1000);
        ThreadCachedPoolExecutor pool = createExecutorBuilder()
                                        ->setMaxPendingTaskNum(100)
                                        ->setMinThreadNum(0)
                                        ->setMaxThreadNum(20)
                                        ->setMaxNoWorkingTime(1000)
                                        ->newCachedThreadPool();
        for(int i = 0;i < 100000;i++) {
            //TEST_FAIL("trace 1,i is %d ",i);
            pool->submit(createSubmitLoopRun1());
        }
        sleep(10);
        pool->shutdown();
        //for(int i = 0; i < 100000;i++) {
        //  if(checksubmitList->get(i) != 1) {
        //    TEST_FAIL("value is %d,index is %d ",checksubmitList->get(i),i);
        //  }
        //}

        if(vv != 100000) {
          TEST_FAIL("[CacheThreadPool loopsumit case1],value is %d",vv);
        }

        TEST_OK("[CacheThreadPool loopsumit case100]");

        break;
    }

    return 0;
}
