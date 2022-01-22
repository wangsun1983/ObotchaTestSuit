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

std::atomic_int interrptCount{0};

DECLARE_CLASS(ThreadPoolCancelTask) IMPLEMENTS(Runnable){
public:
    void run() {
      usleep(1000*500);
    }

    bool onInterrupt() {
      interrptCount++;
      return false;
    }
};

void testThreadPoolInterruptNum() {

    while(1) {
        ThreadPoolExecutor pool= createExecutorBuilder()->setThreadNum(4)->newThreadPool();
        for(int i = 0;i<32*1024;i++) {
          pool->submit(createThreadPoolCancelTask());
        }

        usleep(1000*15);
        pool->shutdown();
        pool->awaitTermination();
        if(interrptCount != 32*1024) {
          int value = interrptCount;
          TEST_FAIL("[ThreadPoolInterruptNum Test case1],count is %d",value);
        }
        break;
    }

    TEST_OK("[ThreadPoolInterruptNum Test case100]");
}
