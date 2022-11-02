#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"

using namespace std;
using namespace obotcha;

FilaMutex threadMutex = createFilaMutex();
CountDownLatch threadlatch = createCountDownLatch(1);

void testRoutineLockInThread() {
  FilaRoutine croutine = createFilaRoutine();
  croutine->start();
  croutine->execute([]{
    poll(NULL,0,100);
    TimeWatcher watcher = createTimeWatcher();
    watcher->start();
    AutoLock l(threadMutex);
    long rs = watcher->stop();
    if(rs < 395 || rs > 405) {
      TEST_FAIL("Filament Routine lock in thread case1,rs is %ld",rs);
    } else {
      TEST_OK("Filament Routine lock in thread case2");
    }
    threadlatch->countDown();
  });
  
  TimeWatcher mywatcher = createTimeWatcher();
  mywatcher->start();
  int isRun = 0;
  croutine->execute([&mywatcher,&isRun]{
    poll(NULL,0,200);
    isRun = 1;
    long rs = mywatcher->stop();
    if(rs < 200 || rs > 205) {
      TEST_FAIL("Filament Routine lock in thread case2,rs is %ld",rs);
    } else {
      TEST_OK("Filament Routine lock in thread case3");
    }
    threadlatch->countDown();
  });

  Thread t = createThread([]{
    AutoLock l(threadMutex);
    usleep(1000*500);
  });
  t->start();

  threadlatch->await();
  
  if(isRun == 0) {
    TEST_FAIL("Filament Routine lock in thread case4");
  }
  TEST_OK("Filament Routine lock in thread case100");
}
