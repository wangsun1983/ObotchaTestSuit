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

void testFilaRoutineGetSize() {
	//case1	
	while(1) {
		TimeWatcher w = createTimeWatcher();
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		if(croutine->getFilamentSize() != 0) {
			TEST_FAIL("FilaRoutine getFilamentSize case1");
		}
		
		for(int i = 0;i < 64;i++) {
			croutine->execute([&] {
				AutoLock l(mutex);
				st(Fila)::Sleep(200);
			});
		}
		
		usleep(1000*50);
		if(croutine->getFilamentSize() != 64) {
			TEST_FAIL("FilaRoutine getFilamentSize case2");
		}
		
		croutine->shutdown();
		w->start();
		croutine->awaitTermination();
		auto r = w->stop();
		if(r < 145 || r > 165) {
			TEST_FAIL("FilaRoutine getFilamentSize case3,r is %d",r);
		}
		
		if(croutine->getFilamentSize() != 0) {
			TEST_FAIL("FilaRoutine getFilamentSize case3");
		}
		break;
	}
	
	TEST_OK("FilaMutex getFilamentSize case100");
}
