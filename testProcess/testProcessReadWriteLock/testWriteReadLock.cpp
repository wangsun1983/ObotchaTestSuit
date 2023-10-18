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

int testWriteReadLock() {
  st(ProcessReadWriteLock)::Create("abc7");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc7");
		AutoLock l(mu->getWriteLock());
		usleep(1000*200);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc7");
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		AutoLock l(mu->getReadLock());
		auto ret = watcher->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessReadWriteLock writereadlock test case1,ret is %d",ret);
		}
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc7");
	  		AutoLock l1(mu->getWriteLock());
			AutoLock l2(mu->getWriteLock());
	  		usleep(1000*200);
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc7");
	  		TimeWatcher watcher = createTimeWatcher();
	  		watcher->start();
	  		AutoLock l(mu->getReadLock());
	  		auto ret = watcher->stop();
	  		if(ret < 95 || ret > 105) {
	  			TEST_FAIL("testProcessReadWriteLock writereadlock test case2,ret is %d",ret);
	  		}
	  		wait(nullptr);
	  }
	  break;
  }
  TEST_OK("testProcessReadWriteLock writereadlock test case100");
  return 0;
}
