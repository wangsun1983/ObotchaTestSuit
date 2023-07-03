#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int runDestory = 1;
DECLARE_CLASS(BaseRunTest1) IMPLEMENTS(Runnable) {
public:
    void run() {
        sleep(5);
    }

    ~_BaseRunTest1() {
        //TEST_FAIL("i am release \n");
        runDestory = 0;
    }
};

Mutex runTest2Mutex;
DECLARE_CLASS(BaseRunTest2) IMPLEMENTS(Runnable) {
public:
    void run() {
        //TEST_FAIL("RunTest2 start 1\n");
        //runTest2Mutex->lock();
        //TEST_FAIL("RunTest2 start 2\n");
    }
};


int baseTest() {
    //TEST_FAIL("[TestScheduledThreadPoolExecutor Test Start] \n");

    //_ScheduledThreadPoolExecutor()
    while(1) {
        ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();

        pool->shutdown();
        TEST_OK("[ScheduledThreadPoolExecutor Test {constructor()} case1]");
        break;
    }


    //void shutdown();
    while(1) {
        ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
        pool->schedule(0,createBaseRunTest1());
        pool->shutdown();
        sleep(5);
        //if(!pool->isShutdown()) {
        //    TEST_FAIL("[ScheduledThreadPoolExecutor Test {shutdown()} case1] [FAIL] \n");
        //    break;
        //}

        Future task = pool->schedule(0,createBaseRunTest1());
        if(task != nullptr) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {shutdown()} case2]");
            break;
        }

        auto result = pool->schedule(0,createBaseRunTest1());
        if(result != nullptr) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {shutdown()} case3]");
            break;
        }

        TEST_OK("[ScheduledThreadPoolExecutor Test {shutdown()} case4]");
        break;
    }


    //int awaitTermination(long timeout);
    while(1) {
        ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
        int result = pool->awaitTermination(1000);
        if(result != -1) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case1]");
            break;
        }

        //runTest2Mutex = createMutex();
        //runTest2Mutex->lock();

        pool->schedule(0,createBaseRunTest2());
        sleep(1);
        pool->shutdown();

        long current = st(System)::CurrentTimeMillis();
        result = pool->awaitTermination(5000);
        if(result != 0) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case2]");
            break;
        }
        long current2 = st(System)::CurrentTimeMillis();
        if(current2 - current > 15) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case3]");
            break;
        }

        TEST_OK("[ScheduledThreadPoolExecutor Test {awaitTermination()} case4]");
        break;
    }


    //int awaitTermination(long timeout = 0);
    while(1) {
        ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
        int result = pool->awaitTermination(0);
        if(result != -1) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case5]");
            break;
        }

        pool->schedule(0,createBaseRunTest1());
        int v = pool->shutdown();

        long current = st(System)::CurrentTimeMillis();
        result = pool->awaitTermination(0);
        if(result != 0) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case6]");
            break;
        }

        long current2 = st(System)::CurrentTimeMillis();
        //TEST_FAIL("current2 - current1 is %d \n",(current2 - current));
        if(current2 - current > 10005) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case7]");
            break;
        }

        TEST_OK("[ScheduledThreadPoolExecutor Test {awaitTermination()} case8]");
        break;
    }



    //int awaitTermination(long timeout = max);
    while(1) {
        ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
        pool->schedule(0,createBaseRunTest1());
        pool->shutdown();

        long current = st(System)::CurrentTimeMillis();
        pool->awaitTermination(100000);
        int v = st(System)::CurrentTimeMillis() - current;
        if(v > 10005) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {awaitTermination()} case9]");
            break;
        }

        TEST_OK("[ScheduledThreadPoolExecutor Test {awaitTermination()} case10]");
        break;
    }



    //submit(Runnable task);
    while(1) {
        ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
        Future task = pool->schedule(0,createBaseRunTest1());
        if(task == nullptr) {
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {submit()} case1]");
            break;
        }

        //long current = st(System)::CurrentTimeMillis();
        //Future task2 = pool->submit(createRunTest1());
        //int v = st(System)::CurrentTimeMillis() - current;
        //if(v >10005) {
        //    TEST_FAIL("[ScheduledThreadPoolExecutor Test {submit()} case2] [FAIL] \n");
        //    break;
        //}
        pool->shutdown();
        TEST_OK("[ScheduledThreadPoolExecutor Test {submit()} case3]");
        break;
    }

    return 0;
}
