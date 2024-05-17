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

DECLARE_CLASS(MyData) {
public:
    int value1;
    String value2;
};

void testFutureGetValue() {
    while(1) {
        FilaRoutine croutine = FilaRoutine::New();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            MyData data = MyData::New();
            data->value1 = 100;
            data->value2 = String::New("hello");
            st(FilaExecutorResult)::Set(data);
        });
        
        usleep(1000*100);
        auto value = future->getResult<MyData>();
        if(!value->value2->sameAs("hello")) {
            TEST_FAIL("Filament Future Get Value case1");
        }
        
        if(value->value1 != 100) {
            TEST_FAIL("Filament Future Get Value case2");
        }
        break;
    }

    TEST_OK("Filament Future Get Value case100");
  }
