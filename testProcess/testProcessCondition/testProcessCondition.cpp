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

int testProcessCondition() {
  st(ProcessCondition)::Create("abc_cond1");
  st(ProcessMutex)::Create("abc");
  int pid = fork();
  if(pid == 0) {
    ProcessCondition cond = ProcessCondition::New("abc_cond1");
    sleep(3);
    cond->notifyAll();
    return -1;
  } else {
    pid = fork();

    if(pid == 0) {
      ProcessCondition cond = ProcessCondition::New("abc_cond1");
      ProcessMutex mu = ProcessMutex::New("abc");
      TimeWatcher w = TimeWatcher::New();
      w->start();
      AutoLock l(mu);
      cond->wait(mu);
      long ret = w->stop();
      if(ret < 2995 || ret > 3050) {
          TEST_FAIL("testProcessCondition case1,ret is %ld",ret);
      }

      TEST_OK("testProcessCondition Child Process case1_1 ");
      return -1;
    } else {
      ProcessCondition cond = ProcessCondition::New("abc_cond1");
      ProcessMutex mu = ProcessMutex::New("abc");
      TimeWatcher w = TimeWatcher::New();
      w->start();
      AutoLock l(mu);
      cond->wait(mu);
      long ret = w->stop();
      if(ret < 2995 || ret > 3050) {
          TEST_FAIL("testProcessCondition case2,ret is %ld",ret);
      }
      ::wait(nullptr);
      TEST_OK("testProcessCondition case3");
    }
    
  }
  TEST_OK("testProcessCondition case100");
  return 0;
}
