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

void testFilaRoutineIsTerminated() {
	//case1	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		croutine->execute([&] {
			AutoLock l(mutex);
			st(Fila)::Sleep(100);
		});
		
		if(croutine->isTerminated()) {
			TEST_FAIL("FilaMutex isTerminated case1");
		}
		
		croutine->shutdown();
		if(!croutine->isTerminated()) {
			TEST_FAIL("FilaMutex isTerminated case2");
		}
		break;
	}
	
	TEST_OK("FilaMutex isTerminated case100");
}
