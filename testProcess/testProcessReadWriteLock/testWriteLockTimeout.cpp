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

int testWriteLockTimeout() {
  st(ProcessReadWriteLock)::Create("abc6");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc6");
		AutoLock l(mu->getReadLock());
		usleep(1000*300);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc6");
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		mu->getWriteLock()->lock(100);
		auto ret = watcher->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessReadWriteLock writelocktimeout test case1,ret is %d",ret);
		}
		
		watcher->start();
		mu->getWriteLock()->lock(50);
		ret = watcher->stop();
		if(ret < 45 || ret > 55) {
			TEST_FAIL("testProcessReadWriteLock writelocktimeout test case2,ret is %d",ret);
		}
		
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc6");
	  		AutoLock l1(mu->getReadLock());
			AutoLock l2(mu->getReadLock());
	  		usleep(1000*300);
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc6");
	  		TimeWatcher watcher = createTimeWatcher();
	  		watcher->start();
	  		mu->getWriteLock()->lock(100);
	  		auto ret = watcher->stop();
	  		if(ret < 95 || ret > 105) {
	  			TEST_FAIL("testProcessReadWriteLock writelocktimeout test case3,ret is %d",ret);
	  		}
			wait(nullptr);
	  }
	  break;
  }
  TEST_OK("testProcessReadWriteLock writelocktimeout test case100");
  return 0;
}
