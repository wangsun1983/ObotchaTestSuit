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

using namespace obotcha;

DECLARE_CLASS(MyReleaseTest) IMPLEMENTS(Runnable) {
public:
    _MyReleaseTest() {
        //printf("MyReleaseTest is %lx \n",this);
    }

    void run() {
        //printf("MyReleaseTest running1 \n");
        sleep(1);
        //printf("MyReleaseTest running2 \n");
    }

    void onInterrupt() {
        //printf("MyReleaseTest interrupt \n");
    }

    ~_MyReleaseTest() {
        //
    }
};



int ReleaseTest() {

    while(1) {
        {
            ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
            for(int i = 0; i < 50;i++) {
                pool->submit(100,createMyReleaseTest());
            }
            //printf("test1 pool size is %d \n",pool->getStrongCount());
            sleep(2);
            //printf("test2 pool size is %d \n",pool->getStrongCount());
            pool->shutdown();
            //printf("test3 pool count is %d \n",pool->getStrongCount());
        }
        printf("---[ScheduledThreadPoolExecutor Test {Release} case6] [OK]--- \n");
        break;
    }


    while(1) {
        //printf("start another test \n");

        {
//printf("start another test1 \n");

            ThreadScheduledPoolExecutor pool = createExecutorBuilder()->newScheduledThreadPool();
            for(int i = 0; i < 50;i++) {
                pool->submit(100,createMyReleaseTest());
            }

            sleep(3);

            //printf("start another test2 \n");

            pool->shutdown();
            //printf("start another test3 \n");

            sleep(5);

            pool = nullptr;

            //printf("MyReleaseTest is %d \n",st(MyReleaseTest)::getDebugReferenceCount());
            //printf("Thread is %d \n",st(Thread)::getDebugReferenceCount());

            printf("start another test4 \n");

        }
        sleep(50);


        printf("---[ScheduledThreadPoolExecutor Test {Release} case10] [OK]--- \n");
        break;
    }

}
