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
  while(1) {
      Barrier barrier = createBarrier(2);
      TimeWatcher w = createTimeWatcher();
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
      break;
  }
  
  while(1) {
      Barrier barrier = createBarrier(2);
      TimeWatcher w = createTimeWatcher();
      w->start();
      int waitret = -1;
      barrier->await([&waitret]{
          waitret = 100;
      },100);
      
      auto r = w->stop();
      if(r > 105 || r < 95) {
          TEST_FAIL("[Barrier Test {Timeout test} case4]");
      }
      
      if(waitret == 100) {
          TEST_FAIL("[Barrier Test {Timeout test} case5]");
      }
      break;
  }
  
  TEST_OK("[Barrier Test {Timeout test} case100]");
}
