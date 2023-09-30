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

void testFilaRoutineAwait() {
	//case1	
	TimeWatcher w = createTimeWatcher();	
	while(1) {
		FilaMutex mutex = createFilaMutex();
		std::vector<int> data;
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		Thread t1 = createThread([&] {
			AutoLock l(mutex);
			usleep(500*1000);
		});
		t1->start();
		usleep(1000*100);
		
		croutine->execute([&] {
			AutoLock l(mutex);
		});
		croutine->shutdown();
		w->start();
		croutine->awaitTermination(100);
		auto r = w->stop();
		if(r < 95 || r > 115) {
			TEST_FAIL("FilaRoutine awaitTermination case1,wait cost: %ld",r);
		}
		
		w->start();
		croutine->awaitTermination();
		r = w->stop();
		if(r < 295 || r > 315) {
			TEST_FAIL("FilaRoutine awaitTermination case2,wait cost: %ld",r);
		}
		t1->join();
		break;
	}
	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		int ret = croutine->awaitTermination();
		if(ret != -1) {
			TEST_FAIL("FilaRoutine awaitTermination case3");
		}
		break;
	}
	TEST_OK("FilaMutex awaitTermination case100");
}
