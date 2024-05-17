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

void testBarrierWaitTimeout() {
  Barrier barrier = Barrier::New(2);
  TimeWatcher w = TimeWatcher::New();
  w->start();
  barrier->await(200);
  auto ret = w->stop();
  if(ret < 195 || ret > 205) {
	  TEST_FAIL("[Barrier Test {Timeout test} case1]");
  }
  
  barrier->await(100);
  
  w->start();
  if(barrier->await(100) != -1) {
	  TEST_FAIL("[Barrier Test {Timeout test} case2]");
  }
  
  ret = w->stop();
  if(ret < 0 || ret > 5) {
  	  TEST_FAIL("[Barrier Test {Timeout test} case3]");
  }
  
  TEST_OK("[Barrier Test {Timeout test} case100]");
}
