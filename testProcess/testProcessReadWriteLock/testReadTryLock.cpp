#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"
#include "ProcessReadWriteLock.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testReadTryLock() {
  st(ProcessReadWriteLock)::Create("abc4");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc4");
		AutoLock l(mu->getWriteLock());
		usleep(1000*300);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc4");
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		int ret = mu->getReadLock()->tryLock();
		auto cost = watcher->stop();
		if(cost > 5) {
			TEST_FAIL("testProcessReadWriteLock readtrylock test case1,ret is %d",cost);
		}
		if(ret >= 0) {
			TEST_FAIL("testProcessReadWriteLock readtrylock test case2,ret is %d",ret);
		}
		 
		watcher->start();
		ret = mu->getReadLock()->tryLock();
		cost = watcher->stop();
		if(cost > 5) {
			TEST_FAIL("testProcessReadWriteLock readtrylock test case3,cost is %d",cost);
		}
		if(ret >= 0) {
			TEST_FAIL("testProcessReadWriteLock readtrylock test case4,ret is %d",ret);
		}
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc4");
	  		int ret = mu->getReadLock()->tryLock();
			if(ret < 0) {
				TEST_FAIL("testProcessReadWriteLock readtrylock test case5,ret is %d",ret);
			}
	  		usleep(1000*200);
			mu->getReadLock()->unlock();
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc4");
	  		TimeWatcher watcher = createTimeWatcher();
	  		watcher->start();
	  		AutoLock l(mu->getWriteLock());
			auto cost = watcher->stop();
			if(cost > 105 || cost < 95) {
				TEST_FAIL("testProcessReadWriteLock readtrylock test case6,ret is %d",cost);
			}
			wait(nullptr);
	  }
	  break;
  }
  
  TEST_OK("testProcessReadWriteLock readtrylock test case100");
  return 0;
}
