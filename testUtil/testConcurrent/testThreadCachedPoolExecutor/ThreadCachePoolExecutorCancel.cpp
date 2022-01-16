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
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

Mutex cancelmutex = createMutex();
int cancelNum = 0;

DECLARE_CLASS(CancelRunnable) IMPLEMENTS(Runnable) {
public:
   void run() {
      try{
        st(Thread)::msleep(5000);
      }catch(InterruptedException e){}
   }

   void onInterrupt() {
     AutoLock l(cancelmutex);
     cancelNum++;
   }
};


int cancelTest() {
    while(1) {
        //TEST_FAIL("start test ");
        //ThreadCachedPoolExecutor pool = st(Executors)::newCachedThreadPool(1024*32,0,20,1000);
        ThreadCachedPoolExecutor pool = createExecutorBuilder()
                                        ->setQueueSize(1024*32)
                                        ->setMinThreadNum(0)
                                        ->setMaxThreadNum(20)
                                        ->setTimeout(1000)
                                        ->newCachedThreadPool();

        ArrayList<Future> cancellists = createArrayList<Future>();
        //TEST_FAIL("start trace ");
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        for(int i = 0;i < 1024*32;i++) {
         //   TEST_FAIL("submit task num is %d ",i);
            Future f = pool->submit(createCancelRunnable());
            cancellists->add(f);
        }

        for(int i = 0;i < 1024*32;i++) {
         //   TEST_FAIL("submit task num is %d ",i);
            Future f = cancellists->get(i);
            f->cancel();
        }

        sleep(5);
        if(cancelNum != 1024*32) {
            TEST_FAIL("[CacheThreadPool Test {cancel()} case1,cancelNum is %d]",cancelNum);
        }
        pool->shutdown();

        TEST_OK("[CacheThreadPool Test {cancel()}case2]");
        break;
    }

    while(1) {
        //TEST_FAIL("start test ");
        cancelNum = 0;
        //ThreadCachedPoolExecutor pool = st(Executors)::newCachedThreadPool(1024*32,0,20,1000);
        ThreadCachedPoolExecutor pool = createExecutorBuilder()
                                        ->setQueueSize(1024*32)
                                        ->setMinThreadNum(0)
                                        ->setMaxThreadNum(20)
                                        ->setTimeout(1000)
                                        ->newCachedThreadPool();

        ArrayList<Future> cancellists = createArrayList<Future>();
        //TEST_FAIL("start trace ");
        for(int i = 0;i < 1024*32;i++) {
         //   TEST_FAIL("submit task num is %d ",i);
            Future f = pool->submit(createCancelRunnable());
            cancellists->add(f);
        }
        pool->shutdown();
        sleep(5);

        if(cancelNum != 1024*32) {
            TEST_FAIL("[CacheThreadPool Test {cancel()} case3,cancelNum is %d]",cancelNum);
        }
        TEST_OK("[CacheThreadPool Test {cancel()}case4]");
        break;
    }

    return 0;
}
