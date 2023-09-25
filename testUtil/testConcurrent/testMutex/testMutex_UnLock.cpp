#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Integer.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "System.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

int testMutex_UnLock() {
    TimeWatcher watch = createTimeWatcher();

    while(1) {
		Mutex t = createMutex();
		Thread th = createThread([&t]{
			t->lock();
			usleep(300*1000);
			t->unlock();
		});
		th->start();
		usleep(100*1000);
		try {
			t->unlock();
			TEST_FAIL("[TestMutex UnLock case1]");
		} catch(...) {}
		th->join();
		break;
    }
	
	while(1) {
		auto mutex = createMutex();
		try {
			mutex->unlock();
			TEST_FAIL("[TestMutex UnLock case2]");
		} catch(...) {}
		break;
	}
	
	while(1) {
		auto mutex = createMutex();
		try {
			mutex->lock();
			mutex->unlock();
			
		} catch(...) {TEST_FAIL("[TestMutex UnLock case3]");}
		break;
	}

    TEST_OK("[TestMutex UnLock case100]");
    return 0;
}
