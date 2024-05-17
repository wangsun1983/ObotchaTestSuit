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

void testWaitCounts() {
	while(1) {
		FilaRoutine c = FilaRoutine::New();
		c->start();
		FilaMutex m = FilaMutex::New();
		FilaCondition cond = FilaCondition::New();
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = TimeWatcher::New();
			w->start();
			cond->wait(m,100);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition WaitCounts case1");
			}
		});
		usleep(1000*50);
		if(cond->getWaitCounts() != 1) {
			TEST_FAIL("FilaMutex Condition WaitCounts case2,counts is %d",cond->getWaitCounts());
		}
		usleep(1000*200);
		if(cond->getWaitCounts() != 0) {
			TEST_FAIL("FilaMutex Condition WaitCounts case3");
		}
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
	while(1) {
		FilaRoutine c = FilaRoutine::New();
		c->start();
		FilaMutex m = FilaMutex::New();
		FilaCondition cond = FilaCondition::New();
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = TimeWatcher::New();
			w->start();
			cond->wait(m,100);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition WaitCounts case4");
			}
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = TimeWatcher::New();
			w->start();
			cond->wait(m,100);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition WaitCounts case5");
			}
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = TimeWatcher::New();
			w->start();
			cond->wait(m,100);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition WaitCounts case6");
			}
		});
		usleep(1000*50);
		if(cond->getWaitCounts() != 3) {
			TEST_FAIL("FilaMutex Condition WaitCounts case7,count is %d",cond->getWaitCounts());
		}
		
		usleep(1000*100);
		if(cond->getWaitCounts() != 0) {
			TEST_FAIL("FilaMutex Condition WaitCounts case8,count is %d",cond->getWaitCounts());
		}
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
    TEST_OK("FilaMutex test unlock case100");
}
