#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "CountDownLatch.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Error.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testCountDownLatch_Release() {
    while(1) {
        CountDownLatch latch = createCountDownLatch(2);
        TimeWatcher watcher = createTimeWatcher();
        
        Thread t = createThread([& latch]{
            latch->await();
        });
        
        Thread t2 = createThread([& latch]{
            latch->await();
        });

        Thread t3 = createThread([& latch]{
            sleep(3);
            latch->release();
        });
        
        t->start();
        t2->start();
        t3->start();
        
        watcher->start();
        t->join();
        t2->join();
        auto v = watcher->stop();
        if(v < 3000 || v > 3005) {
            TEST_FAIL("[TestCountDownLatch Release case1],v is %d",v);
        }
        break;
    }

    TEST_OK("[TestCountDownLatch Release case100]");
}