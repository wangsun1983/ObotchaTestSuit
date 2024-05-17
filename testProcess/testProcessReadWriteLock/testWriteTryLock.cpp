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

int testWriteTryLock() {
  st(ProcessReadWriteLock)::Create("abc8");
  while(1) {
	  int pid = fork();
	  
	  if(pid == 0) {
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc8");
		AutoLock l(mu->getReadLock());
		usleep(1000*300);
		return -1;
	  } else {
		usleep(1000*100);
		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc8");
		TimeWatcher watcher = TimeWatcher::New();
		watcher->start();
		int ret = mu->getWriteLock()->tryLock();
		auto cost = watcher->stop();
		if(cost > 5) {
			TEST_FAIL("testProcessReadWriteLock writetrylock test case1,ret is %d",cost);
		}
		if(ret >= 0) {
			TEST_FAIL("testProcessReadWriteLock writetrylock test case2,ret is %d",ret);
		}
		 
		watcher->start();
		ret = mu->getWriteLock()->tryLock();
		cost = watcher->stop();
		if(cost > 5) {
			TEST_FAIL("testProcessReadWriteLock writetrylock test case3,cost is %d",cost);
		}
		if(ret >= 0) {
			TEST_FAIL("testProcessReadWriteLock writetrylock test case4,ret is %d",ret);
		}
		int status = 0;
		wait(&status);
	  }
	  break;
  }
  //usleep(1000*300);
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc8");
	  		int ret = mu->getWriteLock()->tryLock();
			if(ret < 0) {
				TEST_FAIL("testProcessReadWriteLock writetrylock test case5,ret is %d",ret);
			}
	  		usleep(1000*200);
			mu->getWriteLock()->unlock();
	  		return -1;
	  } else {
	  		usleep(1000*100);
	  		ProcessReadWriteLock mu = ProcessReadWriteLock::New("abc8");
	  		TimeWatcher watcher = TimeWatcher::New();
	  		watcher->start();
	  		AutoLock l(mu->getReadLock());
			auto cost = watcher->stop();
			if(cost > 105 || cost < 95) {
				TEST_FAIL("testProcessReadWriteLock writetrylock test case6,ret is %d",cost);
			}
			wait(nullptr);
	  }
	  break;
  }
  
  TEST_OK("testProcessReadWriteLock writetrylock test case100");
  return 0;
}
