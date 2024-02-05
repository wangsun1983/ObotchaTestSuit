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
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int count = 0;
DECLARE_CLASS(MySleepWaitRun) IMPLEMENTS(Runnable) {
public:
    void run() {
        try {
            st(Thread)::Sleep();
        } catch(...) {}
        count++;
    }
};

void testThreadQuickShutDown() {


    //TestThread onInterrupt case1
    while(1) {
        for(int i = 0;i < 32*1024;i++) {
            //TEST_FAIL("trace1 ");
            ThreadPoolExecutor t = createThreadPoolExecutor(4,4,0);
            //TEST_FAIL("trace2 ");
            t->submit(createMySleepWaitRun());
            t->submit(createMySleepWaitRun());
            t->submit(createMySleepWaitRun());
            t->submit(createMySleepWaitRun());
            //TEST_FAIL("trace3 ");
            t->shutdown();
            //TEST_FAIL("trace4 ");
            t->awaitTermination();
            //TEST_FAIL("trace5 ");
        }

        TEST_OK("[ThreadPoolExecutor Test {QuickShutDown()} special case1],count is %d ",count);
        break;
    }

}
