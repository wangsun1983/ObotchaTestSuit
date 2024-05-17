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
#include "TestLog.hpp"

using namespace obotcha;

long RunTestTime1 = 1;
long RunTestTime2 = 1;

DECLARE_CLASS(ScheduleRunTest1) IMPLEMENTS(Runnable) {
public:
    void run() {
        RunTestTime1 = st(System)::CurrentTimeMillis();
        sleep(5);
    }

    ~_ScheduleRunTest1() {
        //TEST_FAIL("i am release .......aaaa,p is %x\n",this);
    }
};

DECLARE_CLASS(ScheduleRunTest2) IMPLEMENTS(Runnable) {
public:
    void run() {
        RunTestTime2 = st(System)::CurrentTimeMillis();
        sleep(5);
    }
};

int runTest3Val = 0;
DECLARE_CLASS(RunTest3) IMPLEMENTS(Runnable) {
public:
    void run() {
        runTest3Val = 1;
    }
};


int scheduleTest() {
    //TEST_FAIL("[TestScheduledThreadPoolExecutor Test Start] \n");
    //schedule test
    while(1) {
        ThreadScheduledPoolExecutor pool = ExecutorBuilder::New()->newScheduledThreadPool();
        long current = st(System)::CurrentTimeMillis();
        pool->schedule(5000,ScheduleRunTest1::New());
        pool->schedule(5000,ScheduleRunTest2::New());
        sleep(15);
        long v = (RunTestTime1 - RunTestTime2);
        if(v > 50 || v < -50) {
            pool->shutdown();
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {schedule()} case1]");
            break;
        }

        int inter = (RunTestTime1 - current - 5000);
        if(inter > 10) {
            pool->shutdown();
            TEST_FAIL("[ScheduledThreadPoolExecutor Test {schedule()} case2]");
            break;
        }
        pool->shutdown();
        TEST_OK("[ScheduledThreadPoolExecutor Test {schedule()} case3]");
        break;
    }

    return 0;
}
