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

int testProcessMutex() {
  st(ProcessMutex)::Create("abc1");
  int pid = fork();
  
  if(pid == 0) {
    ProcessMutex mu = ProcessMutex::New("abc1");
    AutoLock l(mu);
    usleep(1000*500);
    return -1;
  } else {
    ProcessMutex mu = ProcessMutex::New("abc1");
    usleep(1000*100);
    TimeWatcher w = TimeWatcher::New();
    w->start();
    AutoLock l(mu);
    long ret = w->stop();
    if(ret < 395 || ret > 405) {
        TEST_FAIL("testProcessMutex case1,ret is %ld",ret);
    }
	
	int status = 0;
	wait(&status);
  }
  TEST_OK("testProcessMutex case100");
  return 0;
}
