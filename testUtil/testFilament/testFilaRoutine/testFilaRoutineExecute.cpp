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

DECLARE_CLASS(MyFilament2) IMPLEMENTS(Filament) {
public:
	void run() {
		count++;
	}
	
	static int count;
};
int _MyFilament2::count = 0;

void testFilaRoutineExecute() {
	//case1	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		FilaMutex m = createFilaMutex();
		int count = 0;
		for(int i = 0; i < 128;i ++) {
			croutine->execute([&,i] {
				AutoLock l(m);
				count++;
			});
		}
		usleep(1000*100);
		if(count != 128) {
			TEST_FAIL("FilaMutex execute case1,count is %d",count);
		}
		croutine->shutdown();
		croutine->awaitTermination();
		break;
	}
	
	while(1) {
		FilaRoutine croutine = createFilaRoutine();
		croutine->start();
		for(int i = 0 ; i < 128;i++) {
			croutine->execute(createMyFilament2());
		}
		croutine->shutdown();
		croutine->awaitTermination();
		if(st(MyFilament2)::count != 128) {
			TEST_FAIL("FilaMutex execute case2,count is %d",st(MyFilament2)::count);
		}
		break;
	}
	
	TEST_OK("FilaMutex execute case100");
}
