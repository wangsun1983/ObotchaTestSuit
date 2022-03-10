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
      usleep(1000*100);
      printf("routine start notify \n");
      cond->notify();
      printf("routine finish notify \n");
    });

    Thread t = createThread([]{
      printf("thread start wait \n");
      cond->wait();
      printf("thread finish wait \n");
    });
    t->start();

    TEST_OK("SimpleNotifyInThread case100");
  }
