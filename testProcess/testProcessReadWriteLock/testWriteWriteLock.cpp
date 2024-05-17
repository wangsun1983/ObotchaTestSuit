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

int testWriteWriteLock() {
  st(ProcessReadWriteLock)::Create("abc9");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc9");
		AutoLock l(mu->getWriteLock());
		usleep(1000*200);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc9");
		TimeWatcher watcher = TimeWatcher::New();
		watcher->start();
		AutoLock l(mu->getWriteLock());
		auto ret = watcher->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessReadWriteLock writewritelock test case1,ret is %d",ret);
		}
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc9");
	  		AutoLock l1(mu->getWriteLock());
			AutoLock l2(mu->getWriteLock());
	  		usleep(1000*200);
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc9");
	  		TimeWatcher watcher = TimeWatcher::New();
	  		watcher->start();
	  		AutoLock l(mu->getWriteLock());
	  		auto ret = watcher->stop();
	  		if(ret < 95 || ret > 105) {
	  			TEST_FAIL("testProcessReadWriteLock writewritelock test case2,ret is %d",ret);
	  		}
			wait(nullptr);
	  }
	  break;
  }
  TEST_OK("testProcessReadWriteLock writewritelock test case100");
  return 0;
}
