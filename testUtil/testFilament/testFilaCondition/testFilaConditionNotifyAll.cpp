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

void testNotifyAll() {
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
				TEST_FAIL("FilaMutex Condition notifyAll case1,r is %d",r);
			}
			count++;
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case2,r is %d",r);
			}
			count++;
		});
		
		usleep(1000*100);
		c->execute([&]{
			cond->notifyAll();
		});
		
		usleep(1000*50);
		c->shutdown();
		c->awaitTermination();
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notifyAll case3");
		}
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
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case4,r is %d",r);
			}
			count++;
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case5,r is %d",r);
			}
			count++;
		});
		
		usleep(1000*100);
		Thread t1 = createThread([&]{
			cond->notifyAll();
		});
		t1->start();
		
		usleep(1000*50);
		c->shutdown();
		c->awaitTermination();
		t1->join();
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notifyAll case6");
		}
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		int count = 0;
		Thread t1 = createThread([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case7,r is %d",r);
			}
			count++;
		});
		
		Thread t2 = createThread([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case8,r is %d",r);
			}
			count++;
		});
		t1->start();
		t2->start();
		
		usleep(1000*100);
		c->execute([&]{
			cond->notifyAll();
		});
		
		usleep(1000*50);
		c->shutdown();
		c->awaitTermination();
		t1->join();
		t2->join();
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notifyAll case9");
		}
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		int count = 0;
		Thread t1 = createThread([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case10,r is %d",r);
			}
			count++;
		});
		t1->start();
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notifyAll case11,r is %d",r);
			}
			count++;
		});
		t1->start();
		
		usleep(1000*100);
		c->execute([&]{
			cond->notifyAll();
		});
		
		usleep(1000*50);
		c->shutdown();
		c->awaitTermination();
		t1->join();
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notifyAll case12");
		}
		break;
	}
	
    TEST_OK("FilaMutex test notifyAll case100");
}
