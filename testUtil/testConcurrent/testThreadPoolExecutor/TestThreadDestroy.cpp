#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "ExecutorBuilder.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyDestroyTest) IMPLEMENTS(Runnable) {
public:
    void run() {
        //TEST_FAIL("i am running123 ");
        sleep(5);
    }

};

void testThreadDestroy() {

    //TestThread onInterrupt case1
    while(1) {
        //try {
            {
                ThreadPoolExecutor pool = ExecutorBuilder::New()->newThreadPool();
                pool->submit(MyDestroyTest::New());
                pool->shutdown();
            }
            sleep(10);
        //} catch(ExecutorDestructorException e) {
        //    TEST_FAIL("[ThreadPoolExecutor Test {destroy()} special case1] [FAIL] ");
        //    break;
        //}

        TEST_OK("[ThreadPoolExecutor Test {destroy()} special case1]");
        break;
    }

}
