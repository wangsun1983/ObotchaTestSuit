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

using namespace std;
using namespace obotcha;

CountDownLatch latch = createCountDownLatch(2);
//Mutex mu = createMutex();
//Condition cond = createCondition();
FilaCondition cond = createFilaCondition();
FilaMutex mu = createFilaMutex();

int value = 0;

int main(void) {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();

    croutine->execute([] {
        AutoLock l(mu);
        printf("c1 start wait\n");
        cond->wait(mu);
        printf("c1 finish wait\n");
        value++;
        latch->countDown();
    });

    croutine->execute([] {
        printf("c2222 start wait\n");
        AutoLock l(mu);
        printf("c2 start wait\n");
        cond->wait(mu);
        printf("c2 finish wait\n");
        value++;
        latch->countDown();
    });

    Thread t = createThread([]{
        sleep(1);
        printf("start notify all \n");
        cond->notifyAll();
        printf("finish notify all \n");
    });

    t->start();
    latch->await();
    if(value != 2) {
      TEST_FAIL("Filament Simple Notify case1");
    }


    TEST_OK("Filament simple lambda case100");
  }
