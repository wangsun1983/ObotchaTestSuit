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

int testReadWriteLock() {
  st(ProcessReadWriteLock)::Create("abc5");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc5");
		AutoLock l(mu->getReadLock());
		usleep(1000*200);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc5");
		TimeWatcher watcher = TimeWatcher::New();
		watcher->start();
		AutoLock l(mu->getWriteLock());
		auto ret = watcher->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessReadWriteLock readwritelock test case1,ret is %d",ret);
		}
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc5");
	  		AutoLock l1(mu->getReadLock());
			AutoLock l2(mu->getReadLock());
	  		usleep(1000*200);
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc5");
	  		TimeWatcher watcher = TimeWatcher::New();
	  		watcher->start();
	  		AutoLock l(mu->getWriteLock());
	  		auto ret = watcher->stop();
	  		if(ret < 95 || ret > 105) {
	  			TEST_FAIL("testProcessReadWriteLock readwritelock test case2,ret is %d",ret);
	  		}
	  		wait(nullptr);
	  }
	  break;
  }
  TEST_OK("testProcessReadWriteLock readwritelock test case100");
  return 0;
}
