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
	TimeWatcher w = TimeWatcher::New();	
	while(1) {
		int case1_count = 0;
		for(int i = 0;i < 256;i++) {
			FilaMutex mutex = FilaMutex::New();
			std::vector<int> data;
			FilaRoutine croutine = FilaRoutine::New();
			croutine->start();
			
			Thread t1 = Thread::New([&] {
				AutoLock l(mutex);
				usleep(300*1000);
			});
			t1->start();
			usleep(1000*100);
			
			croutine->execute([&] {
				AutoLock l(mutex);
				case1_count++;
			});
			usleep(1000*100);
			croutine->shutdown();
			w->start();
			croutine->awaitTermination();
			auto r = w->stop();
			if(r < 95 || r > 115) {
				TEST_FAIL("FilaRoutine shutdown case1,wait cost: %ld,i is %d",r,i);
			}
			t1->join();
		}
		
		if(case1_count != 256) {
			TEST_FAIL("FilaRoutine shutdown case2,case1_count is %d",case1_count);
		}
		break;
	}
	
	while(1) {
		int case1_count = 0;
		for(int i = 0;i < 256;i++) {
			FilaMutex mutex = FilaMutex::New();
			std::vector<int> data;
			FilaRoutine croutine = FilaRoutine::New();
			croutine->start();
			
			Thread t1 = Thread::New([&] {
				AutoLock l(mutex);
				usleep(200*1000);
			});
			t1->start();
			usleep(1000*100);
			
			croutine->execute([&] {
				AutoLock l(mutex);
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
		FilaRoutine croutine = FilaRoutine::New();
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
