#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "InterruptedException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int interruptVal = 1;

DECLARE_CLASS(RunTest1) IMPLEMENTS(Runnable) {
public:
    void run() {
        //TEST_FAIL("i am running ");
        try {
            st(Thread)::Sleep(10*1000);
        } catch(InterruptedException &e) {
            interruptVal = 2;
        }

    }

    ~_RunTest1() {
        //TEST_FAIL("i am release ");
        //unDestory = 0;
        //interruptVal = 1;
    }
};



void testRunnable_onInterrupt() {
    //void shutdown();
    while(1) {
        ThreadPoolExecutor pool = createExecutorBuilder()->setMaxPendingTaskNum(100)->setDefaultThreadNum(100)->newThreadPool();
        pool->submit(createRunTest1());
        sleep(1);
        pool->shutdown();
        sleep(5);
        if(interruptVal != 2) {
            TEST_FAIL("[TestThreadPoolExecutor TestOnInterrupt {onInterrupt(),interruptVal is %d} case1]  ",interruptVal);
            break;
        }

        TEST_OK("[TestThreadPoolExecutor TestOnInterrupt {onInterrupt()} case1]");
        break;
    }

}
