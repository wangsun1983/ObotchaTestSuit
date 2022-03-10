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

FilaMutex routineMutex = createFilaMutex();
CountDownLatch routinelatch = createCountDownLatch(2);

void testRoutineLock() {
  FilaRoutine croutine = createFilaRoutine();
  croutine->start();
  croutine->execute([]{
    routineMutex->lock();
    poll(NULL, 0, 500);
    routineMutex->unlock();
    routinelatch->countDown();
  });
  usleep(1000*100);

  croutine->execute([]{
    routineMutex->lock();
    poll(NULL, 0, 100);
    routineMutex->unlock();
    routinelatch->countDown();
  });

  routinelatch->await();
  TEST_OK("Filament Routine lock case1");
}
