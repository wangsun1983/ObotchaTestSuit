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

using namespace obotcha;


extern int baseTest();
extern int scheduleTest();
extern int ReleaseTest();
//extern int fixRateTest();
//extern int fixDelayTest();
extern int scheduleloopsubmit();
extern int testThreadLambda();

extern void testSubmitWait();
extern void testSubmitTask();
extern void testSubmitTimeout();
extern void testAwaitTermination();
extern void testShutdownCount();

int main() {

#if 0
    testSubmitWait();
    testSubmitTask();
    testSubmitTimeout();
    testAwaitTermination();

    testThreadLambda();
    baseTest();
    scheduleTest();
    ReleaseTest();
    scheduleloopsubmit();
#endif
    testShutdownCount();

    sleep(10);

}
