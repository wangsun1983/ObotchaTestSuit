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

void testNotify() {
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
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notify case1,r is %d",r);
			}
			count = 1;
		});
		usleep(1000*100);
		c->execute([&]{
			cond->notify();
		});
		
		c->shutdown();
		c->awaitTermination();
		if(count != 1) {
			TEST_FAIL("FilaMutex Condition notify case2");
		}
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		
		int hit = 0;
		int unhit = 0;
		int count = 0;
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 200) {
				hit = r;
			} else {
				unhit = r;
			}
			count++;
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 200) {
				hit = r;
			} else {
				unhit = r;
			}
			count++;
		});
		
		usleep(1000*100);
		c->execute([&]{
			cond->notify();
		});
		
		usleep(1000*150);
		
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notify case3");
		}
		
		if(hit < 95 || hit > 105) {
			TEST_FAIL("FilaMutex Condition notify case4,hit is %d",hit);
		}
		
		if(unhit < 195 || unhit > 215) {
			TEST_FAIL("FilaMutex Condition notify case4,unhit is %d",unhit);
		}
		
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
    TEST_OK("FilaMutex test notify case100");
}
