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

void testFilaMutexLock() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        croutine->execute([&mutex] {
            AutoLock l(mutex);
            //mutex->lock();
            try {
                st(Fila)::Sleep(200);
            }catch(...) {}
        });
        usleep(1000*100);
        
        croutine->execute([&mutex] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 115 || interval < 95) {
                TEST_FAIL("FilaMutex test Lock case1,interval is %d",interval);
            }
        });
        usleep(1000*200);

        croutine->shutdown();
        croutine->awaitTermination();
        break;
    }

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        croutine->execute([&mutex] {
            AutoLock l(mutex);
            //mutex->lock();
            st(Fila)::Sleep(200);
        });
        usleep(1000*100);
        
        int run = 0;
        Thread t = createThread([&mutex,&run] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 115 || interval < 95) {
                TEST_FAIL("FilaMutex test Lock case2,interval is %d",interval);
            }
            run = 1;
        });
        t->start();
        
        t->join();
        if(run != 1) {
            TEST_FAIL("FilaMutex test Lock case3");
        }
		croutine->shutdown();
		croutine->awaitTermination();
        break;
    }

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        Thread t = createThread([&mutex] {
            AutoLock l(mutex);
            usleep(1000 * 200);
        });
        t->start();
        usleep(1000*100);
        
        int ret = 0;
        croutine->execute([&mutex,&ret] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 115 || interval < 95) {
                TEST_FAIL("FilaMutex test Lock case4,interval is %d",interval);
            }
            ret = 1;
        });
        
        usleep(1000 * 300);
        
        if(ret != 1) {
            TEST_FAIL("FilaMutex test Lock case5");
        }
		croutine->shutdown();
		croutine->awaitTermination();
        break;
    }

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        int value = 0;
        croutine->execute([&mutex,&value] {
            AutoLock l(mutex);
            for(int i = 0;i < 1024;i++) {
                value++;
                st(Fila)::Sleep(1);
            }
        });
        
        croutine->execute([&mutex,&value] {
            AutoLock l(mutex);
            for(int i = 0;i < 1024;i++) {
                value++;
                st(Fila)::Sleep(1);
            }
        });
        
        croutine->execute([&mutex,&value] {
            AutoLock l(mutex);
            for(int i = 0;i < 1024;i++) {
                value++;
                st(Fila)::Sleep(1);
            }
        });
        
        sleep(5);
        
        if(value != 1024*3) {
            TEST_FAIL("FilaMutex test Lock case6,value is %d",value);
        }
        croutine->shutdown();
        croutine->awaitTermination();
        break;
    }

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        croutine->execute([&mutex] {
            AutoLock l(mutex);
            //mutex->lock();
            st(Fila)::Sleep(1000);
        });
        usleep(1000*100);
        
        croutine->execute([&mutex] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 915 || interval < 895) {
                TEST_FAIL("FilaMutex test Lock case7,interval is %d",interval);
            }
        });
        
        usleep(1000*2000);
        croutine->shutdown();
        croutine->awaitTermination();
        break;
    }
    

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        croutine->execute([&mutex] {
            mutex->lock();
            st(Fila)::Sleep(1000);
            mutex->unlock();
        });
        usleep(1000*100);
        
        bool isExecute = false;
        croutine->execute([&isExecute,&mutex] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 915 || interval < 895) {
                TEST_FAIL("FilaMutex test Lock case8,interval is %d",interval);
            }
            
            isExecute = true;
        });
        
        usleep(1000*2000);
		croutine->shutdown();
		croutine->awaitTermination();
        usleep(1000*2000);
        
        if(!isExecute) {
            TEST_FAIL("FilaMutex test Lock case8_1");
        }
        break;
    }

	while(1) {
		TimeWatcher watcher = createTimeWatcher();
	    FilaRoutine croutine = createFilaRoutine();
	    croutine->start();
	    FilaMutex mutex = createFilaMutex();
		croutine->execute([&] {
			mutex->lock();
			mutex->lock();
			mutex->unlock();
			st(Fila)::Sleep(300);
			mutex->unlock();
		});
		usleep(100*1000);
		
		int count = 0;
		croutine->execute([&] {
			watcher->start();
			mutex->lock();
			auto r = watcher->stop();
			if(r < 195 || r > 215) {
				TEST_FAIL("FilaMutex test Lock case9,r is %d",r);
			}
			count = 1;
		});
		
		usleep(400*1000);
		if(count != 1) {
			TEST_FAIL("FilaMutex test Lock case10");
		}
		croutine->shutdown();
		croutine->awaitTermination();
		break;
	}

    TEST_OK("FilaMutex test Lock case100");
}
