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
#include "Fila.hpp"
#include "System.hpp"

using namespace std;
using namespace obotcha;

void testFutureWake() {
    while(1) {
        FilaRoutine croutine = FilaRoutine::New();
        FilaFuture future = FilaFuture::New();
        long start = 0;
        long finish = 0;
        croutine->start();
        croutine->submit([future,&finish]{
            future->wait();
            finish = st(System)::CurrentTimeMillis();
        });
        
        usleep(1000*100);
        start = st(System)::CurrentTimeMillis();
        future->wake();
        usleep(1000*100);
        if(finish < start) {
            TEST_FAIL("Filament Future wake case1");
        }
        
        break;
    }

    while(1) {
        FilaRoutine croutine = FilaRoutine::New();
        FilaFuture future = FilaFuture::New();
        long start = 0;
        long finish1 = 0;
        long finish2 = 0;
        croutine->start();
        croutine->submit([future,&finish1]{
            future->wait();
            finish1 = st(System)::CurrentTimeMillis();
        });
        
        croutine->submit([future,&finish2]{
            future->wait();
            finish2 = st(System)::CurrentTimeMillis();
        });
        
        usleep(1000*100);
        start = st(System)::CurrentTimeMillis();
        future->wakeAll();
        usleep(1000*100);
        if(finish1 < start || finish2 < start) {
            TEST_FAIL("Filament Future wake case2");
        }
        
        break;
    }
    
    while(1) {
        FilaRoutine croutine = FilaRoutine::New();
        FilaFuture future = FilaFuture::New();
        long start = 0;
        long finish1 = 0;
        long finish2 = 0;
        croutine->start();
        croutine->submit([future,&finish1]{
            future->wait();
            finish1 = st(System)::CurrentTimeMillis();
        });
        
        croutine->submit([future,&finish2]{
            future->wait();
            finish2 = st(System)::CurrentTimeMillis();
        });
        
        usleep(1000*100);
        start = st(System)::CurrentTimeMillis();
        future->wake();
        usleep(1000*100);
        if(finish1 > start && finish2 > start) {
            TEST_FAIL("Filament Future wake case3");
        }
        
        future->wakeAll();
        break;
    }

    TEST_OK("Filament Future wake case100");
  }
