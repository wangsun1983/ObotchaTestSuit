#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"
#include "ProcessReadWriteLock.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testProcessReadWriteLock() {
  int pid = fork();
  
  if(pid == 0) {
    ProcessReadWriteLock mu = createProcessReadWriteLock("./abc");
    AutoLock l(mu->getReadLock());
    sleep(5);
    exit(0);
  } else {
    ProcessReadWriteLock mu = createProcessReadWriteLock("./abc");
    sleep(1);
    TimeWatcher w = createTimeWatcher();
    w->start();
    AutoLock l(mu->getReadLock());
    long ret = w->stop();
    if(ret < 0 || ret > 5) {
        TEST_FAIL("testProcessReadWriteLock case1,ret is %ld",ret);
    }
    printf("ttt \n");
  }
  sleep(6);

  pid = fork();
  if(pid == 0) {
    ProcessReadWriteLock mu = createProcessReadWriteLock("./abc");
    printf("start getWriteLock \n");
    AutoLock l(mu->getWriteLock());
    printf("start getWriteLock trace1\n");
    sleep(5);
    exit(0);
  } else {
    ProcessReadWriteLock mu = createProcessReadWriteLock("./abc");
    sleep(1);
    TimeWatcher w = createTimeWatcher();
    w->start();
    printf("start getReadLock \n");
    AutoLock l(mu->getReadLock());
    printf("start finish ReadLock \n");
    long ret = w->stop();
    if(ret < 3995 || ret > 4050) {
        TEST_FAIL("testProcessReadWriteLock case2,ret is %ld",ret);
    }
  }
  TEST_OK("testProcessMutex case100");
}
