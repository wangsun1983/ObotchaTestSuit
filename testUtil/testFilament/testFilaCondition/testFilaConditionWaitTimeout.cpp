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

void testWaitTimeout() {
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,100);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition wait case1");
			}
		});
		usleep(1000*200);
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		int count = 0;
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m);
			auto r = w->stop();
			if(r < 95 || r > 115) {
				TEST_FAIL("FilaMutex Condition wait case2");
			}
			count = 1;
		});
		
		usleep(1000*100);
		c->execute([&]{
			AutoLock l(m);
			cond->notify();
		});
		
		usleep(1000*100);
		if(count != 1) {
			TEST_FAIL("FilaMutex Condition wait case3");
		}
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		int count = 0;
		for(int i = 0;i < 128;i++) {
			c->execute([&]{
				AutoLock l(m);
				TimeWatcher w = createTimeWatcher();
				w->start();
				cond->wait(m,200);
				auto r = w->stop();
				if(r < 95 || r > 225) {
					TEST_FAIL("FilaMutex Condition wait case4,r is %d",r);
				}
				count++;
			});
		}
		
		usleep(1000*250);
		if(count != 128) {
			TEST_FAIL("FilaMutex Condition wait case5");
		}
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
	//test in thread
	while(1) {
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		TimeWatcher w = createTimeWatcher();
		AutoLock l(m);
		w->start();
		cond->wait(m,100);
		auto r = w->stop();
		if(r < 95 || r > 105) {
			TEST_FAIL("FilaMutex Condition wait case6");
		}
		break;
	}
	
    TEST_OK("FilaMutex test unlock case100");
}
