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
#include "AtomicNumber.hpp"

using namespace obotcha;

int testMutex_Lock() {
    TimeWatcher watch = TimeWatcher::New();

    while(1) {
      Mutex t = Mutex::New();
      watch->start();
      t->lock(100);
      t->lock(100);
      long result = watch->stop();
      if(result < 0 || result > 5) {
        TEST_FAIL("[TestMutex Lock case1]");
        break;
      }
      break;
    }

    while(1) {
      Mutex t = Mutex::New(st(Lock)::Type::Normal);
      watch->start();
      t->lock(100);
      t->lock(100);
      long result = watch->stop();
      if(result < 100 || result > 105) {
        TEST_FAIL("[TestMutex Lock case2]");
        break;
      }
      break;
    }
	
	while(1) {
	  Mutex t = Mutex::New(st(Lock)::Type::Normal);
	  watch->start();
	  t->lock(100);
	  t->lock(100);
	  t->lock(100);
	  long result = watch->stop();
	  if(result < 200 || result > 205) {
	    TEST_FAIL("[TestMutex Lock case2_1]");
	    break;
	  }
	  break;
	}

    while(1) {
      Mutex t = Mutex::New();
      Thread t1 = Thread::New([&t]{
        t->lock(300);
      });
      t1->start();
      usleep(100*1000);
      watch->start();
      long ret = t->lock(100);
      long result = watch->stop();
      if(ret != -ETIMEDOUT) {
        TEST_FAIL("[TestMutex Lock case3_1]");
        break;
      }

      if(result < 100 || result > 105) {
        TEST_FAIL("[TestMutex Lock case3]");
        break;
      }
      break;
    }

    while(1) {
      Mutex t = Mutex::New();
      AtomicInteger count = AtomicInteger::New(0);
      t->lock();

      Thread t1 = Thread::New([&t,&count]{
        t->lock();
        count->incrementAndGet();
      });
      t1->start();

      usleep(100*1000);
      if(count->get() != 0) {
        TEST_FAIL("[TestMutex Lock case4]");
        break;
      }
      t->unlock();
      usleep(10*1000);
      if(count->get() != 1) {
        TEST_FAIL("[TestMutex Lock case5]");
        break;
      }
      break;
    }
	
	while(1) {
		Mutex t = Mutex::New();
		t->lock();
		t->lock();
		
		Thread t1 = Thread::New([&] {
			t->lock();
		});
		t1->start();
		t->unlock();
		watch->start();
		t1->join(100);
		auto r = watch->stop();
		if(r < 95 || r > 105) {
			TEST_FAIL("[TestMutex Lock case6]");
		}
		
		watch->start();
		t->unlock();
		t1->join();
		r = watch->stop();
		if(r < 0 || r > 5) {
			TEST_FAIL("[TestMutex Lock case7]");
		}
		break;
	}
    TEST_OK("[TestMutex Lock case100]");
    return 0;
}
