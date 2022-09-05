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
  printf("trace1 \n");
  readlock->lock();
  printf("trace2 \n");
  writelock->lock();
  printf("trace3 \n");
  readlock->lock();
  printf("trace4 \n");
  writelock->lock();
  TEST_OK("[TestReadWriteLock  LoopLock case100]");
}
