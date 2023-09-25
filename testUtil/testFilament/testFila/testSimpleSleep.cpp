#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "Fila.hpp"
#include "TimeWatcher.hpp"

using namespace std;
using namespace obotcha;

CountDownLatch sleepLatch = createCountDownLatch(1);

void testSimpleSleep() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        int runCount = 0;
        croutine->execute([&runCount]{
          TimeWatcher watcher = createTimeWatcher();
          watcher->start();
          st(Fila)::Sleep(100);
          long v = watcher->stop();
          if(v < 95 || v > 105) {
            TEST_FAIL("Filament test sleep case1");
          }
          runCount++;
        });

        croutine->execute([&runCount]{
          TimeWatcher watcher = createTimeWatcher();
          watcher->start();
          st(Fila)::Sleep(200);
          long v = watcher->stop();
          if(v < 195 || v > 205) {
            TEST_FAIL("Filament test sleep case2");
          }
          runCount++;
        });

        usleep(1000*300);
        if(runCount != 2) {
          TEST_FAIL("Filament test sleep case3,runCount is %d",runCount);
        }
        break;
    }
    
    while(1) {
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        st(Fila)::Sleep(100);
        auto v = watcher->stop();
        
        if(v < 95 || v > 105) {
            TEST_FAIL("Filament test sleep case4");
        }
        break;
    }
    
    TEST_OK("Filament test sleep case100");
  }
