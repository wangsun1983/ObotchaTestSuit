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

void testMutexUnlock() {
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex m = createFilaMutex();
		
		c->execute([&]{
			try {
				m->unlock();
				TEST_FAIL("FilaMutex test unlock cases1");
			} catch(...) {}
		});
		
		c->execute([&]{
			try {
				m->lock();
				m->unlock();
			} catch(...) {
				TEST_FAIL("FilaMutex test unlock cases2");
			}
		});
		
		c->execute([&]{
			try {
				m->lock();
				m->unlock();
				m->unlock();
				TEST_FAIL("FilaMutex test unlock cases3");
			} catch(...) {
			}
		});
		usleep(1000*10);
		m->lock();
		usleep(1000*10);
		c->execute([&]{
			try {
				m->unlock();
				TEST_FAIL("FilaMutex test unlock cases4");
			} catch(...) {
			}
		});
		usleep(1000*100);
		c->shutdown();
		c->awaitTermination();
		break;
	}

	while(1) {
		FilaMutex m = createFilaMutex();
		FilaRoutine c = createFilaRoutine();
		c->start();
		Thread t1 = createThread([&]{
			m->lock();
			usleep(1000*300);
			m->unlock();
		});
		t1->start();
		usleep(1000*100);
		
		int count = 0;
		c->execute([&]{
			TimeWatcher w = createTimeWatcher();
			w->start();
			m->lock();
			auto r = w->stop();
			if(r < 195 || r > 215) {
				TEST_FAIL("FilaMutex test unlock case5,r is %d",r);
			}
			
			count = 1;
		});
		usleep(1000*400);
		if(count != 1) {
			TEST_FAIL("FilaMutex test unlock case6");
		}
		c->shutdown();
		c->awaitTermination();
		break;
	}

	while(1) {
		FilaMutex m = createFilaMutex();
		FilaRoutine c = createFilaRoutine();
		c->start();
		
		c->execute([&]{
			m->lock();
			st(Fila)::Sleep(300);
			m->unlock();
		});
		usleep(1000*100);
		
		int count = 0;
		Thread t1 = createThread([&]{
			TimeWatcher w = createTimeWatcher();
			w->start();
			m->lock();
			auto r = w->stop();
			if(r < 195 || r > 215) {
				TEST_FAIL("FilaMutex test unlock case7,r is %d",r);
			}
			count = 1;
		});
		t1->start();
		t1->join();
		usleep(300*1000);
		if(count != 1) {
			TEST_FAIL("FilaMutex test unlock case8");
		}
		c->shutdown();
		c->awaitTermination();
		break;
	}
	
	for(int i = 0;i < 128;i++) {
		FilaMutex m = createFilaMutex();
		FilaRoutine c = createFilaRoutine();
		c->start();
		int count = 0;
		
		c->execute([&]{
			//printf("tt1 \n");
			m->lock();
			//printf("tt1_1 \n");
			count++;
			st(Fila)::Sleep(100);
			m->unlock();
		});
		
		c->execute([&]{
			//printf("tt2 \n");
			m->lock();
			//printf("tt2_1 \n");
			count++;
			st(Fila)::Sleep(100);
			m->unlock();
		});
		
		c->execute([&]{
			//printf("tt3 \n");
			m->lock();
			//printf("tt3_1 \n");
			count++;
			st(Fila)::Sleep(100);
			m->unlock();
		});
		
		Thread t1 = createThread([&]{
			m->lock();
			count++;
			usleep(1000*100);
			m->unlock();
		});
		t1->start();
		
		Thread t2 = createThread([&]{
			m->lock();
			count++;
			usleep(1000*100);
			m->unlock();
		});
		t2->start();
		
		Thread t3 = createThread([&]{
			m->lock();
			count++;
			usleep(1000*100);
			m->unlock();
		});
		t3->start();
		
		usleep(600*1000);
		usleep(100*1000);
		
		if(count != 6) {
			TEST_FAIL("FilaMutex test unlock case9,count is %d,i is %d",count,i);
		}
		c->shutdown();
		c->awaitTermination();
	}
    TEST_OK("FilaMutex test unlock case100");
}
