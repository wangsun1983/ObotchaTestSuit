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

void testFilaRoutineShutdown() {
	//case1	
	TimeWatcher w = createTimeWatcher();	
	while(1) {
		int case1_count = 0;
		for(int i = 0;i < 256;i++) {
			FilaMutex mutex = createFilaMutex();
			std::vector<int> data;
			FilaRoutine croutine = createFilaRoutine();
			croutine->start();
			croutine->execute([&] {
				AutoLock l(mutex);
				st(Fila)::Sleep(200);
				case1_count++;
			});
			croutine->shutdown();
			w->start();
			croutine->awaitTermination();
			auto r = w->stop();
			if(r < 195 || r > 215) {
				TEST_FAIL("FilaRoutine shutdown case1,wait cost: %ld",r);
			}
		}
		
		if(case1_count != 256) {
			TEST_FAIL("FilaRoutine shutdown case2,case1_count is %d",case1_count);
		}
		break;
	}
	
	while(1) {
		int case1_count = 0;
		for(int i = 0;i < 256;i++) {
			FilaMutex mutex = createFilaMutex();
			std::vector<int> data;
			FilaRoutine croutine = createFilaRoutine();
			croutine->start();
			croutine->execute([&] {
				AutoLock l(mutex);
				st(Fila)::Sleep(200);
				case1_count++;
			});
			croutine->shutdown();
			usleep(1000*250);
		}
		
		if(case1_count != 256) {
			TEST_FAIL("FilaRoutine shutdown case3,case1_count is %d",case1_count);
		}
		break;
	}
	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		croutine->execute([&] {
			AutoLock l(mutex);
			st(Fila)::Sleep(200);
		});
		croutine->shutdown();
		auto future = croutine->submit([&] {
			AutoLock l(mutex);
			st(Fila)::Sleep(200);
		});
		if(future != nullptr) {
			TEST_FAIL("FilaRoutine shutdown case4");
		}
		break;
	}

	TEST_OK("FilaMutex shutdown case100");
}
