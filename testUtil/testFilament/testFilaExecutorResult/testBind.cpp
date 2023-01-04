#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "Fila.hpp"
#include "TimeWatcher.hpp"
#include "FilaExecutorResult.hpp"

using namespace std;
using namespace obotcha;

void testBind() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        bool isRun = false;
        auto f = croutine->submit([&isRun]{
            auto result = createFilaExecutorResult();
            st(FilaExecutorResult)::bindResult(GetCurrThreadCo(),
                                            result);
            st(FilaExecutorResult)::set(createString("abc"));
            
            auto ret = result->get<String>();
            if(ret == nullptr || !ret->equals("abc")) {
                TEST_FAIL("Filament test FilaExecutorResult case1");
            }
            isRun = true;
        });        
        usleep(1000*100);
        
        if(!isRun) {
            TEST_FAIL("Filament test FilaExecutorResult case2");
        }
        break;
    }
    
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        bool isRun = false;
        auto f = croutine->submit([&isRun]{
            auto result = createFilaExecutorResult();
            st(FilaExecutorResult)::bindResult(GetCurrThreadCo(),
                                            result);
            st(FilaExecutorResult)::set(createString("abc"));
            st(FilaExecutorResult)::unBindResult(GetCurrThreadCo());
            st(FilaExecutorResult)::set(createString("abc2"));
            
            auto ret = result->get<String>();
            if(ret == nullptr || !ret->equals("abc")) {
                TEST_FAIL("Filament test FilaExecutorResult case3");
            }
            isRun = true;
        });        
        usleep(1000*100);
        
        if(!isRun) {
            TEST_FAIL("Filament test FilaExecutorResult case4");
        }
        break;
    }
    
    TEST_OK("Filament test FilaExecutorResult case100");
  }
