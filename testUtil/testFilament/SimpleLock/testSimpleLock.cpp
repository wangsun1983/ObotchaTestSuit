#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "FilaCondition.hpp"

using namespace std;
using namespace obotcha;

FilaMutex mMutex = createFilaMutex();
CountDownLatch latch = createCountDownLatch(1);

void testSimpleLock() {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();
    croutine->execute([]{
      mMutex->lock();
      usleep(1000*500);
      mMutex->unlock();
      latch->countDown();
    });

    usleep(1000*100);
    TimeWatcher watcher = createTimeWatcher();
    watcher->start();
    mMutex->lock();
    long ret = watcher->stop();
    if(ret < 400 || ret > 405) {
      TEST_FAIL("Filament Simple lock case1");
    }
    latch->await();
    TEST_OK("Filament Simple lock case100");
  }
