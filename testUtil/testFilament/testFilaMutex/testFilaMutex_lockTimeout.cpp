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

void testFilaMutexLockTimeout() {
    while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex mutex = createFilaMutex();
		mutex->lock();
		
		c->execute([&]{
			TimeWatcher w = createTimeWatcher();
			w->start();
			mutex->lock(100);
			auto r = w->stop();
			if(r < 95 || r > 105) {
				TEST_FAIL("FilaMutex test Lock Timeout case1");
			}
		});
		
		usleep(200*1000);
		mutex->unlock();
		c->execute([&]{
			TimeWatcher w = createTimeWatcher();
			w->start();
			mutex->lock(100);
			auto r = w->stop();
			if(r > 5) {
				TEST_FAIL("FilaMutex test Lock Timeout case2");
			}
		});
		usleep(1000*100);
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex mutex = createFilaMutex();
		
		Thread t1 = createThread([&]{
			mutex->lock();
			usleep(1000*200);
			mutex->unlock();
		});
		t1->start();
		usleep(100*1000);
		
		c->execute([&]{
			TimeWatcher w = createTimeWatcher();
			w->start();
			mutex->lock(100);
			auto r = w->stop();
			if(r > 105 || r < 95) {
				TEST_FAIL("FilaMutex test Lock Timeout case3,r is %d",r);
			}
		});
		usleep(1000*200);
		break;
	}
	
	while(1) {
		FilaRoutine c = createFilaRoutine();
		c->start();
		FilaMutex mutex = createFilaMutex();
		c->execute([&]{
			mutex->lock();
			st(Fila)::Sleep(200);
			mutex->unlock();
		});
		usleep(1000*100);
		
		Thread t1 = createThread([&]{
			TimeWatcher w = createTimeWatcher();
			w->start();
			mutex->lock(100);
			auto r = w->stop();
			if(r > 105 || r < 95) {
				TEST_FAIL("FilaMutex test Lock Timeout case4");
			}
		});
		t1->start();
		usleep(200*1000);
		break;
	}
	
    TEST_OK("FilaMutex test Lock Timeout case100");
}
