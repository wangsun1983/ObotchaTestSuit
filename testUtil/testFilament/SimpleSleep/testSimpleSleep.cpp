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

CountDownLatch sleepLatch = createCountDownLatch(1);

void testSimpleSleep() {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();
    croutine->execute([]{
      filaSleep(800);

    });

    croutine->execute([]{
      filaSleep(200);
      sleepLatch->countDown();
    });

    usleep(1000*100);
    TimeWatcher watcher = createTimeWatcher();
    watcher->start();
    sleepLatch->await();
    long ret = watcher->stop();
    if(ret < 100 || ret > 105) {
      TEST_FAIL("Filament Simple sleep case1");
    }

    TEST_OK("Filament Simple sleep case100");
  }
