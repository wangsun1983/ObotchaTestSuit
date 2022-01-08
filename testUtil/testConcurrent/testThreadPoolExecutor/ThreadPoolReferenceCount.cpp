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

void testPoolReferenceCount() {

    while(1) {
        ThreadPoolExecutor pool = nullptr;
        {
            pool = createExecutorBuilder()->setThreadNum(4)->newThreadPool();
            pool->submit([]() {
              try {
                st(Thread)::interruptableSleep(10);
              } catch(InterruptedException &e){}
            });

            pool->submit([]() {
              try {
                st(Thread)::interruptableSleep(10);
              } catch(InterruptedException &e){}
            });

            pool->submit([]() {
              try {
                st(Thread)::interruptableSleep(10);
              } catch(InterruptedException &e){}
            });
        }

        if(pool->getStrongCount() != 9) {
          TEST_FAIL("[ThreadPoolExecutor Test Reference count is %d case1]",pool->getStrongCount());
          //break;
        }

        pool->shutdown();
        sleep(11);
        if(pool->getStrongCount() != 1) {
          TEST_FAIL("[ThreadPoolExecutor Test Reference count is %d case2]",pool->getStrongCount());
          //break;
        }
        sleep(5);
        if(pool->getStrongCount() != 1) {
          TEST_FAIL("[ThreadPoolExecutor Test Reference count is %d case3]",pool->getStrongCount());
          //break;
        }

        TEST_OK("[ThreadPoolExecutor Test Reference case4]");
        break;
    }

}
