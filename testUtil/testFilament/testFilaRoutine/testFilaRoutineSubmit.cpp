#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"
#include "Fila.hpp"
#include "ForEveryOne.hpp"

using namespace std;
using namespace obotcha;

DECLARE_CLASS(MyFilament) IMPLEMENTS(Filament) {
public:
	void run() {
		count++;
	}
	
	static int count;
};
int _MyFilament::count = 0;

void testFilaRoutineSubmit() {
	//case1	
	while(1) {
		FilaRoutine croutine = FilaRoutine::New();
		croutine->start();
		auto f = croutine->submit([&] {
			st(FilaExecutorResult)::Set(123);
		});
		
		usleep(1000*10);
		if(f->getResult<int>() != 123) {
			TEST_FAIL("FilaMutex submit case1");
		}
		croutine->shutdown();
		croutine->awaitTermination();
		break;
	}
	
	while(1) {
		FilaRoutine croutine = FilaRoutine::New();
		croutine->start();
		FilaMutex m = FilaMutex::New();
		int count = 0;
		ArrayList<FilaFuture> list = ArrayList<FilaFuture>::New();
		for(int i = 0; i < 128;i ++) {
			auto f1 = croutine->submit([&,i] {
				AutoLock l(m);
				count++;
				st(FilaExecutorResult)::Set(i);
			});
			list->add(f1);
		}
		usleep(1000*100);
		if(count != 128) {
			TEST_FAIL("FilaMutex submit case2,count is %d",count);
		}
		if(list->size() != 128) {
			TEST_FAIL("FilaMutex submit case3");
		}

		int index = 0;
		ForEveryOne(f,list) {
			if(f->getResult<int>() != index) {
				TEST_FAIL("FilaMutex submit case4,expect is %d,result is %d",index,f->getResult<int>());
			}
			index++;
		}
		croutine->shutdown();
		croutine->awaitTermination();
		break;
	}
	
	while(1) {
		FilaRoutine croutine = FilaRoutine::New();
		croutine->start();
		for(int i = 0 ; i < 128;i++) {
			croutine->submit(MyFilament::New());
		}
		usleep(1000*10);
		croutine->shutdown();
		croutine->awaitTermination();
		if(st(MyFilament)::count != 128) {
			TEST_FAIL("FilaMutex submit case5,count is %d",st(MyFilament)::count);
		}
		break;
	}
	
	TEST_OK("FilaMutex submit case100");
}
