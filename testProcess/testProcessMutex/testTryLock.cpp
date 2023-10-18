#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"
#include "ProcessMutex.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testTryLock() {
  st(ProcessMutex)::Create("abc1");
  int pid = fork();
  
  if(pid == 0) {
    ProcessMutex mu = createProcessMutex("abc1");
    mu->tryLock();
    usleep(1000*500);
	mu->unlock();
    return -1;
  } else {
	usleep(1000*100);
    TimeWatcher w1 = createTimeWatcher();
	ProcessMutex mu = createProcessMutex("abc1");
	w1->start();
	auto ret = mu->tryLock();
	auto cost = w1->stop();
	if(ret == 0) {
		TEST_FAIL("testProcessMutex trylock case1,ret is %d",ret);
	}
	
	if(cost > 5) {
		TEST_FAIL("testProcessMutex trylock case2,cost is %d",cost);
	}
	int status = 0;
	wait(&status);
  }
  TEST_OK("testProcessMutex trylock case100");
  return 0;
}
