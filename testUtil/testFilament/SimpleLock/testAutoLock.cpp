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

FilaMutex autoLockMutex = FilaMutex::New();
CountDownLatch autoLocklatch = CountDownLatch::New(2);

void testAutoLock() {
  FilaRoutine croutine = FilaRoutine::New();
  croutine->start();
  croutine->execute([]{
    AutoLock l(autoLockMutex);
    poll(NULL, 0, 500);
    autoLocklatch->countDown();
  });
  usleep(1000*100);

  croutine->execute([]{
    TimeWatcher watcher1 = TimeWatcher::New();
    watcher1->start();
    AutoLock l(autoLockMutex);
    long rs = watcher1->stop();
    if(rs < 395 || rs > 415) {
      TEST_FAIL("Filament Routine auto lock case1,rs is %ld",rs);
    }
    poll(NULL, 0, 100);
    autoLocklatch->countDown();
  });

  TimeWatcher watcher = TimeWatcher::New();
  watcher->start();
  autoLocklatch->await();
  long rs = watcher->stop();

  if(rs < 495 || rs > 515) {
    TEST_FAIL("Filament Routine auto lock case2,rs is %ld",rs);
  }

  TEST_OK("Filament Routine auto lock case100");
}
