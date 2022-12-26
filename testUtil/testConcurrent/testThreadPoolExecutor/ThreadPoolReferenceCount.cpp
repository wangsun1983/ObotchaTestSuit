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
            pool = createExecutorBuilder()->setDefaultThreadNum(3)->newThreadPool();
            pool->submit([]() {
              try {
                st(Thread)::sleep(10);
              } catch(...){}
            });

            pool->submit([]() {
              try {
                st(Thread)::sleep(10);
              } catch(...){}
            });

            pool->submit([]() {
              try {
                st(Thread)::sleep(10);
              } catch(...){}
            });
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
        pool->awaitTermination();
        TEST_OK("[ThreadPoolExecutor Test Reference case4]");
        break;
    }
    
    while(1) {
        auto pool = createExecutorBuilder()->setDefaultThreadNum(4)->newThreadPool();
        pool->submit([]() {
          try {
            st(Thread)::sleep(100);
          } catch(...){}
        });
        
        if(pool->getStrongCount() <= 1) {
          TEST_FAIL("[ThreadPoolExecutor Test Reference count is %d case5]",pool->getStrongCount());
          //break;
        }
        
        usleep(200*1000);
        
        if(pool->getStrongCount() != 9) {
          //lambda will save all param
          TEST_FAIL("[ThreadPoolExecutor Test Reference count is %d case6]",pool->getStrongCount());
          //break;
        }
        pool->shutdown();
        pool->awaitTermination();
        break;
    }
    
    TEST_OK("[ThreadPoolExecutor Test Reference case100]");
}
