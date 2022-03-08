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

using namespace std;
using namespace obotcha;

CountDownLatch latch = createCountDownLatch(2);
//Mutex mu = createMutex();
//Condition cond = createCondition();
FilaCondition cond = createFilaCondition();

int value = 0;

int main(void) {
    FilaCroutine croutine = createFilaCroutine();
    croutine->start();

    croutine->submit([] {
        //AutoLock l(mu);
        cond->wait();
        value++;
        latch->countDown();
    });

    croutine->submit([] {
        //AutoLock l(mu);
        cond->wait();
        value++;
        latch->countDown();
    });


    Thread t = createThread([]{
        sleep(1);
        cond->notifyAll();
    });
    t->start();
    latch->await();
    if(value != 2) {
      TEST_FAIL("Filament Simple Notify case1");
    }


    TEST_OK("Filament simple lambda case100");
  }
