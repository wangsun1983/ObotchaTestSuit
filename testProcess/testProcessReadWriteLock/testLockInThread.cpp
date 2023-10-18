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
#include "Thread.hpp"

using namespace obotcha;

int testLockInThread() {
  st(ProcessReadWriteLock)::Create("abc10");
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
		AutoLock l(mu->getReadLock());
		usleep(1000*200);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
		Thread t1 = createThread([&]{
			TimeWatcher watcher = createTimeWatcher();
			watcher->start();
			AutoLock l(mu->getWriteLock());
			auto ret = watcher->stop();
			if(ret > 105 || ret < 95) {
				TEST_FAIL("testProcessReadWriteLock lockinthread test case1,ret is %d",ret);
			}
		});
		t1->start();
		t1->join();
		wait(nullptr);
	  }
	  break;
  }
  
  while(1) {
  	  int pid = fork();
  	  if(pid == 0) {
  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
  		AutoLock l(mu->getWriteLock());
  		usleep(1000*200);
  		return -1;
  	  } else {
  		usleep(1000*100);
  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
  		Thread t1 = createThread([&]{
  			TimeWatcher watcher = createTimeWatcher();
  			watcher->start();
  			AutoLock l(mu->getReadLock());
  			auto ret = watcher->stop();
  			if(ret > 105 || ret < 95) {
  				TEST_FAIL("testProcessReadWriteLock lockinthread test case2,ret is %d",ret);
  			}
  		});
  		t1->start();
  		t1->join();
  		wait(nullptr);
  	  }
  	  break;
  }
  
  while(1) {
  	  int pid = fork();
  	  if(pid == 0) {
  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
		Thread t1 = createThread([&]{
			AutoLock l(mu->getWriteLock());
			usleep(1000*200);
		});
  		t1->start();
		t1->join();
  		return -1;
  	  } else {
  		usleep(1000*100);
  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
  		Thread t1 = createThread([&]{
  			TimeWatcher watcher = createTimeWatcher();
  			watcher->start();
  			AutoLock l(mu->getReadLock());
  			auto ret = watcher->stop();
  			if(ret > 105 || ret < 95) {
  				TEST_FAIL("testProcessReadWriteLock lockinthread test case3,ret is %d",ret);
  			}
  		});
  		t1->start();
  		t1->join();
  		wait(nullptr);
  	  }
  	  break;
  }
  
  while(1) {
  	  int pid = fork();
  	  if(pid == 0) {
  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
  		Thread t1 = createThread([&]{
  			AutoLock l(mu->getReadLock());
  			usleep(1000*200);
  		});
  		t1->start();
  		t1->join();
  		return -1;
  	  } else {
  		usleep(1000*100);
  		ProcessReadWriteLock mu = createProcessReadWriteLock("abc10");
  		Thread t1 = createThread([&]{
  			TimeWatcher watcher = createTimeWatcher();
  			watcher->start();
  			AutoLock l(mu->getWriteLock());
  			auto ret = watcher->stop();
  			if(ret > 105 || ret < 95) {
  				TEST_FAIL("testProcessReadWriteLock lockinthread test case3,ret is %d",ret);
  			}
  		});
  		t1->start();
  		t1->join();
  		wait(nullptr);
  	  }
  	  break;
  }
  
  TEST_OK("testProcessReadWriteLock lockinthread test case100");
  return 0;
}
