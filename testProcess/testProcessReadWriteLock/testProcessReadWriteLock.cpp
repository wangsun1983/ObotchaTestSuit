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
#include <sys/wait.h>

using namespace obotcha;

int testProcessReadWriteLock() {
  st(ProcessReadWriteLock)::Create("abc");
  int pid = fork();
  
  if(pid == 0) {
    ProcessReadWriteLock mu = createProcessReadWriteLock("abc");
    AutoLock l(mu->getReadLock());
    sleep(5);
    return -1;
  } else {
    ProcessReadWriteLock mu = createProcessReadWriteLock("abc");
    sleep(1);
    TimeWatcher w = createTimeWatcher();
    w->start();
    AutoLock l(mu->getReadLock());
    long ret = w->stop();
    if(ret < 0 || ret > 5) {
        TEST_FAIL("testProcessReadWriteLock case1,ret is %ld",ret);
    }
	wait(nullptr);
  }
  sleep(6);

  pid = fork();
  if(pid == 0) {
    ProcessReadWriteLock mu = createProcessReadWriteLock("abc");
    mu->getWriteLock()->lock();
    sleep(5);
	int ret = mu->getWriteLock()->unlock();
	return -1;
  } else {
    ProcessReadWriteLock mu = createProcessReadWriteLock("abc");
    sleep(1);
    TimeWatcher w = createTimeWatcher();
    w->start();
    AutoLock l(mu->getReadLock());
    long ret = w->stop();
    if(ret < 3995 || ret > 4050) {
        TEST_FAIL("testProcessReadWriteLock case2,ret is %ld",ret);
    }
	wait(nullptr);
  }
  TEST_OK("testProcessMutex case100");
  return 0;
}
