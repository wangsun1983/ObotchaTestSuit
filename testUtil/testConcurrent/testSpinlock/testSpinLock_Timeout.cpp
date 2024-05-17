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

void testSpinlockTimeout() {
	TimeWatcher watcher = TimeWatcher::New();

	while(1) {
		SpinLock l = SpinLock::New();
		Thread t = Thread::New([&]{
			l->lock();
			usleep(300*1000);
			l->unlock();
		});
		t->start();
		usleep(100*1000);

		watcher->start();
		l->lock(100);
		long v = watcher->stop();
		if(v < 95 || v > 115) {
			TEST_FAIL("[TestSpinlock LockTimeout case1],v is %d",v);
		}
		t->join();
		break;
	}
	
	while(1) {
		SpinLock l = SpinLock::New();
		watcher->start();
		l->lock(100);
		auto v = watcher->stop();
		if(v > 5) {
			TEST_FAIL("[TestSpinlock LockTimeout case2],v is %d",v);
		}
		break;
	}
	
	while(1) {
		SpinLock l = SpinLock::New();
		Thread t1 = Thread::New([&]{
			l->lock();
			usleep(1000*300);
			l->unlock();
		});
		t1->start();
		usleep(1000*20);
		
		int ret = l->lock(100);
		if(ret != -EBUSY) {
			TEST_OK("[TestSpinlock Lock Timeout case1],ret is %d",ret);
		}
		
		t1->join();
		break;
	}

	TEST_OK("[TestSpinlock Lock Timeout case100]");
}
