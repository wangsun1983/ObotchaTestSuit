#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"
#include "ProcessMutex.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testProcessMutex() {
  int pid = fork();
  if(pid == 0) {
    ProcessMutex mu = createProcessMutex("abc");
    AutoLock l(mu);
    sleep(5);
    return;
  } else {
    ProcessMutex mu = createProcessMutex("abc");
    sleep(1);
    TimeWatcher w = createTimeWatcher();
    w->start();
    AutoLock l(mu);
    long ret = w->stop();
    if(ret < 3995 || ret > 4030) {
        TEST_FAIL("testProcessMutex case1,ret is %ld",ret);
    }
  }
  TEST_OK("testProcessMutex case100");
}
