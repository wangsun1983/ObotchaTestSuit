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

using namespace std;
using namespace obotcha;

void testFilaRoutineShutdownInSleep() {
	//case1	
	TimeWatcher w = createTimeWatcher();	
#if 0	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		int count = 0;
		croutine->execute([&] {
			w->start();
			try {
				st(Fila)::Sleep(500);
				TEST_FAIL("FilaRoutine shutdown Interrupt case1");
			} catch(...) {}
			
			auto cost = w->stop();
			if(cost > 105) {
				TEST_FAIL("FilaRoutine shutdown Interrupt case2,cost is %d",cost);
			}
			count++;
		});
		
		croutine->execute([&] {
			w->start();
			try {
				st(Fila)::Sleep(500);
				TEST_FAIL("FilaRoutine shutdown Interrupt case3");
			} catch(...) {}
			if(w->stop() > 105) {
				TEST_FAIL("FilaRoutine shutdown Interrupt case4");
			}
			count++;
		});
		
		usleep(1000*100);
		Thread t1 = createThread([&]{
			croutine->shutdown();
		});
		t1->start();
		t1->join();
		usleep(600*1000);
		if(count != 2) {
			TEST_FAIL("FilaRoutine shutdown Interrupt case5,count is %d",count);
		}
		break;
	}
#endif	
	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		int count = 0;
		FilaMutex mutex = createFilaMutex();
		FilaCondition condition = createFilaCondition();
		croutine->execute([&] {
			w->start();
			try {
				AutoLock l(mutex);
				condition->wait(mutex,500);
				TEST_FAIL("FilaRoutine shutdown Interrupt case1");
			} catch(...) {}
			
			auto cost = w->stop();
			if(cost > 105) {
				TEST_FAIL("FilaRoutine shutdown Interrupt case2,cost is %d",cost);
			}
			count++;
		});
		
		croutine->execute([&] {
			w->start();
			try {
				AutoLock l(mutex);
				condition->wait(mutex,500);
				TEST_FAIL("FilaRoutine shutdown Interrupt case3");
			} catch(...) {}
			if(w->stop() > 105) {
				TEST_FAIL("FilaRoutine shutdown Interrupt case4");
			}
			count++;
		});
		
		usleep(1000*100);
		Thread t1 = createThread([&]{
			croutine->shutdown();
		});
		t1->start();
		t1->join();
		usleep(600*1000);
		if(count != 2) {
			TEST_FAIL("FilaRoutine shutdown Interrupt case5,count is %d",count);
		}
		break;
	}
	TEST_OK("FilaRoutine shutdown case100");
}
