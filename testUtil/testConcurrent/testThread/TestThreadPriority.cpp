#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyPriorityThread) IMPLEMENTS(Thread) {
public:
    void run() {
        setPriority(st(Thread)::ThreadPriority::High);
        int priority = getPriority();
        if(priority != -NotSupport) {
            TEST_OK("[Thread Test {Set Priority()} case1],priority is %d",priority);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Low);
        priority = getPriority();
        if(priority != -NotSupport) {
            TEST_OK("[Thread Test {Set Priority()} case2],priority is %d",priority);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Normal);
        priority = getPriority();
        if(priority != -NotSupport) {
            TEST_OK("[Thread Test {Set Priority()} case3],priority is %d",priority);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Highest);
        priority = getPriority();
        if(priority != -NotSupport) {
            TEST_OK("[Thread Test {Set Priority()} case4],priority is %d",priority);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Realtime);
        priority = getPriority();
        if(priority != -NotSupport) {
            TEST_OK("[Thread Test {Set Priority()} case5],priority is %d",priority);
        }

        /////////////////////////////////policy changed
        setSchedPolicy(st(Thread)::SchedType::Fifo);
        int policy = getSchedPolicy();
        if(policy != st(Thread)::SchedType::Fifo) {
            TEST_OK("[Thread Test {Set Priority()} case6],policy is %d",policy);
        }

        int ret = setPriority(st(Thread)::ThreadPriority::Low);
        priority = getPriority();
        if(priority != st(Thread)::ThreadPriority::Low) {
            TEST_OK("[Thread Test {Set Priority()} case7],priority is %d,ret is %d",priority,ret);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Normal);
        priority = getPriority();
        if(priority != st(Thread)::ThreadPriority::Normal) {
            TEST_OK("[Thread Test {Set Priority()} case8],priority is %d",priority);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Highest);
        priority = getPriority();
        if(priority != st(Thread)::ThreadPriority::Highest) {
            TEST_OK("[Thread Test {Set Priority()} case9],priority is %d",priority);
        }

        sleep(100);
        setPriority(st(Thread)::ThreadPriority::Realtime);
        priority = getPriority();
        if(priority != st(Thread)::ThreadPriority::Realtime) {

            TEST_OK("[Thread Test {Set Priority()} case10],priority is %d",priority);
        }

        TEST_OK("[Thread Test {Set Priority()} case20]");
    }
};


void testThreadPriority() {
    //TestThread onInterrupt case1
    MyPriorityThread t = createMyPriorityThread();
    t->start();
    t->join();

}
