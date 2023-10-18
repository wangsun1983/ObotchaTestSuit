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
#include "Thread.hpp"

using namespace obotcha;

int testNotifyAllInThread() {
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
			ProcessMutex mu = createProcessMutex("abc1");
			ProcessCondition cond = createProcessCondition("abc_cond1");
			TimeWatcher w = createTimeWatcher();
			w->start();
			Thread t1 = createThread([&] {
				AutoLock l(mu);
				cond->wait(mu,500);
				long ret = w->stop();				
				if(ret > 105 || ret < 95) {
					TEST_FAIL("testProcessCondition notifyAll in thread case1,ret is %ld",ret);
				}
				 
			});
			t1->start();
			
			Thread t2 = createThread([&] {
				AutoLock l(mu);
				cond->wait(mu,500);
				long ret = w->stop();
				if(ret > 105 || ret < 95) {
					TEST_FAIL("testProcessCondition notifyAll in thread case3,ret is %ld",ret);
				}				
			});
			t2->start();
			
			t1->join();
			t2->join();
	  }
	  break;
  }
  usleep(1000*500);
  
  while(1) {
	  ProcessMutex mu = createProcessMutex("abc1");
	  ProcessCondition cond = createProcessCondition("abc_cond1");
	  
	  Thread t1 = createThread([&]{
		  usleep(1000*100);
		  cond->notifyAll();
	  });
	  
	  Thread t2 = createThread([&]{
	  	TimeWatcher w = createTimeWatcher();
		w->start();
		AutoLock l(mu);
		cond->wait(mu);
		auto ret = w->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("testProcessCondition notifyAll in thread case4");
		}
	  });
	  
	  Thread t3 = createThread([&]{
	  	TimeWatcher w = createTimeWatcher();
	  		w->start();
	  		AutoLock l(mu);
	  		cond->wait(mu);
	  		auto ret = w->stop();
	  		if(ret < 95 || ret > 105) {
	  			TEST_FAIL("testProcessCondition notifyAll in thread case5");
	  		}
	  });
	  t2->start();
	  t3->start();
	  t1->start();
	  
	  t1->join();
	  t2->join();
	  t3->join();
	  break;
  }
  
  TEST_OK("testProcessCondition notifyAll in thread case100");
  return 0;
}
