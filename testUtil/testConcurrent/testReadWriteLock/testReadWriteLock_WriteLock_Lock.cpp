#include <stdio.h>
#include <unistd.h>

#include "ReadWriteLock.hpp"
#include "Runnable.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "AtomicNumber.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testWriteLock_Lock() {
  TimeWatcher watcher = TimeWatcher::New();
  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getWriteLock()->lock();
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
    usleep(10*1000);
    watcher->start();
    rwLock->getWriteLock()->unlock();
    t->join();
    t1->join();
    t2->join();
    long v = watcher->stop();
    if(v < 300 || v > 305) {
      TEST_FAIL("[TestReadLock WriteLock Lock case1]");
      break;
    }
    if(value->get() != 3) {
      TEST_FAIL("[TestReadLock WriteLock Lock case2]");
      break;
    }
    break;
  }

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getWriteLock()->lock();
    rwLock->getWriteLock()->lock();
    TEST_OK("[TestReadLock WriteLock Lock case3]");
    break;
  }

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    Thread t = Thread::New([&rwLock]() {
      rwLock->getWriteLock()->lock();
      usleep(200*1000);
      rwLock->getWriteLock()->unlock();
    });
    t->start();
    usleep(100*1000);

    watcher->start();
    rwLock->getWriteLock()->lock(100);
    long v = watcher->stop();
    if(v < 100 || v > 105) {
      TEST_FAIL("[TestReadLock WriteLock Lock case4]");
      break;
    }
    t->join();
    break;
  }
  
  TEST_OK("[TestReadLock ReadLock Lock case100]");
}
