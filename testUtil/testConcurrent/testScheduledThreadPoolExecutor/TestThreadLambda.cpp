#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testThreadLambda() {
    ThreadScheduledPoolExecutor t = ExecutorBuilder::New()->newScheduledThreadPool();
    while(1) {
        long time1 = 0;
        long time2 = st(System)::CurrentTimeMillis();

        t->schedule(5000,[&time1]() {
            time1 = st(System)::CurrentTimeMillis();
        });

        sleep(6);
        if(time2 - time1 > 5005 || time1 - time2 > 5005) {
            TEST_FAIL("[testThreadLambda value case1]");
            break;
        }
        TEST_OK("[testThreadLambda value case2]");
        break;
    }
    t->shutdown();
    sleep(10);
    TEST_OK("testThreadLambda inner shutdown");

    return 0;
}
