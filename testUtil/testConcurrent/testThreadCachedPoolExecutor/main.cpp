#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadCachedPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"

using namespace obotcha;

extern int normalTest();
extern int numTest();
extern int releaseTest();
extern int loopsubmittest();
extern int cancelTest();
extern int testThreadLambda();
extern void CachedPoolSubmit_Wait();
extern void CachedPoolSubmit_ThreadNum();
extern void CachedPoolSubmit_AwaitTermination();
extern void CachedPoolSubmit_Timeout();

int main() {

    normalTest();
    numTest();
    releaseTest();
    loopsubmittest();
    cancelTest();

    testThreadLambda();
    sleep(10);

    CachedPoolSubmit_Wait();
    CachedPoolSubmit_ThreadNum();
    CachedPoolSubmit_AwaitTermination();
    CachedPoolSubmit_Timeout();


    //cancelTestOne();
    return 0;
}
