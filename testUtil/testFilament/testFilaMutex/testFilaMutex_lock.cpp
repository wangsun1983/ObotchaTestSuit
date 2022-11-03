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
            st(Fila)::sleep(200);
        });
        usleep(1000*100);
        
        croutine->execute([&mutex] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 105 || interval < 95) {
                TEST_FAIL("FilaMutex test Lock case1");
            }
        });
        
        usleep(1000 * 300);
        break;
    }
    
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        croutine->execute([&mutex] {
            AutoLock l(mutex);
            //mutex->lock();
            st(Fila)::sleep(200);
        });
        usleep(1000*100);
        
        int run = 0;
        Thread t = createThread([&mutex,&run] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 105 || interval < 95) {
                TEST_FAIL("FilaMutex test Lock case2");
            }
            run = 1;
        });
        t->start();
        
        t->join();
        if(run != 1) {
            TEST_FAIL("FilaMutex test Lock case3");
        }
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
            if(interval > 105 || interval < 95) {
                TEST_FAIL("FilaMutex test Lock case4,interval is %d",interval);
            }
            ret = 1;
        });
        
        usleep(1000 * 300);
        
        if(ret != 1) {
            TEST_FAIL("FilaMutex test Lock case5");
        }
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
                st(Fila)::sleep(1);
            }
        });
        
        croutine->execute([&mutex,&value] {
            AutoLock l(mutex);
            for(int i = 0;i < 1024;i++) {
                value++;
                st(Fila)::sleep(1);
            }
        });
        
        croutine->execute([&mutex,&value] {
            AutoLock l(mutex);
            for(int i = 0;i < 1024;i++) {
                value++;
                st(Fila)::sleep(1);
            }
        });
        
        sleep(5);
        
        if(value != 1024*3) {
            TEST_FAIL("FilaMutex test Lock case6,value is %d",value);
        }
        
        break;
    }
    
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        croutine->start();
        FilaMutex mutex = createFilaMutex();
        
        croutine->execute([&mutex] {
            AutoLock l(mutex);
            //mutex->lock();
            st(Fila)::sleep(1000);
        });
        usleep(1000*100);
        
        croutine->execute([&mutex] {
            TimeWatcher t = createTimeWatcher();
            t->start();
            AutoLock l(mutex);
            auto interval = t->stop();
            if(interval > 905 || interval < 895) {
                TEST_FAIL("FilaMutex test Lock case7,interval is %d",interval);
            }
        });
        
        usleep(1000*2000);
        croutine->stop();
        croutine->join();
        usleep(1000*2000);
        break;
    }

    TEST_OK("FilaMutex test Lock case100");
}
