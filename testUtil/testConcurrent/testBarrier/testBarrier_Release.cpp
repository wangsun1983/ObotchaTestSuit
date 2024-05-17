#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testBarrierRelease() {
  while(1) {
    Barrier barrier1 = Barrier::New(3);
    Thread t1 = Thread::New([&barrier1]{
      auto watch = TimeWatcher::New();
      watch->start();
      barrier1->await();
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case1],l is %ld",l);
      }
    });

    Thread t2 = Thread::New([&barrier1]{
      auto watch = TimeWatcher::New();
      watch->start();
      barrier1->await();
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case2],l is %ld",l);
      }
    });

    t1->start();
    t2->start();

    usleep(1000*100);
    Thread t3 = Thread::New([&barrier1]{
      barrier1->release();
    });
    t3->start();

    t1->join();
    t2->join();
    t3->join();
    break;
  }

  while(1) {
    Barrier barrier1 = Barrier::New(3);
    Thread t1 = Thread::New([&barrier1]{
      auto watch = TimeWatcher::New();
      watch->start();
      barrier1->await(1000);
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case3],l is %ld",l);
      }
    });

    Thread t2 = Thread::New([&barrier1]{
      auto watch = TimeWatcher::New();
      watch->start();
      barrier1->await(1000);
      auto l = watch->stop();
      if(l < 100 || l > 105) {
        TEST_FAIL("[Barrier Test {Release test} case4],l is %ld",l);
      }
    });

    t1->start();
    t2->start();

    usleep(1000*100);
    Thread t3 = Thread::New([&barrier1]{
      barrier1->release();
    });
    t3->start();

    t1->join();
    t2->join();
    t3->join();
    break;
  }
  
  while(1) {
	  Barrier b = Barrier::New(5);
	  Thread t1 = Thread::New([&]{
		TimeWatcher w = TimeWatcher::New();
		w->start();
		b->await();
		auto ret = w->stop();
		if(ret < 195 || ret > 205) {
			TEST_FAIL("[Barrier Test {Release test} case4],ret is %d",ret);
		}
	  });
	  
	  Thread t2 = Thread::New([&]{
	  	TimeWatcher w = TimeWatcher::New();
	  	w->start();
	  	b->await();
	  	auto ret = w->stop();
	  	if(ret < 195 || ret > 205) {
	  		TEST_FAIL("[Barrier Test {Release test} case5],ret is %d",ret);
	  	}
	  });
	  
	  t1->start();
	  t2->start();
	  
	  usleep(200*1000);
	  b->release();
	  
	  t1->join();
	  t2->join();
	  TEST_OK("[Barrier Test {Release test} case6]");
	  break;
  }

  TEST_OK("[Barrier Test {Release test} case100]");
}
