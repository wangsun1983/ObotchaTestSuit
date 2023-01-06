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

void testReadWriteLock_GetName() {
  
  ReadWriteLock rwLock = createReadWriteLock(createString("testLock"));
  if(!rwLock->getName()->equals("testLock")
    ||!rwLock->getReadLock()->getName()->equals("testLock")
    ||!rwLock->getWriteLock()->getName()->equals("testLock")) {
    TEST_FAIL("[TestReadLock ReadWriteLock GetName case1]");
  }

  TEST_OK("[TestReadLock ReadWriteLock GetName case100]");
}
