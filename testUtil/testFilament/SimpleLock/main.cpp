#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaCroutine.hpp"
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

CountDownLatch latch = createCountDownLatch(2);
//Mutex mu = createMutex();
//Condition cond = createCondition();
FilaMutex mMutex = createFilaMutex();

int value = 0;

int main(void) {
    FilaCroutine croutine = createFilaCroutine();
    croutine->start();

    croutine->submit([] {
        //AutoLock l(mu);
        printf("start trace1 \n");
        mMutex->lock();
        printf("start trace2 \n");
        value++;
        usleep(1000*500);
        mMutex->unlock();
        printf("start trace3 \n");
    });

    
    usleep(1000*100);
    TimeWatcher watcher = createTimeWatcher();
    watcher->start();

    mMutex->lock();
    long ret = watcher->stop();
    if(ret < 400 || ret > 405) {
        TEST_FAIL("Filament simple lock case1");
    }

    TEST_OK("Filament simple lock case100");
  }
