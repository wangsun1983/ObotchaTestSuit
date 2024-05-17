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
#include "Error.hpp"
#include "ThreadScheduledPoolExecutor.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyReleaseTest) IMPLEMENTS(Runnable) {
public:
    _MyReleaseTest() {
        //TEST_FAIL("MyReleaseTest is %lx \n",this);
    }

    void run() {
        //TEST_FAIL("MyReleaseTest running1 \n");
        sleep(1);
        //TEST_FAIL("MyReleaseTest running2 \n");
    }

    bool onInterrupt() {
        //TEST_FAIL("MyReleaseTest interrupt \n");
        return false;
    }

    ~_MyReleaseTest() {
        //
    }
};



int ReleaseTest() {

    while(1) {
        {
            ThreadScheduledPoolExecutor pool = ExecutorBuilder::New()->newScheduledThreadPool();
            for(int i = 0; i < 50;i++) {
                pool->schedule(100,MyReleaseTest::New());
            }
            //TEST_FAIL("test1 pool size is %d \n",pool->getStrongCount());
            sleep(2);
            //TEST_FAIL("test2 pool size is %d \n",pool->getStrongCount());
            pool->shutdown();
            //TEST_FAIL("test3 pool count is %d \n",pool->getStrongCount());
        }
        TEST_OK("[ScheduledThreadPoolExecutor Test {Release} case6]");
        break;
    }


    while(1) {
        //TEST_FAIL("start another test \n");

        {
//TEST_FAIL("start another test1 \n");

            ThreadScheduledPoolExecutor pool = ExecutorBuilder::New()->newScheduledThreadPool();
            for(int i = 0; i < 50;i++) {
                pool->schedule(100,MyReleaseTest::New());
            }

            sleep(3);

            //TEST_FAIL("start another test2 \n");

            pool->shutdown();
            //TEST_FAIL("start another test3 \n");

            sleep(5);

            pool = nullptr;

            //TEST_FAIL("MyReleaseTest is %d \n",st(MyReleaseTest)::getDebugReferenceCount());
            //TEST_FAIL("Thread is %d \n",st(Thread)::getDebugReferenceCount());
        }
        sleep(50);


        TEST_OK("[ScheduledThreadPoolExecutor Test {Release} case10]");
        break;
    }
    return 0;
}
