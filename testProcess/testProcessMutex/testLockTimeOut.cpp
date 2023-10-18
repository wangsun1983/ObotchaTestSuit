#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"
#include "ProcessMutex.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testLockTimeout() {
  st(ProcessMutex)::Create("abc1");
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
		ProcessMutex mu = createProcessMutex("abc1");
		AutoLock l(mu);
		usleep(1000*500);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessMutex mu = createProcessMutex("abc1");
		TimeWatcher w = createTimeWatcher();
		w->start();
		mu->lock(100);
		long ret = w->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessMuex lock timeout case1,ret is %ld",ret);
		}
		
		w->start();
		mu->lock();
		ret = w->stop();
		if(ret < 295 || ret > 305) {
			TEST_FAIL("testProcessMuex lock timeout case2,ret is %ld",ret);
		}
		int status = 0;
		wait(&status);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
		ProcessMutex mu = createProcessMutex("abc1");
		AutoLock l(mu);
		usleep(1000*100);
		return -1;
	  } else {
		usleep(1000*150);
		ProcessMutex mu = createProcessMutex("abc1");
		TimeWatcher w = createTimeWatcher();
		w->start();
		mu->lock(100);
		auto ret = w->stop();
		if(ret  > 5) {
			TEST_FAIL("testProcessMuex lock timeout case3,ret is %ld",ret);
		}
		mu->unlock();
	  }
	  break;
  }
  TEST_OK("testProcessMuex lock timeout case100");
  return 0;
}
