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

int testReadReadLock() {
  st(ProcessReadWriteLock)::Create("abc3");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc3");
		AutoLock l(mu->getReadLock());
		usleep(1000*200);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc3");
		TimeWatcher watcher = TimeWatcher::New();
		watcher->start();
		AutoLock l(mu->getReadLock());
		auto ret = watcher->stop();
		if(ret > 5) {
			TEST_FAIL("testProcessReadWriteLock readreadlock test case1,ret is %d",ret);
		}
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc3");
	  		AutoLock l1(mu->getReadLock());
			AutoLock l2(mu->getReadLock());
	  		usleep(1000*200);
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc3");
	  		TimeWatcher watcher = TimeWatcher::New();
	  		watcher->start();
	  		AutoLock l(mu->getReadLock());
	  		auto ret = watcher->stop();
	  		if(ret > 5) {
	  			TEST_FAIL("testProcessReadWriteLock readreadlock test case2,ret is %d",ret);
	  		}
	  		wait(nullptr);
	  }
	  break;
  }
  TEST_OK("testProcessReadWriteLock readreadlock test case100");
  return 0;
}
