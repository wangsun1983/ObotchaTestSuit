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

void testFutureWaitTimeout() {
	TimeWatcher w = TimeWatcher::New();
	
    while(1) {
        FilaRoutine croutine = FilaRoutine::New();
        croutine->start();
        FilaFuture future = croutine->submit([]{
            st(Fila)::Sleep(200);
            st(FilaExecutorResult)::Set<int>(100);
        });
        w->start();
		future->wait(100);
		auto ret = w->stop();
		if(ret < 95 || ret > 105) {
			TEST_FAIL("Filament Future wait timeout case1");
		}
		
		w->start();
		future->wait(200);
		ret = w->stop();
		if(ret > 105) {
			TEST_FAIL("Filament Future wait timeout case2");
		}
		
		croutine->shutdown();
		croutine->awaitTermination();
        break;
    }
	
	while(1) {
		FilaRoutine croutine = FilaRoutine::New();
		int count = 0;
		croutine->start();
		FilaFuture future = croutine->submit([]{
		    st(Fila)::Sleep(300);
		    st(FilaExecutorResult)::Set<int>(100);
		});
		
		usleep(1000*100);
		croutine->submit([&]{
		    w->start();
		    future->wait(100);
		    auto ret = w->stop();
		    if(ret < 95 || ret > 105) {
		    	TEST_FAIL("Filament Future wait timeout case3");
		    }
		    
		    w->start();
		    future->wait(200);
		    ret = w->stop();
		    if(ret > 105) {
		    	TEST_FAIL("Filament Future wait timeout case4");
		    }
			
			auto v = future->getResult<int>();
			if(v != 100) {
				TEST_FAIL("Filament Future wait timeout case5,v is %d",v);
			}
			count++;
		});
		
		usleep(1000*500);
		croutine->shutdown();
		croutine->awaitTermination();
		if(count != 1) {
			TEST_FAIL("Filament Future wait timeout case6");
		}
		break;
	}

    TEST_OK("Filament Future wait timeout case100");
  }
