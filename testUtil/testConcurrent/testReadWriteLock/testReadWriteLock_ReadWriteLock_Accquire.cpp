#include <stdio.h>
#include <unistd.h>

#include "ReadWriteLock.hpp"
#include "Runnable.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "AtomicInteger.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testReadWriteLock_Acquire() {
  TimeWatcher watcher = createTimeWatcher();

  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    rwLock->getReadLock()->lock();
    rwLock->getWriteLock()->lock();
    AtomicInteger value = createAtomicInteger(0);
    long start = st(System)::CurrentTimeMillis();
    Thread t = createThread([&value,&rwLock] {
        rwLock->getWriteLock()->lock();
        sleep(1);
        rwLock->getWriteLock()->unlock();
    });
    rwLock->getWriteLock()->unlock();
    rwLock->getReadLock()->unlock();
    t->start();
    t->join();
    long interval = st(System)::CurrentTimeMillis() - start;
    if(interval < 950 || interval > 1050) {
        TEST_FAIL("[TestReadLock ReadWriteLock Acquire case1],interval is %d",interval);
    }
    break;
  }


  TEST_OK("[TestReadLock ReadWriteLock Acquire case100]");
}
