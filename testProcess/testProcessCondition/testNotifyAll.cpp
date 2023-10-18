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

int testNotifyAll() {
  st(ProcessCondition)::Create("abc_cond1");
  st(ProcessMutex)::Create("abc1");
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
			ProcessMutex mu = createProcessMutex("abc1");
			ProcessCondition cond = createProcessCondition("abc_cond1");
			usleep(1000*200);
			cond->notifyAll();
			return -1;
	  } else {
		    usleep(1000*100);
		    int pid2 = fork();
			if(pid2 == 0) {
				ProcessMutex mu = createProcessMutex("abc1");
				ProcessCondition cond = createProcessCondition("abc_cond1");
				TimeWatcher w = createTimeWatcher();
				w->start();
				AutoLock l(mu);
				cond->wait(mu,500);
				long ret = w->stop();
				if(ret < 95 || ret > 105) {
					TEST_FAIL("testProcessCondition notifyAll case1,ret is %ld",ret);
				}
				return -1;
			} else {
				ProcessMutex mu = createProcessMutex("abc1");
				ProcessCondition cond = createProcessCondition("abc_cond1");
				TimeWatcher w = createTimeWatcher();
				w->start();
				AutoLock l(mu);
				cond->wait(mu,500);
				long ret = w->stop();
				if(ret < 95 || ret > 105) {
					TEST_FAIL("testProcessCondition notifyAll case2,ret is %ld",ret);
				}
			}
	  }
	  break;
  }
  usleep(1000*500);
  
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
		  ProcessMutex mu = createProcessMutex("abc1");
		  ProcessCondition cond = createProcessCondition("abc_cond1");
		  cond->notifyAll();
		  return -1;
	  } else {
		  usleep(1000*100);
		  ProcessMutex mu = createProcessMutex("abc1");
		  ProcessCondition cond = createProcessCondition("abc_cond1");
		  TimeWatcher w = createTimeWatcher();
		  w->start();
		  AutoLock l(mu);
		  cond->wait(mu,100);
		  long ret = w->stop();
		  if(ret < 95 || ret > 105) {
			  TEST_FAIL("testProcessCondition notifyAll case4,ret is %ld",ret);
		  }
	  }
	  break;
  }
  TEST_OK("testProcessCondition notifyAll case100");
  return 0;
}
