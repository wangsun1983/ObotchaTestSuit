#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "Fila.hpp"

using namespace std;
using namespace obotcha;

CountDownLatch sleepLatch = createCountDownLatch(1);

void testOnComplete() {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();
    croutine->execute([]{
      st(Fila)::sleep(300);
    });

    croutine->execute([]{
      st(Fila)::sleep(200);
      sleepLatch->countDown();
    });

    usleep(1000*100);
    if(croutine->getFilamentSize() != 2) {
      TEST_OK("Filament Simple onComplete case1");
    }
    usleep(1000*300);
    if(croutine->getFilamentSize() != 0) {
      TEST_OK("Filament Simple onComplete case2");
    }
    TEST_OK("Filament Simple onComplete case100");
  }
