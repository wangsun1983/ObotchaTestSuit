#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "Fila.hpp"

using namespace std;
using namespace obotcha;

void testFilaRoutineDestroy() {
	//case1
	for(int i = 0;i < 1024;i++) {
		FilaMutex mutex = createFilaMutex();
		std::vector<int> data;
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		croutine->execute([&] {
			AutoLock l(mutex);
			st(Fila)::Sleep(200);
		});
		croutine->shutdown();
		croutine->awaitTermination();
		printf("count is %d \n",croutine->getStrongCount());
	}
	
	TEST_OK("FilaMutex test unlock case100");
}
