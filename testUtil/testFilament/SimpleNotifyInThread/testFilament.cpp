#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Inet4Address.hpp"
#include "NetPort.hpp"
#include "Socket.hpp"
#include "SocketBuilder.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Thread.hpp"
#include "FilaCondition.hpp"
#include "TimeWatcher.hpp"
#include "System.hpp"

using namespace std;
using namespace obotcha;

FilaMutex fmutex = createFilaMutex();
FilaCondition cond = createFilaCondition();
TimeWatcher watcher = createTimeWatcher();
CountDownLatch latch = createCountDownLatch(2);

int main(void) {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();

    croutine->execute([] {
      usleep(1000*200);
      AutoLock l(fmutex);
      cond->notify();
      latch->countDown();
    });

    Thread t = createThread([]{
      AutoLock l(fmutex);
      cond->wait(fmutex);
      latch->countDown();
    });
    t->start();
    usleep(1000*100);

    TimeWatcher watcher = createTimeWatcher();
    watcher->start();
    latch->await();
    long rs = watcher->stop();
    if(rs < 95 || rs > 105) {
      TEST_FAIL("SimpleNotifyInThread case1");
    }

    TEST_OK("SimpleNotifyInThread case100");
  }
