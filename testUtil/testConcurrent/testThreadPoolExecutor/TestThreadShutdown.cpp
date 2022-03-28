#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "ThreadPoolExecutor.hpp"
#include "ExecutorBuilder.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyShutdownRunTest1) IMPLEMENTS(Runnable) {
public:
    void run() {
        //TEST_FAIL("i am running123 ");
        sleep(10);
    }
};

DECLARE_CLASS(MyShutdownRunTest2) IMPLEMENTS(Runnable) {
public:
    _MyShutdownRunTest2() {
        mMutex = createMutex();
        count = 0;
    }

    void run() {
        //TEST_FAIL("i am running123 ");
        sleep(10);
    }

    bool onInterrupt() {
        AutoLock ll(mMutex);
        count++;
        return false;
    }

    int getCount() {
        return count;
    }

private:
    Mutex mMutex;
    int count;
};

DECLARE_CLASS(MyShutdownRunTest3) IMPLEMENTS(Runnable) {
public:
    void run() {

    }
};

DECLARE_CLASS(MyShutdownRunTest4) IMPLEMENTS(Thread) {
public:
    _MyShutdownRunTest4(ThreadPoolExecutor p) {
        mPool = p;
    }

    void run() {
        long start = st(System)::currentTimeMillis();
        mPool->awaitTermination(10000);
        long end = st(System)::currentTimeMillis();
        interval = end - start;
    }

    long getInterval() {
        return interval;
    }

private:
    ThreadPoolExecutor mPool;
    long interval;
};

void testThreadShutdown() {


    //TestThread onInterrupt case1
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->newThreadPool();
        pool->shutdown();
        int ret = pool->shutdown();

        if(ret != -AlreadyDestroy) {
            TEST_FAIL("[ThreadPoolExecutor Test {shutdown()} special case1],ret is %d ",ret);
            break;
        }

        auto mtask = pool->submit(createMyShutdownRunTest1());
        if(mtask != nullptr) {
            TEST_FAIL("[ThreadPoolExecutor Test {shutdown()} special case2]");
            break;
        }

        TEST_OK("[ThreadPoolExecutor Test {shutdown()} special case3]");
        break;
    }

    while(1) {
        ThreadPoolExecutor pool = createThreadPoolExecutor(128,1);
        MyShutdownRunTest2 run = createMyShutdownRunTest2();
        pool->submit(run);
        pool->submit(run);
        pool->submit(run);
        pool->submit(run);
        pool->submit(run);
        sleep(1);
        pool->shutdown();
        sleep(1);
        if(run->getCount() != 5) {
            TEST_FAIL("[ThreadPoolExecutor Test {shutdown()} special case4,run->getCount is %d ] ",run->getCount());
            break;
        }
        TEST_OK("[ThreadPoolExecutor Test {shutdown()} special case5]");
        break;
    }

    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->newThreadPool();
        long t = st(System)::currentTimeMillis();
        pool->awaitTermination(1000);
        long current = st(System)::currentTimeMillis();
        if((current - t) > 1) {
            TEST_FAIL("[ThreadPoolExecutor Test {shutdown()} special case6, interval is %ld] ",current - t);
            break;
        }

        pool->shutdown();
        TEST_OK("[ThreadPoolExecutor Test {shutdown()} special case7]");
        break;
    }

    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->newThreadPool();
        pool->submit(createMyShutdownRunTest3());
        pool->shutdown();
        long t = st(System)::currentTimeMillis();
        int result = pool->awaitTermination(1000);
        long current = st(System)::currentTimeMillis();
        if((current - t) > 10 || result < 0) {
            TEST_FAIL("[ThreadPoolExecutor Test {shutdown()} special case8],interval is %ld,result is %d ",current - t,result);
            break;
        }

        TEST_OK("[ThreadPoolExecutor Test {shutdown()} special case9]");
        break;
    }

}
