#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <wait.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"
#include "ProcessMutex.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "ProcessCondition.hpp"


using namespace obotcha;

int testWaitTimeout() {
  st(ProcessCondition)::Create("abc_cond1");
  st(ProcessMutex)::Create("abc1");
  
  while(1) {
	ProcessCondition cond = ProcessCondition::New("abc_cond1");
	ProcessMutex mu = ProcessMutex::New("abc1");
	TimeWatcher w = TimeWatcher::New();
	AutoLock l(mu);
	w->start();
	cond->wait(mu,100);
	auto ret = w->stop();
	if(ret < 95 || ret > 105) {
		TEST_FAIL("testProcessCondition wait timeout case1,ret is %d",ret);
	}
	break;
  }
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
			ProcessMutex mu = ProcessMutex::New("abc1");
			ProcessCondition cond = ProcessCondition::New("abc_cond1");
			usleep(1000*200);
			cond->notify();
			return -1;
	  } else {
			usleep(1000*100);
			ProcessMutex mu = ProcessMutex::New("abc1");
			ProcessCondition cond = ProcessCondition::New("abc_cond1");
			TimeWatcher w = TimeWatcher::New();
			w->start();
			AutoLock l(mu);
			cond->wait(mu,500);
			long ret = w->stop();
			if(ret < 95 || ret > 105) {
				TEST_FAIL("testProcessCondition wait timeout case2,ret is %ld",ret);
			}
	  }
	  break;
  }
  
  TEST_OK("testProcessCondition wait timeout case100");
  return 0;
}
