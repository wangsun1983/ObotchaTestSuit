#include <stdio.h>
#include <unistd.h>

#include "ReadWriteLock.hpp"
#include "Runnable.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "AtomicInteger.hpp"
#include "TimeWatcher.hpp"

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
        printf("---[TestReadLock ReadLock TryLock case1] [FAIL]--- \n");
      }
      value->incrementAndGet();
    });
    t->start();
    usleep(1000);

    if(value->get() != 1) {
      printf("---[TestReadLock ReadLock TryLock case2] [FAIL]--- \n");
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
        printf("---[TestReadLock ReadLock TryLock case3] [FAIL]--- ret is %d\n",ret);
      }
      value->incrementAndGet();
    });
    t->start();
    usleep(1000);

    if(value->get() != 1) {
      printf("---[TestReadLock ReadLock TryLock case4] [FAIL]--- \n");
    }
    break;
  }

  printf("---[TestReadLock ReadLock TryLock case100] [OK]--- \n");
}
