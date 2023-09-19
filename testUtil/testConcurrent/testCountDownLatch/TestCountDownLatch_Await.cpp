#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "CountDownLatch.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testCountDownLatch_Await() {
    TimeWatcher watcher = createTimeWatcher();
    while(1) {
      CountDownLatch latch = createCountDownLatch(1);
      Thread t = createThread([&latch]{
        usleep(200*1000);
        latch->countDown();
      });
      t->start();
      watcher->start();
      latch->await(100);
      long result = watcher->stop();
      if(result < 100 || result > 105) {
        TEST_FAIL("[TestCountDownLatch await case1]");
        break;
      }

      t->join();
      watcher->start();
      latch->await(100);
      result = watcher->stop();
      if(result > 5) {
        TEST_FAIL("[TestCountDownLatch await case2]");
        break;
      }
      break;
    }
	
	while(1) {
		CountDownLatch latch = createCountDownLatch(1);
		Thread t = createThread([&latch]{
		  usleep(200*1000);
		  latch->countDown();
		});

		t1->start();
		watcher->start();
		int ret = latch->await();
		auto cost = watcher->stop();
		if(ret != 0) {
			TEST_FAIL("[TestCountDownLatch await case3]");
		}
		
		if(cost < 195 || cost > 205) {
			TEST_FAIL("[TestCountDownLatch await case4]");
		}
		break;
	}
	
	while(1) {
		CountDownLatch latch = createCountDownLatch(1);
		watcher->start();
		auto result = latch->await(100);
		auto ret = watcher->stop();
		if(result >= 0 || ret >105 || ret < 95) {
			TEST_FAIL("[TestCountDownLatch await case5]");
		}
		break;
	}
	
	while(1) {
		CountDownLatch latch = createCountDownLatch(1);
		latch->countDown();
		watcher->start();
		if(latch->await() != -1) {
			TEST_FAIL("[TestCountDownLatch await case6]");
		}
		break;
	}
	
	while(1) {
		CountDownLatch latch = createCountDownLatch(1);
		long cost1 = 0;
		long cost2 = 0;
		long cost3 = 0;
		long cost4 = 0;
		
		Thread t1 = createThread([&]{
			TimeWatcher w1 = createTimeWatcher();
			w1->start();
			cost1 = latch->await();
		});
		
		Thread t2 = createThread([&]{
			TimeWatcher w2 = createTimeWatcher();
			w2->start();
			cost2 = latch->await();
		});
		
		Thread t3 = createThread([&]{
			TimeWatcher w3 = createTimeWatcher();
			w3->start();
			cost3 = latch->await();
		});
		
		Thread t4 = createThread([&]{
			TimeWatcher w4 = createTimeWatcher();
			w4->start();
			cost4 = latch->await();
		});
		
		t1->start();
		t2->start();
		t3->start();
		t4->start();
		
		usleep(200*1000);
		latch->countDown();
		t1->join();
		t2->join();
		t3->join();
		t4->join();
		
		if(cost1 > 205 || cost1 < 195) {
			TEST_FAIL("[TestCountDownLatch await case7],cost1 is %ld",cost1);
		}
		
		if(cost2 > 205 || cost2 < 195) {
			TEST_FAIL("[TestCountDownLatch await case7],cost2 is %ld",cost2);
		}
		
		if(cost3 > 205 || cost3 < 195) {
			TEST_FAIL("[TestCountDownLatch await case7],cost3 is %ld",cost3);
		}
		
		if(cost4 > 205 || cost4 < 195) {
			TEST_FAIL("[TestCountDownLatch await case7],cost2 is %ld",cost4);
		}
		
	}
    TEST_OK("[TestCountDownLatch await case100]");
}
