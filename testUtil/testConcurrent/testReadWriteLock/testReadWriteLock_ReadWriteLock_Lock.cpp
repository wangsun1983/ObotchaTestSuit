#include <stdio.h>
#include <unistd.h>

#include "ReadWriteLock.hpp"
#include "Runnable.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "AtomicNumber.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testReadWriteLock_Lock() {
  TimeWatcher watcher = TimeWatcher::New();

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getReadLock()->lock();
    AtomicInteger value = AtomicInteger::New(0);
    Thread t = Thread::New([&value,&rwLock] {
        rwLock->getWriteLock()->lock();
        usleep(100*1000);
        value->incrementAndGet();
        rwLock->getWriteLock()->unlock();
    });

    Thread t1 = Thread::New([&value,&rwLock] {
        rwLock->getWriteLock()->lock();
        usleep(100*1000);
        value->incrementAndGet();
        rwLock->getWriteLock()->unlock();
    });

    Thread t2 = Thread::New([&value,&rwLock] {
        rwLock->getWriteLock()->lock();
        usleep(100*1000);
        value->incrementAndGet();
        rwLock->getWriteLock()->unlock();
    });

    t->start();
    t1->start();
    t2->start();

    rwLock->getReadLock()->unlock();
    watcher->start();
    t->join();
    t1->join();
    t2->join();
    long v = watcher->stop();

    if(value->get() != 3) {
      TEST_FAIL("[TestReadLock ReadWriteLock Lock case1]");
      break;
    }

    if(v < 300 || v > 305) {
      TEST_FAIL("[TestReadLock ReadWriteLock Lock case2]");
      break;
    }

    break;
  }

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getWriteLock()->lock();
    AtomicInteger value = AtomicInteger::New(0);
    Thread t = Thread::New([&value,&rwLock] {
        rwLock->getReadLock()->lock();
        usleep(100*1000);
        value->incrementAndGet();
		try {
			rwLock->getWriteLock()->unlock();
			TEST_FAIL("[TestReadLock ReadWriteLock Lock case3_1]");
		} catch(...) {}
    });

    Thread t1 = Thread::New([&value,&rwLock] {
        rwLock->getReadLock()->lock();
        usleep(100*1000);
        value->incrementAndGet();
        try {
        	rwLock->getWriteLock()->unlock();
        	TEST_FAIL("[TestReadLock ReadWriteLock Lock case3_2]");
        } catch(...) {}
    });

    Thread t2 = Thread::New([&value,&rwLock] {
        rwLock->getReadLock()->lock();
        usleep(100*1000);
        value->incrementAndGet();
        try {
        	rwLock->getWriteLock()->unlock();
        	TEST_FAIL("[TestReadLock ReadWriteLock Lock case3_3]");
        } catch(...) {}
    });

    t->start();
    t1->start();
    t2->start();

    rwLock->getWriteLock()->unlock();
    watcher->start();
    t->join();
    t1->join();
    t2->join();
    long v = watcher->stop();

    if(value->get() != 3) {
      TEST_FAIL("[TestReadLock ReadWriteLock Lock case3]");
      break;
    }

    if(v < 100 || v > 105) {
      TEST_FAIL("[TestReadLock ReadWriteLock Lock case4]");
      break;
    }

    break;
  }

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getWriteLock()->lock();
    rwLock->getWriteLock()->lock();
    rwLock->getReadLock()->lock();
    TEST_OK("[TestReadLock ReadWriteLock Lock case5]");
    break;
  }

  TEST_OK("[TestReadLock ReadWriteLock Lock case100]");
}
