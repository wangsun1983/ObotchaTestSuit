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

using namespace obotcha;

void testSpinlockTryLock() {
	TimeWatcher watcher = createTimeWatcher();

	while(1) {
		SpinLock l = createSpinLock();
		Thread t = createThread([l]{
			l->lock();
			usleep(200*1000);
			l->unlock();
		});
		t->start();
		usleep(100*1000);

		watcher->start();
		int ret = l->tryLock();
		long v = watcher->stop();
		if(v < 0 || v > 5) {
			TEST_FAIL("[TestSpinlock TryLock case1]");
			break;
		}

		if(ret != -EBUSY) {
			TEST_FAIL("[TestSpinlock TryLock case2],ret is %d \n",ret);
			break;
		}

		break;
	}

	while(1) {
		SpinLock l = createSpinLock();
		Thread t = createThread([&l]{
			l->tryLock();
			usleep(200*1000);
			l->unlock();
		});
		t->start();

		usleep(100*1000);
		watcher->start();
		l->lock();
		long v = watcher->stop();
		if(v < 95 || v > 105) {
			TEST_FAIL("[TestSpinlock TryLock case3],v is %d",v);
			break;
		}
		t->join();
		break;
	}

	TEST_OK("[TestSpinlock TryLock case100]");
}
