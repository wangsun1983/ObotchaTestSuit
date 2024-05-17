#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "System.hpp"
#include "File.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;


void testSleep() {
  TimeWatcher watch = TimeWatcher::New();
  watch->start();
  st(System)::Sleep(1000);
  auto ret = watch->stop();
  if(ret > 1005 || ret < 995) {
	  TEST_FAIL("[testSleep case1]");
  }
  
  watch->start();
  st(System)::Sleep(1100);
  ret = watch->stop();
  if(ret > 1105 || ret < 1095) {
  	  TEST_FAIL("[testSleep case2],ret is %ld",ret);
  }
  
  watch->start();
  st(System)::Sleep(100);
  ret = watch->stop();
  if(ret > 105 || ret < 95) {
  	  TEST_FAIL("[testSleep case3],ret is %ld",ret);
  }
  
  watch->start();
  st(System)::Sleep(130);
  ret = watch->stop();
  if(ret > 135 || ret < 125) {
  	  TEST_FAIL("[testSleep case4],ret is %ld",ret);
  }
  TEST_OK("[testSleep case100]");
}
