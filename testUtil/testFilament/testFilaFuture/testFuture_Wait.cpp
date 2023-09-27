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

void testFutureWait() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(Fila)::Sleep(200);
            st(FilaExecutorResult)::Set<int>(100);
        });
        
        usleep(1000*100);
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        auto value = future->getResult<int>();
        auto interval = watcher->stop();
        if(value != 100) {
            TEST_FAIL("Filament Future wait case1,value is %d",value);
        }
        
        if(interval < 95 || interval > 105) {
            TEST_FAIL("Filament Future wait case2");
        }
        break;
    }


    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(Fila)::Sleep(1000);
            st(FilaExecutorResult)::Set<int>(100);
        });
        
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        int value = 0;
        try {
            future->getResult<int>(100);
            TEST_FAIL("Filament Future wait case3");
        } catch(...) {}
        auto interval = watcher->stop();
        
        if(interval < 95 || interval > 105) {
            TEST_FAIL("Filament Future wait case4");
        }
        sleep(2);
        break;
    }
    
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(Fila)::Sleep(100);
            st(FilaExecutorResult)::Set<int>(100);
        });
        
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        int value = 0;
        try {
            value = future->getResult<int>(200);
        } catch(...) {
            TEST_FAIL("Filament Future wait case5");
        }
        auto interval = watcher->stop();
        
        if(interval < 95 || interval > 105) {
            TEST_FAIL("Filament Future wait case6");
        }
        sleep(2);
        break;
    }
    
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(Fila)::Sleep(100);
            st(FilaExecutorResult)::Set<int>(100);
        });
        
        int v1 = 0;
        Thread t1 = createThread([&future,&v1]{
            v1 = future->getResult<int>();
        });
        
        int v2 = 0;
        Thread t2 = createThread([&future,&v2]{
            v2 = future->getResult<int>();
        });
        t1->start();
        t2->start();
        t1->join();
        t2->join();
        if(v1 != 100 || v2 != 100) {
            TEST_FAIL("Filament Future wait case7");
        }
        break;
    }
    
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(Fila)::Sleep(100);
            st(FilaExecutorResult)::Set<int>(100);
        });
        
        int v1 = 0;
        croutine->execute([&future,&v1]{
            v1 = future->getResult<int>();
        });
        
        int v2 = 0;
        croutine->execute([&future,&v2]{
            v2 = future->getResult<int>();
        });
        
        st(Fila)::Sleep(200);
        if(v1 != 100 || v2 != 100) {
            TEST_FAIL("Filament Future wait case8");
        }
        break;
    }


    TEST_OK("Filament Future wait case100");
  }
