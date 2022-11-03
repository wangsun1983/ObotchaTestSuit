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

void testFutureGetUint32() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(FilaExecutorResult)::set<uint32_t>(123);
        });
        
        usleep(1000*100);
        uint32_t value = future->getResult<uint32_t>();
        if(value != 123) {
            TEST_FAIL("Filament Future Get uint32 case1,value is %d",value);
        }
        break;
    }

    TEST_OK("Filament Future Get uint32 case100");
  }
