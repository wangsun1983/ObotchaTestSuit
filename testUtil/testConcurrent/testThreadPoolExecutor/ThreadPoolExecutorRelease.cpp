#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ThreadPoolExecutor.hpp"
#include "ExecutorBuilder.hpp"
#include "TestLog.hpp"

using namespace obotcha;

Mutex numMutex = createMutex();
int releaseCount;

DECLARE_CLASS(ReleaseunTest1) IMPLEMENTS(Runnable) {
public:
    _ReleaseunTest1() {
        //TEST_FAIL("create this is %lx ",this);
    }

    void run() {
        sleep(1);
    }

    ~_ReleaseunTest1() {
        //decDebugReferenctCount();
        //TEST_FAIL("numMutex1 count is %d,this is %lx ",numMutex->getStrongCount(),this);
        //{
        AutoLock ll(numMutex);
            //TEST_FAIL("numMutex2 count is %d ",numMutex->getStrongCount());
        releaseCount++;
        //}
        //TEST_FAIL("numMutex2 count is %d,this is %lx ",numMutex->getStrongCount(),this);

    }

};


void releaseTest() {
    while(1) {
        {
            ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(50)->setThreadNum(8)->newThreadPool();//st(Executors)::newFixedThreadPool(50,8);
            for(int i = 0;i<50;i++) {
                pool->submit(createReleaseunTest1());
            }

            pool->shutdown();
            sleep(10);
            if(pool->getThreadsNum() != 8) {
                TEST_FAIL("[TestThreadPoolExecutor Test {release()},thread num is %d case2]",pool->getThreadsNum());
                break;
            }

            if(releaseCount != 50) {
                TEST_FAIL("[TestThreadPoolExecutor Test {release()},count is %d case3]",releaseCount);
                break;
            }

            TEST_OK("[TestThreadPoolExecutor Test {release()}, case4]");
            break;
        }

        sleep(1);
        TEST_OK("[TestThreadPoolExecutor Test {release()} case5]");
        break;
    }

    sleep(1);

}
