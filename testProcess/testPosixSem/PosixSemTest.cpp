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

int main() {
 
  {
    ProcessSem sem = createProcessSem("sem_test1",0);
    sem->clear();

    ProcessSem sem2 = createProcessSem("sem_test2",0);
    sem2->clear();

    ProcessSem sem3 = createProcessSem("sem_test3",100);
    sem3->clear();
  }
  //wait()
  int pid = fork();
  if(pid == 0) {
      ProcessSem sem = createProcessSem("sem_test1",0);
      int ret = sem->wait();
      exit(0);
  } else {
      ProcessSem sem = createProcessSem("sem_test1",0);
      sleep(1);
      sem->post();
      TimeWatcher t = createTimeWatcher();
      t->start();
      wait(nullptr);//wait for child process
      long v = t->stop();
      if(v > 100) {
        TEST_FAIL("[ProcessSem Test {wait()} case1] v is %ld",v);
      }
      sem->clear();
      TEST_OK("[ProcessSem Test {wait()} case2]");
  }

  //wait(long)
  pid = fork();
  if(pid == 0) {
      ProcessSem sem = createProcessSem("sem_test2",0);
      sleep(1);
      int ret = sem->post();
      exit(0);
  } else {
      ProcessSem sem = createProcessSem("sem_test2",0);
      long current = st(System)::currentTimeMillis();
      sem->wait(500);
      long waittime = (st(System)::currentTimeMillis() - current);

      sem->clear();
      if(waittime > 505 || waittime <495) {
          TEST_FAIL("[ProcessSem Test {wait(long)} case1],waittime is %ld",waittime);
          return 1;
      }

      TEST_OK("[ProcessSem Test {wait(long)} case2]");
  }


  //int getValue();
  {
      auto sem3 = createProcessSem("sem_test3",0);
      sem3->post();
      if(sem3->getValue() != 1) {
        TEST_FAIL("[ProcessSem Test {getValue()} case1]");
      }
      TEST_OK("[ProcessSem Test {getValue()} case2]");
  }

}
