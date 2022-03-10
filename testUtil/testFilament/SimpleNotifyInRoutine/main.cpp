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

using namespace std;
using namespace obotcha;

FilaCondition cond = createFilaCondition();
TimeWatcher watcher = createTimeWatcher();
CountDownLatch latch = createCountDownLatch(2);

int main(void) {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();

    croutine->execute([] {
        watcher->start();
        cond->wait();
        long ret = watcher->stop();
        if(ret < 200 || ret > 205) {
          TEST_FAIL("SimpleNotifyInRoutine case1");
        }
        latch->countDown();
    });

    croutine->execute([] {
        //AutoLock l(mu);
        filaSleep(200);
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
