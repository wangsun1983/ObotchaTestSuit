#include <stdio.h>
#include <unistd.h>

#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Thread.hpp"
#include "SpinLock.hpp"
#include "AutoLock.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"
#include "Mutex.hpp"
#include "SpinLock.hpp"

using namespace obotcha;

void testAutoLockSpinlock() {
	while(1) {
		SpinLock mutex = createSpinLock();

		Thread t = createThread([&]{
		  AutoLock l(mutex);
			usleep(200*1000);
		});
		t->start();

		usleep(100*1000);
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		AutoLock l(mutex);
		long v = watcher->stop();
		if(v < 95 || v > 105) {
			TEST_FAIL("[TestAutoLock Spinlock case1],v is %d",v);
			break;
		}
		t->join();
		break;
	}

	TEST_OK("[TestAutoLock Spinlock case100]");
}
