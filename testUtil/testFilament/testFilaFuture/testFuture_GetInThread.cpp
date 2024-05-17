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

using namespace std;
using namespace obotcha;

void testFutureGetInThread() {
    while(1) {
        FilaRoutine croutine = FilaRoutine::New();
        croutine->start();
        FilaFuture future = croutine->submit([]{
			st(Fila)::Sleep(100);
            st(FilaExecutorResult)::Set(String::New("hello"));
        });
        
        Thread t1 = Thread::New([&]{
			TimeWatcher w = TimeWatcher::New();
			w->start();
			auto v = future->getResult<String>();
			auto ret = w->stop();
			if(ret < 95 || ret > 105) {
				TEST_FAIL("Filament Future GetInThread case1");
			}
		});
		t1->start();
		
		t1->join();
		croutine->shutdown();
		croutine->awaitTermination();
        break;
    }

    TEST_OK("Filament Future GetInThread case100");
  }
