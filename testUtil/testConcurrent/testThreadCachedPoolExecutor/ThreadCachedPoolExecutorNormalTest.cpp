#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadCachedPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "ExecutorBuilder.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int runDestory = 1;
DECLARE_CLASS(RunTest1) IMPLEMENTS(Runnable) {
public:
    void run() {
        try {
            st(Thread)::Sleep(10*1000);
        } catch(InterruptedException &e){
            
        }
    }


    ~_RunTest1() {
        runDestory = 0;
    }
};

Mutex runTest2Mutex;
DECLARE_CLASS(RunTest2) IMPLEMENTS(Runnable) {
public:
    void run() {
        runTest2Mutex->lock();
    }
};


int normalTest() {

    //int awaitTermination(long timeout = 0);
    while(1) {
        ThreadCachedPoolExecutor pool = ExecutorBuilder::New()->newCachedThreadPool();

        //int result = pool->awaitTermination(0);
        //if(result != -InvalidStatus) {
        //    TEST_FAIL("[TestCachedPoolExecutor Test {awaitTermination()} case5]");
        //    pool->shutdown();
        //    break;
        //}

        pool->submit(RunTest1::New());
        pool->shutdown();

        long current = st(System)::CurrentTimeMillis();
        int result = pool->awaitTermination(0);
        if(result != 0) {
            TEST_FAIL("[TestCachedPoolExecutor Test {awaitTermination()} case6]");
            pool->shutdown();
            break;
        }

        long current2 = st(System)::CurrentTimeMillis();
        //TEST_FAIL("current2 - current1 is %d ",(current2 - current));
        if(current2 - current > 10005) {
            TEST_FAIL("[TestCachedPoolExecutor Test {awaitTermination()} case7,interval is %ld]",current2 - current);
            break;
        }

        TEST_OK("[TestCachedPoolExecutor Test {awaitTermination()} case8]");
        break;
    }

    sleep(1);

    return 0;
}
