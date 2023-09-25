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
#include "Thread.hpp"

using namespace std;
using namespace obotcha;

void testSleepInThread() {
	while(1) {
		TimeWatcher w = createTimeWatcher();
		Thread t = createThread([&] {
			w->start();
			st(Fila)::Sleep(100);
			auto ret = w->stop();
			if(ret < 95 || ret > 105) {
				TEST_FAIL("Filament test sleep in thread case1");
			}
		});
		t->start();
		t->join();
		break;
	}
    TEST_OK("Filament test sleep in thread case100");
}
