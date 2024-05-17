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
#include "ThreadScheduledPoolExecutor.hpp"
#include "Long.hpp"
#include "TestLog.hpp"

using namespace obotcha;

AtomicInteger myloopvalue = AtomicInteger::New(0);

DECLARE_CLASS(MyLoopSubmit) IMPLEMENTS(Runnable) {
public:

    void run() {
        myloopvalue->incrementAndGet();
    }

    bool onInterrupt() {
        //TEST_FAIL("MyLoopSubmit interrupt \n");
        return false;
    }
};

Mutex myloopsubmitMutex = Mutex::New("MyMutex");
ArrayList<long> currentTimeList = ArrayList<long>::New();

DECLARE_CLASS(MyLoopTimeSubmit) IMPLEMENTS(Runnable) {
public:

    void run() {
        AutoLock l(myloopsubmitMutex);
        currentTimeList->add(st(System)::CurrentTimeMillis());
    }

    bool onInterrupt() {
        //TEST_FAIL("MyLoopSubmit interrupt \n");
        return false;
    }
};

int scheduleloopsubmit() {
    //test1
    ThreadScheduledPoolExecutor pool = ExecutorBuilder::New()->newScheduledThreadPool();
    long time = st(System)::CurrentTimeMillis();
    for(int i = 0; i < 32*1024;i++) {
        pool->schedule(0,MyLoopSubmit::New());
    }

    sleep(1);
    if(myloopvalue->get() != 32*1024) {
        TEST_FAIL("[ScheduledThreadPoolExecutor LoopSubmit case1]");
    }
    pool->shutdown();

    //test2
    myloopvalue = AtomicInteger::New(0);
    pool = ExecutorBuilder::New()->newScheduledThreadPool();
    for(int i = 0; i < 32*1024;i++) {
        pool->schedule(100,MyLoopSubmit::New());
    }

    sleep(5);

    if(myloopvalue->get() != 32*1024) {
        TEST_FAIL("[ScheduledThreadPoolExecutor LoopSubmit case2]");
    }
    pool->shutdown();

#if 0 //need test
    //test3
    pool = ExecutorBuilder::New()->newScheduledThreadPool();
    time = st(System)::CurrentTimeMillis();

    for(int i = 0; i < 32*1024;i++) {
        pool->submit(createMyLoopTimeSubmit(),1);
    }

    sleep(5);
    if(currentTimeList->size() != 32*1024) {
        TEST_FAIL("[ScheduledThreadPoolExecutor LoopSubmit case3]");
    }

    for(int i = 0;i < 32*1024;i++) {
        long v = currentTimeList->get(i);
        if((v - time) > 200) {
           TEST_FAIL("[ScheduledThreadPoolExecutor LoopSubmit case4]");
           //break;
        }
    }
#endif
    TEST_OK("[ScheduledThreadPoolExecutor LoopSubmit case100]");
    return 0;
}
