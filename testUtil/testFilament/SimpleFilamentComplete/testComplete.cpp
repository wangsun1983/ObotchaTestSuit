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

void testOnComplete() {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();
    printf("trace1 \n");
    croutine->execute([]{
      filaSleep(300);
      printf("trace1_1 \n");
    });

    croutine->execute([]{
      filaSleep(200);
      sleepLatch->countDown();
      printf("trace1_2 \n");
    });

    printf("trace2 \n");
    usleep(1000*100);
    if(croutine->getFilamentSize() != 2) {
      TEST_OK("Filament Simple onComplete case1");
    }
    printf("trace3 \n");
    usleep(1000*300);
    printf("trace3_1 \n");
    if(croutine->getFilamentSize() != 0) {
      TEST_OK("Filament Simple onComplete case2");
    }
    printf("trace4 \n");
    TEST_OK("Filament Simple onComplete case100");
  }
