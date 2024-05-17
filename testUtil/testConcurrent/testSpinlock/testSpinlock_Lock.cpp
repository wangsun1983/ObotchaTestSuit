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

using namespace obotcha;

void testSpinlockLock() {
	TimeWatcher watcher = TimeWatcher::New();
	watcher->start();
	watcher->stop();
	while(1) {
		SpinLock l = SpinLock::New();
		Thread t = Thread::New([&l]{
			l->lock();
			usleep(200*1000);
			l->unlock();
		});
		t->start();
		usleep(100*1000);

		watcher->start();
		l->lock();
		long v = watcher->stop();
		if(v < 95 || v > 105) {
			TEST_FAIL("[TestSpinlock Lock case1],v is %d",v);
		}
		l->unlock();
		t->join();
		break;
	}

	TEST_OK("[TestSpinlock Lock case100]");
}
