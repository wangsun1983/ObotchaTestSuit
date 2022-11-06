#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "FilaExecutorResult.hpp"
#include "Uint32.hpp"

using namespace std;
using namespace obotcha;

void testFutureGetString() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(FilaExecutorResult)::set(createString("hello"));
        });
        
        usleep(1000*100);
        auto value = future->getResult<String>();
        if(!value->equals("hello")) {
            TEST_FAIL("Filament Future Get String case1,value is %s",value->toChars());
        }
        break;
    }

    TEST_OK("Filament Future Get String case100");
  }
