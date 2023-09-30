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
		
		usleep(1000*200);
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
			TEST_FAIL("FilaMutex Condition notify case5,unhit is %d",unhit);
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
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,200);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex Condition notify case6,r is %d",r);
			}
			count = 1;
		});
		usleep(1000*100);
		
		Thread t1 = createThread([&]{
			cond->notify();
		});
		t1->start();
		usleep(1000*50);
		if(count != 1) {
			TEST_FAIL("FilaMutex Condition notify case7,count is %d",count);
		}
		c->shutdown();
		c->awaitTermination();
		t1->join();
		break;
	}

	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		
		int hit = 0;
		int firsthit = 0;
		int secondhit = 0;
		int count = 0;
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 200) {
				firsthit = r;
			} else {
				secondhit = r;
			}
			count++;
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 200) {
				firsthit = r;
			} else {
				secondhit = r;
			}
			count++;
		});
		
		usleep(1000*100);
		Thread t1 = createThread([&] {
			cond->notify();
		});
		t1->start();
		
		usleep(1000*200);
		Thread t2 = createThread([&] {
			cond->notify();
		});
		t2->start();
		t1->join();
		t2->join();
		usleep(1000*200);
		
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notify case8");
		}
		
		if(firsthit < 95 || firsthit > 105) {
			TEST_FAIL("FilaMutex Condition notify case9,firsthit is %d",firsthit);
		}
		
		if(secondhit < 295 || secondhit > 315) {
			TEST_FAIL("FilaMutex Condition notify case10,secondhit is %d",secondhit);
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
		Thread t1 = createThread([&] {
			TimeWatcher w = createTimeWatcher();
			AutoLock l(m);
			w->start();
			cond->wait(m);
			auto r = w->stop();
			if(r < 95 || r > 115) {
				TEST_FAIL("FilaMutex Condition notify case11,r is %d",r);
			}
			count++;
		});
		t1->start();
		
		usleep(1000*100);
		c->execute([&]{
			cond->notify();
		});
		
		t1->join();
		c->shutdown();
		c->awaitTermination();
		if(count != 1) {
			TEST_FAIL("FilaMutex Condition notify case12,count is %d",count);
		}
		break;
	}

	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		FilaCondition cond = createFilaCondition();
		
		int hit = 0;
		int firsthit = 0;
		int secondhit = 0;
		int count = 0;
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 200) {
				firsthit = r;
			} else {
				secondhit = r;
			}
			count++;
		});
		
		Thread t1 = createThread([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 200) {
				firsthit = r;
			} else {
				secondhit = r;
			}
			count++;
		});
		t1->start();
		
		usleep(1000*100);
		Thread t2 = createThread([&] {
			cond->notify();
		});
		t2->start();
		
		usleep(1000*200);
		c->execute([&]{
			cond->notify();
		});
		
		t1->join();
		t2->join();
		usleep(1000*200);
		
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notify case13");
		}
		
		if(firsthit < 95 || firsthit > 105) {
			TEST_FAIL("FilaMutex Condition notify case14,firsthit is %d",firsthit);
		}
		
		if(secondhit < 295 || secondhit > 315) {
			TEST_FAIL("FilaMutex Condition notify case15,secondhit is %d",secondhit);
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
		c->execute([&]{
			TimeWatcher w = createTimeWatcher();
			count++;
			w->start();
			m->lock();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 95 || r > 115) {
				TEST_FAIL("FilaMutex Condition notify case16,r is %d",r);
			}
			count++;
		});
		
		usleep(1000*100);
		c->execute([&]{
			cond->notify();
		});
		usleep(1000*10);
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notify case17,count is %d",count);
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
		
		int hit = 0;
		int firsthit = 0;
		int secondhit = 0;
		int count = 0;
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 200) {
				firsthit = r;
			} else {
				secondhit = r;
			}
			count++;
		});
		
		c->execute([&]{
			AutoLock l(m);
			TimeWatcher w = createTimeWatcher();
			w->start();
			cond->wait(m,400);
			auto r = w->stop();
			if(r < 200) {
				firsthit = r;
			} else {
				secondhit = r;
			}
			count++;
		});
		
		usleep(1000*100);
		c->execute([&] {
			cond->notify();
		});
		
		usleep(1000*200);
		c->execute([&] {
			cond->notify();
		});
		usleep(1000*200);
		
		if(count != 2) {
			TEST_FAIL("FilaMutex Condition notify case18");
		}
		
		if(firsthit < 95 || firsthit > 105) {
			TEST_FAIL("FilaMutex Condition notify case19,firsthit is %d",firsthit);
		}
		
		if(secondhit < 295 || secondhit > 315) {
			TEST_FAIL("FilaMutex Condition notify case20,secondhit is %d",secondhit);
		}
		
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
    TEST_OK("FilaMutex test notify case100");
}
