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

using namespace obotcha;

void testAutoLockMutex() {
	while(1) {
		Mutex mutex = Mutex::New();

		Thread t = Thread::New([&]{
		  AutoLock l(mutex);
			usleep(200*1000);
		});
		t->start();

		usleep(100*1000);
		TimeWatcher watcher = TimeWatcher::New();
		watcher->start();
		AutoLock l(mutex);
		long v = watcher->stop();
		if(v < 100 || v > 105) {
			TEST_FAIL("[TestAutoLock Mutex case1],v is %d",v);
			break;
		}
		t->join();
		break;
	}

	TEST_OK("[TestAutoLock Mutex case100]");
}
