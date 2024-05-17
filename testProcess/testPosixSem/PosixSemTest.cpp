#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ProcessSem.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int normalTest() {
 
  // {
  //   ProcessSem sem = ProcessSem::New("sem_test1",0);
  //   sem->clear();

  //   ProcessSem sem2 = ProcessSem::New("sem_test2",0);
  //   sem2->clear();

  //   ProcessSem sem3 = ProcessSem::New("sem_test3",100);
  //   sem3->clear();
  // }
  //wait()
  st(ProcessSem)::Create("sem_test1");
  int pid = fork();
  if(pid == 0) {
      ProcessSem sem = ProcessSem::New("sem_test1");
      int ret = sem->wait();
      exit(0);
  } else {
      ProcessSem sem = ProcessSem::New("sem_test1");
      sleep(1);
      sem->post();
      TimeWatcher t = TimeWatcher::New();
      t->start();
      wait(nullptr);//wait for child process
      long v = t->stop();
      if(v > 100) {
        TEST_FAIL("[ProcessSem Test {wait()} case1] v is %ld",v);
      }
      //sem->clear();
      TEST_OK("[ProcessSem Test {wait()} case2]");
  }

  //wait(long)
  st(ProcessSem)::Create("sem_test2",0);
  pid = fork();
  if(pid == 0) {
      ProcessSem sem = ProcessSem::New("sem_test2");
      sleep(1);
      int ret = sem->post();
      exit(0);
  } else {
      ProcessSem sem = ProcessSem::New("sem_test2");
      long current = st(System)::CurrentTimeMillis();
      sem->wait(500);
      long waittime = (st(System)::CurrentTimeMillis() - current);

      //sem->clear();
      if(waittime > 505 || waittime <495) {
          TEST_FAIL("[ProcessSem Test {wait(long)} case1],waittime is %ld",waittime);
          return 1;
      }

      TEST_OK("[ProcessSem Test {wait(long)} case2]");
  }


  //int getValue();
  {
	  st(ProcessSem)::Create("sem_test3",0);
      auto sem3 = ProcessSem::New("sem_test3");
      sem3->post();
      if(sem3->getValue() != 1) {
        TEST_FAIL("[ProcessSem Test {getValue()} case1]");
      }
      TEST_OK("[ProcessSem Test {getValue()} case2]");
  }
  return 0;
}
