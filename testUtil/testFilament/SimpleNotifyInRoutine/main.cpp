#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Inet4Address.hpp"
#include "NetPort.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Thread.hpp"
#include "FilaCondition.hpp"
#include "TimeWatcher.hpp"
#include "Fila.hpp"

using namespace std;
using namespace obotcha;

FilaMutex mm = createFilaMutex();
FilaCondition cond = createFilaCondition();
TimeWatcher watcher = createTimeWatcher();
CountDownLatch latch = createCountDownLatch(2);

int main(void) {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();

    croutine->execute([] {
        watcher->start();
        AutoLock l(mm);
        cond->wait(mm);
        long ret = watcher->stop();
        if(ret < 200 || ret > 205) {
          TEST_FAIL("SimpleNotifyInRoutine case1");
        }
        latch->countDown();
    });

    croutine->execute([] {
        //AutoLock l(mu);
        st(Fila)::sleep(200);
        cond->notify();
        latch->countDown();
    });

    TimeWatcher w2 = createTimeWatcher();
    w2->start();
    latch->await();
    long rs = w2->stop();
    if(rs < 200 || rs > 205) {
      TEST_FAIL("SimpleNotifyInRoutine case2");
    }

    TEST_OK("SimpleNotifyInRoutine case100");
  }
