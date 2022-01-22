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

using namespace obotcha;

std::atomic_int count{0};

DECLARE_CLASS(ReleaseTestRunnable) IMPLEMENTS(Runnable) {
public:
   void run() {
      sleep(1);
      count++;
      //int v = count;
      //printf("count is %d \n",v);
   }
};

int releaseTest() {
    while(1) {
        //ThreadCachedPoolExecutor pool = st(Executors)::newCachedThreadPool(100,0,20,1000);
        ThreadCachedPoolExecutor pool = createExecutorBuilder()
                                        ->setQueueSize(100)
                                        ->setMinThreadNum(0)
                                        ->setMaxThreadNum(20)
                                        ->setTimeout(1000)
                                        ->newCachedThreadPool();
        for(int i = 0;i < 100;i++) {
            pool->submit(createReleaseTestRunnable());
        }
        sleep(10);
        pool->shutdown();
        pool->awaitTermination();
        break;
    }
    TEST_OK("[CacheThreadPool Test {release()}case4]");
    return 0;
}
