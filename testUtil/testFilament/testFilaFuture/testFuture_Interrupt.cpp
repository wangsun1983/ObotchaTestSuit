#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "FilaExecutorResult.hpp"
#include "Uint32.hpp"
#include "Fila.hpp"
#include "System.hpp"

using namespace std;
using namespace obotcha;

void testFutureInterrupt() {
    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        FilaFuture future = createFilaFuture();
        croutine->start();
        auto f1 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(500);
            } catch(...) {}
        });

        auto f2 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(500);
            } catch(...) {}
        });

        auto f3 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(500);
            } catch(...) {}
        });

        auto f4 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(500);
            } catch(...) {}
        });

        auto f5 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(500);
            } catch(...) {}
        });

        Thread t1 = createThread([&] {
            TimeWatcher w = createTimeWatcher();
            w->start();
            f1->wait();
            auto r = w->stop();
            if(r < 190 || r > 220) {
                TEST_FAIL("Filament Future Interrupt case1,r is %d",r);
            }
        });
        t1->start();

        Thread t2 = createThread([&] {
            TimeWatcher w = createTimeWatcher();
            w->start();
            f2->wait();
            auto r = w->stop();
            if(r < 190 || r > 220) {
                TEST_FAIL("Filament Future Interrupt case2,r is %d",r);
            }
        });
        t2->start();

        Thread t3 = createThread([&] {
            TimeWatcher w = createTimeWatcher();
            w->start();
            f3->wait();
            auto r = w->stop();
            if(r < 190 || r > 220) {
                TEST_FAIL("Filament Future Interrupt case3,r is %d",r);
            }
        });
        t3->start();

        Thread t4 = createThread([&] {
            TimeWatcher w = createTimeWatcher();
            w->start();
            f4->wait();
            auto r = w->stop();
            if(r < 190 || r > 220) {
                TEST_FAIL("Filament Future Interrupt case4,r is %d",r);
            }
        });
        t4->start();

        Thread t5 = createThread([&] {
            TimeWatcher w = createTimeWatcher();
            w->start();
            f5->wait();
            auto r = w->stop();
            if(r < 190 || r > 220) {
                TEST_FAIL("Filament Future Interrupt case5,r is %d",r);
            }
        });
        t5->start();
        usleep(1000*200);
        croutine->shutdown();
        croutine->awaitTermination();
        t1->join();
        t2->join();
        t3->join();
        t4->join();
        t5->join();
        break;
    }

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        FilaFuture future = createFilaFuture();
        croutine->start();
        auto f1 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(300);
            } catch(...) {}
        });

        Thread t1 = createThread([&]{
            TimeWatcher w = createTimeWatcher();
            w->start();
            try {
                f1->getResult<int>();
                TEST_FAIL("Filament Future Interrupt case7");
            } catch(...) {}
            
            auto r1 = w->stop();
            if(r1 < 95 || r1 > 105) {
                TEST_FAIL("Filament Future Interrupt case8,r1 is %ld",r1);
            }
        });
        t1->start();

        usleep(1000*100);
        croutine->shutdown();
        t1->join();
        croutine->awaitTermination();
        break;
    }

    while(1) {
        FilaRoutine croutine = createFilaRoutine();
        FilaFuture future = createFilaFuture();
        croutine->start();
        auto f1 = croutine->submit([&]{
            try {
                st(Fila)::Sleep(300);
            } catch(...) {}
        });

        croutine->shutdown();
        croutine->awaitTermination();

        try {
            f1->getResult<int>();
            TEST_FAIL("Filament Future Interrupt case9");
        } catch(...){}
        break;
    }
    TEST_OK("Filament Future Interrupt case100");
  }
