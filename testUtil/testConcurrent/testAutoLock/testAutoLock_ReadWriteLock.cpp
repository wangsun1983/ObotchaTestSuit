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
#include "ReadWriteLock.hpp"

using namespace obotcha;

void testAutoLockReadWriteLock() {
	while(1) {
		ReadWriteLock rwlock = createReadWriteLock();

		Thread t = createThread([&]{
		  AutoLock l(rwlock->getWriteLock());
			usleep(200*1000);
		});
		t->start();

		usleep(100*1000);
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		AutoLock l(rwlock->getWriteLock());
		long v = watcher->stop();
		if(v < 100 || v > 105) {
			TEST_FAIL("[TestAutoLock ReadWriteLock case1],v is %d",v);
			break;
		}
		t->join();
		break;
	}

	while(1) {
		ReadWriteLock rwlock = createReadWriteLock();

		Thread t = createThread([&]{
		  AutoLock l(rwlock->getReadLock());
			usleep(200*1000);
		});
		t->start();

		usleep(100*1000);
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		AutoLock l(rwlock->getWriteLock());
		long v = watcher->stop();
		if(v < 100 || v > 105) {
			TEST_FAIL("[TestAutoLock ReadWriteLock case2],v is %d",v);
			break;
		}
		t->join();
		break;
	}

	while(1) {
		ReadWriteLock rwlock = createReadWriteLock();

		Thread t = createThread([&]{
		  AutoLock l(rwlock->getReadLock());
			usleep(200*1000);
		});
		t->start();

		usleep(100*1000);
		TimeWatcher watcher = createTimeWatcher();
		watcher->start();
		AutoLock l(rwlock->getReadLock());
		long v = watcher->stop();
		if(v < 0 || v > 5) {
			TEST_FAIL("[TestAutoLock ReadWriteLock case4],v is %d",v);
			break;
		}
		t->join();
		break;
	}

	TEST_OK("[TestAutoLock ReadWriteLock case100]");
}
