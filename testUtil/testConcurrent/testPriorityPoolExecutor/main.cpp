#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPriorityPoolExecutor.hpp"
#include "Integer.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "InterruptedException.hpp"

using namespace obotcha;

extern void testSubmitWait();
extern void testSubmitPriority();
extern void testSubmitMultiThread();
extern void testAwaitTermination();
extern void testShutdownCount();

int main() {

    testSubmitWait();
    testSubmitPriority();
    testSubmitMultiThread();
    testAwaitTermination();
    testShutdownCount();

    return 1;
}
