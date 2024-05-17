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
#include "Thread.hpp"

using namespace obotcha;

int testThreadMutex() {
  st(ProcessMutex)::Create("abc2");
  while(1) {
	  int pid = fork();
	  if(pid == 0) {
		//printf("child process trace1 \n");
		ProcessMutex mu = ProcessMutex::New("abc2");
		AutoLock l(mu);
		//printf("child process trace2 \n");
		usleep(1000*500);
		//printf("child process trace3 \n");
		return -1;
	  } else {
		//usleep(1000*100);
		ProcessMutex mu = ProcessMutex::New("abc2");
		long firsthit = 0;
		long secondhit = 0;
		
		Thread t1 = Thread::New([&] {
			TimeWatcher watcher = TimeWatcher::New();
			watcher->start();
			AutoLock l(mu);
			if(firsthit == 0) {
				firsthit = watcher->stop();
			} else {
				secondhit = watcher->stop();
			}
			usleep(1000*100);
		});
		t1->start();
		
		Thread t2 = Thread::New([&] {
			TimeWatcher watcher = TimeWatcher::New();
			watcher->start();
			AutoLock l(mu);
			if(firsthit == 0) {
				firsthit = watcher->stop();
			} else {
				secondhit = watcher->stop();
			}
			usleep(1000*100);
		});
		t2->start();
		
		t1->join();
		t2->join();
		if(firsthit > 505 || firsthit < 495) {
			TEST_FAIL("testProcessMutex lock in thread case1,r is %ld",firsthit);
		}
		
		if(secondhit > 605 || secondhit < 595) {
			TEST_FAIL("testProcessMutex lock in thread case2,r is %ld",secondhit);
		}
		int status = 0;
		wait(&status);
	  }
	  break;
  }
  
  while(1) {
	  ProcessMutex mu = ProcessMutex::New("abc2");
	  AutoLock l(mu);
	  TimeWatcher watcher = TimeWatcher::New();
	  watcher->start();
	  mu->lock(100);
	  auto ret = watcher->stop();
	  if(ret > 5) {
		  TEST_FAIL("testProcessMutex lock in thread case3,ret is %ld",ret);
	  }
	  mu->unlock();
	  break;
  }
  
  while(1) {
  	  ProcessMutex mu = ProcessMutex::New("abc2");
	  int count = 0;
	  ArrayList<Thread> list = ArrayList<Thread>::New();
	  
	  for(int i = 0;i<256;i++) {
		  Thread t1 = Thread::New([&]{
		  		  AutoLock l1(mu);
		  		  AutoLock l2(mu);
		  		  AutoLock l3(mu);
		  		  AutoLock l4(mu);
		  		  count++;
		  });
		  list->add(t1);
		  t1->start();
	  }
  	  
	  for(int i = 0;i<256;i++) {
		  list->get(i)->join();
	  }
	  
	  if(count != 256) {
		  TEST_FAIL("testProcessMutex lock in thread case4,count is %ld",count);
	  }
  	  break;
  }
  
  TEST_OK("testProcessMutex lock in thread case100");
  return 0;
}
