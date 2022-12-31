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

void testWriteLock_LockTimeout() {
  TimeWatcher watcher = createTimeWatcher();
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    Thread t = createThread([&rwLock] {
        rwLock->getReadLock()->lock();
        usleep(500*1000);
    });
    t->start();
    usleep(1000*50);
    watcher->start();
    int ret = rwLock->getWriteLock()->lock(100);
    long interval = watcher->stop();
    if(ret == 0 || interval < 95 || interval > 105) {
        TEST_FAIL("[TestReadLock WriteLock Lock Timeout case1],ret is %d,interval is %ld",ret,interval);
    }
    t->join();
    break;
  }
  
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    watcher->start();
    int ret = rwLock->getWriteLock()->lock(100);
    long interval = watcher->stop();
    if(ret != 0 || interval > 5) {
        TEST_FAIL("[TestReadLock WriteLock Lock Timeout case2],ret is %d,interval is %ld",ret,interval);
    }
    break;
  }
 
  TEST_OK("[TestReadLock WriteLock Lock Timeout case100]");
}
