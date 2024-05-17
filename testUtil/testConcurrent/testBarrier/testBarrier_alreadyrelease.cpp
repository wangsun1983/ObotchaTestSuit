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

void testBarrierAlreadyRelease() {
  Barrier barrier = Barrier::New(3);
  
  Thread t1 = Thread::New([&] {
	  barrier->await();
  });
  
  Thread t2 = Thread::New([&] {
  	  barrier->await();
  });
  
  Thread t3 = Thread::New([&] {
  	  barrier->await();
  });
  
  t1->start();
  t2->start();
  t3->start();
  
  t1->join();
  t2->join();
  t3->join();
  
  Thread t4 = Thread::New([&] {
  	  if(barrier->await() != -1) {
		  TEST_FAIL("[Barrier Test {Already Release test} case1]");
	  }
  });
  
  Thread t5 = Thread::New([&] {
  	  if(barrier->await() != -1) {
  	  		  TEST_FAIL("[Barrier Test {Already Release test} case2]");
  	  }
  });
  t4->start();
  t5->start();
  
  TimeWatcher w = TimeWatcher::New();
  w->start();
  t4->join(1000*100);
  t5->join(1000*100);
  if(w->stop() > 5) {
	  TEST_FAIL("[Barrier Test {Already Release test} case3]");
  }
  TEST_OK("[Barrier Test {Already Release test} case100]");
}
