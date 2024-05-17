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
#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "FilaCondition.hpp"

using namespace std;
using namespace obotcha;

void testSleepInterrupt() {
	TimeWatcher w = TimeWatcher::New();
	while(1) {
		FilaRoutine croutine = FilaRoutine::New();
		croutine->start();
		int count = 0;
		auto f = croutine->submit([&]{
		  count = 1;
		  try {
			st(Fila)::Sleep(300);
			TEST_FAIL("Filament test sleep interrupt case1"); 
		  } catch(...) {}
		});
		usleep(1000*100);
		Thread t = Thread::New([&]{
			croutine->shutdown();
		});
		t->start();
		w->start();
		f->wait();
		auto r = w->stop();
		if(r > 5) {
			TEST_FAIL("Filament test sleep interrupt case2,r is %d",r);
		}
		
		if(count != 1) {
			TEST_FAIL("Filament test sleep interrupt case3,count is %d",count);
		}
		
		if(f->getStatus() != st(Concurrent)::Status::Interrupt) {
			TEST_FAIL("Filament test sleep interrupt case4");
		}
		break;
	}

    TEST_OK("Filament test sleep interrupt case100");
}
