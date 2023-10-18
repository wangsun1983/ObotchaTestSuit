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

int testReadLockTimeout() {
  st(ProcessReadWriteLock)::Create("abc2");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc2");
		AutoLock l(mu->getWriteLock());
		usleep(1000*300);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc2");
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		mu->getReadLock()->lock(100);
		auto ret = watcher->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessReadWriteLock readlocktimeout test case1,ret is %d",ret);
		}
		
		watcher->start();
		mu->getReadLock()->lock(50);
		ret = watcher->stop();
		if(ret < 45 || ret > 55) {
			TEST_FAIL("testProcessReadWriteLock readlocktimeout test case2,ret is %d",ret);
		}
		int status = 0;
		wait(&status);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc2");
	  		AutoLock l1(mu->getWriteLock());
			AutoLock l2(mu->getWriteLock());
	  		usleep(1000*300);
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc2");
	  		TimeWatcher watcher = createTimeWatcher();
	  		watcher->start();
	  		mu->getReadLock()->lock(100);
	  		auto ret = watcher->stop();
	  		if(ret < 95 || ret > 105) {
	  			TEST_FAIL("testProcessReadWriteLock readlocktimeout test case3,ret is %d",ret);
	  		}
			wait(nullptr);
	  }
	  break;
  }
  TEST_OK("testProcessReadWriteLock readlocktimeout test case100");
  return 0;
}
