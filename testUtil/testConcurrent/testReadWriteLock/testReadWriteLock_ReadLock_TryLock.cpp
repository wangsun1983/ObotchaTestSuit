#include <stdio.h>
#include <unistd.h>

#include "ReadWriteLock.hpp"
#include "Runnable.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "AtomicInteger.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

void testReadLock_TryLock() {
  TimeWatcher watcher = createTimeWatcher();

  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    rwLock->getWriteLock()->lock();
    AtomicInteger value = createAtomicInteger();
    Thread t = createThread([&rwLock,&value]{
      int ret = rwLock->getReadLock()->tryLock();
      if(ret != -LockBusy) {
        TEST_FAIL("[TestReadLock ReadLock TryLock case1]");
      }
      value->incrementAndGet();
    });
    t->start();
    usleep(1000);

    if(value->get() != 1) {
      TEST_FAIL("[TestReadLock ReadLock TryLock case2]");
    }
    break;
  }

  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    rwLock->getReadLock()->lock();
    AtomicInteger value = createAtomicInteger();
    Thread t = createThread([&rwLock,&value]{
      int ret = rwLock->getReadLock()->tryLock();
      if(ret != 0) {
        TEST_FAIL("[TestReadLock ReadLock TryLock case3]");
      }
      value->incrementAndGet();
    });
    t->start();
    usleep(1000);

    if(value->get() != 1) {
      TEST_FAIL("[TestReadLock ReadLock TryLock case4]");
    }
    break;
  }

  TEST_OK("[TestReadLock ReadLock TryLock case100]");
}
