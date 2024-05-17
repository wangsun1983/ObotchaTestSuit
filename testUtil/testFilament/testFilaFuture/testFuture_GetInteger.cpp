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

CountDownLatch sleepLatch = CountDownLatch::New(1);

DECLARE_CLASS(MyFutureTask) IMPLEMENTS(Filament){
public:
    void run() {
      usleep(1000*100);
      st(FilaExecutorResult)::Set(Integer::New(100));
    }
};

void testFutureGetInteger() {
    FilaRoutine croutine = FilaRoutine::New();
    croutine->start();
    TimeWatcher watcher = TimeWatcher::New();
    FilaFuture f = croutine->submit(MyFutureTask::New());
    watcher->start();
    Integer v = f->getResult<Integer>();
    long ret = watcher->stop();
    if(ret < 95 || ret > 105) {
      TEST_FAIL("Filament Simple Future case1,ret is %ld \n",ret);
    }

    if(v == nullptr || v->toValue() != 100) {
      TEST_FAIL("Filament Simple Future case2");
    }

    TEST_OK("Filament Simple Future case100");
  }
