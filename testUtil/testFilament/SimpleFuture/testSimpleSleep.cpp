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

DECLARE_CLASS(MyFutureTask) IMPLEMENTS(Filament){
public:
    void run() {
      usleep(1000*100);
      st(FilaFuture)::setResult(createInteger(100));
    }
};

void testSimpleFuture() {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();
    TimeWatcher watcher = createTimeWatcher();
    FilaFuture f = croutine->submit(createMyFutureTask());
    watcher->start();
    Integer v = f->getResult<Integer>();
    long ret = watcher->stop();
    if(ret < 95 || ret > 105) {
      TEST_FAIL("Filament Simple sleep case1,ret is %ld \n",ret);
    }

    if(v == nullptr || v->toValue() != 100) {
      TEST_FAIL("Filament Simple sleep case2");
    }
    TEST_OK("Filament Simple sleep case100");
  }
