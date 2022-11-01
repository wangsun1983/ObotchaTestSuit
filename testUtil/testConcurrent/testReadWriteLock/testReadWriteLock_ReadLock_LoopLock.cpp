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

void testReadLock_LoopLock() {

  ReadWriteLock rwlock = createReadWriteLock();
  auto readlock = rwlock->getReadLock();
  auto writelock = rwlock->getWriteLock();
  readlock->lock();
  writelock->lock();
  readlock->lock();
  writelock->lock();
  TEST_OK("[TestReadWriteLock  LoopLock case100]");
}
