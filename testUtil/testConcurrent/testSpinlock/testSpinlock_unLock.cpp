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

void testSpinlockunLock() {
	TimeWatcher w = TimeWatcher::New();
	
	while(1) {
		SpinLock l = SpinLock::New();
		Thread t1 = Thread::New([&]{
			l->lock();
			usleep(1000*300);
			l->unlock();
		});
		t1->start();
		usleep(1000*100);

		try {
			l->unlock();
			TEST_FAIL("[TestSpinlock unLock case1]");
		} catch(...){}
		t1->join();
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
		usleep(1000*100);
		
		Thread t2 = Thread::New([&]{
			l->lock(100);
		});
		t2->start();
		usleep(1000*100);
		try {
			l->unlock();
			TEST_FAIL("[TestSpinlock unLock case2]");
		} catch(...){}
		t1->join();
		t2->join();
		
		try {
			l->unlock();
			TEST_FAIL("[TestSpinlock unLock case3]");
		} catch(...){
		}
		
		l->lock();
		try {
			l->unlock();
		} catch(...){
			TEST_FAIL("[TestSpinlock unLock case4]");
		}
		break;
	}
	TEST_OK("[TestSpinlock unLock case100]");
}
