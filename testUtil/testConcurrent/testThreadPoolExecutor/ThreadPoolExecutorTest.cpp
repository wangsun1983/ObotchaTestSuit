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
#include "ExecutorBuilder.hpp"
#include "TestLog.hpp"

using namespace obotcha;


int runDestory = 1;
DECLARE_CLASS(MyRunTest1) IMPLEMENTS(Runnable) {
public:
    void run() {
        sleep(10);
    }

    bool onInterrupt() {
        //TEST_FAIL("i am interrupt ");
        runDestory = 2;
        return false;
    }

    ~_MyRunTest1() {
        //TEST_FAIL("i am release ");
        runDestory = 0;
    }
};

Mutex runTest2Mutex;
DECLARE_CLASS(RunTest2) IMPLEMENTS(Runnable) {
public:
    void run() {
        fflush(stdout);
        runTest2Mutex->lock();
    }

    void onInterrupt() {
        //TEST_FAIL("RunTest2 onInterrupt 2");
    }

    ~_RunTest2() {
        //TEST_FAIL("RunTest2 dispose 2");
    }
};


void normalTest() {
    //_ThreadPoolExecutor(int queuesize,int threadnum);

    while(1) {
        {
			ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(1)->setThreadNum(1)->newThreadPool();//st(Executors)::newFixedThreadPool(1,1);
			pool->shutdown();
		}

        sleep(1);

        TEST_OK("[TestThreadPoolExecutor Test {constructor()} case1]");
        break;
    }

    //_ThreadPoolExecutor();
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(1)->setThreadNum(1)->newThreadPool();
        pool->shutdown();
        TEST_OK("[TestThreadPoolExecutor Test {constructor2()} case1] ");
        break;
    }


    //void shutdown();
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(100)->setThreadNum(100)->newThreadPool();
        pool->submit(createMyRunTest1());
        pool->shutdown();
        sleep(5);
        //if(!pool->isShutdown()) {
        //    TEST_FAIL("[TestThreadPoolExecutor Test {shutdown()} case1]");
        //    break;
        //}

        Future task = pool->submit(createMyRunTest1());
        if(task != nullptr) {
            TEST_FAIL("[TestThreadPoolExecutor Test {shutdown()} case2]");
            break;
        }

        int result = pool->execute(createMyRunTest1());
        if(result != -InvalidStatus) {
            TEST_FAIL("[TestThreadPoolExecutor Test {shutdown()} case3],result is %d",result);
            break;
        }

        TEST_OK("[TestThreadPoolExecutor Test {shutdown()} case4]");
        break;
    }

    //int awaitTermination(long timeout);
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(1)->setThreadNum(1)->newThreadPool();
        int result = pool->awaitTermination(1000);
        if(result != -InvalidStatus) {
            TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()} case1]");
            break;
        }
        
        runTest2Mutex = createMutex();
        runTest2Mutex->lock();

        pool->submit(createRunTest2());
		//TEST_FAIL("start at % ld ",st(System)::currentTimeMillis());
        sleep(1);
		//TEST_FAIL("start end % ld ",st(System)::currentTimeMillis());
        pool->shutdown();

        long current = st(System)::currentTimeMillis();
        result = pool->awaitTermination(5000);
        //TEST_FAIL("awaitTermination result is %d ",result);
        if(result != -WaitTimeout) {
            TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()} case2],result is %d ",result);
            break;
        }

        long current2 = st(System)::currentTimeMillis();
        //TEST_FAIL("current2 - current1 is %d ",(current2 - current));
        if(current2 - current > 5015) {
            TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()} case3]");
            break;
        }

        TEST_OK("[TestThreadPoolExecutor Test {awaitTermination()} case4]");
        runTest2Mutex->unlock();
        break;
    }


    //int awaitTermination(long timeout = 0);
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(100)->setThreadNum(100)->newThreadPool();
        //int result = pool->awaitTermination(0);
        //if(result != -InvalidStatus) {
        //    TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()} case5]");
        //    break;
        //}

        pool->submit(createMyRunTest1());
        pool->shutdown();

        long current = st(System)::currentTimeMillis();
        //TEST_FAIL("awaitTermination start test ");
        int result = pool->awaitTermination(0);
        //TEST_FAIL("awaitTermination result is %d ",result);
        if(result != 0) {
            TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()} case6]");
            break;
        }

        long current2 = st(System)::currentTimeMillis();
        //TEST_FAIL("current2 - current1 is %d ",(current2 - current));
        if(current2 - current > 10005) {
            TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()} case7]");
            break;
        }

        TEST_OK("[TestThreadPoolExecutor Test {awaitTermination()} case8]");
        break;
    }


    //int awaitTermination(long timeout = max);
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(100)->setThreadNum(100)->newThreadPool();
        pool->submit(createMyRunTest1());
        pool->shutdown();

        long current = st(System)::currentTimeMillis();
        pool->awaitTermination(100000);
        long v = st(System)::currentTimeMillis() - current;
        if(v > 10005) {
            TEST_FAIL("[TestThreadPoolExecutor Test {awaitTermination()},v is %ld case9]",v);
            break;
        }

        TEST_OK("[TestThreadPoolExecutor Test {awaitTermination()} case10]");
        break;
    }


    //int getThreadsNum();
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(100)->setThreadNum(100)->newThreadPool();
        if(pool->getThreadsNum() != 100) {
            TEST_FAIL("[TestThreadPoolExecutor Test {getThreadsNum()} case1]");
            break;
        }
        pool->shutdown();
        TEST_OK("[TestThreadPoolExecutor Test {getThreadsNum()} case2]");
        break;
    }

    //submit(Runnable task);
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setQueueSize(1)->setThreadNum(1)->newThreadPool();
        Future task = pool->submit(createMyRunTest1());
        if(task == nullptr) {
            TEST_FAIL("[TestThreadPoolExecutor Test {submit()} case1]");
            break;
        }

        long current = st(System)::currentTimeMillis();
        Future task2 = pool->submit(createMyRunTest1());
        int v = st(System)::currentTimeMillis() - current;
        if(v >10005) {
            TEST_FAIL("[TestThreadPoolExecutor Test {submit()} case2]");
            break;
        }
        pool->shutdown();
        TEST_OK("[TestThreadPoolExecutor Test {submit()} case3]");
        break;
    }

}
