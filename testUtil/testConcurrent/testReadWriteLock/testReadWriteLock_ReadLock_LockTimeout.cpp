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

void testReadLock_LockTimeout() {
  TimeWatcher watcher = TimeWatcher::New();

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    Thread t = Thread::New([&rwLock] {
        rwLock->getWriteLock()->lock();
        usleep(1000*500);
    });

    t->start();
    usleep(1000*100);
    
    watcher->start();
    int ret = rwLock->getReadLock()->lock(100);
    long interval = watcher->stop();
    if(ret == 0 || interval < 95 || interval > 105) {
        TEST_FAIL("[TestReadLock ReadLock Lock Timeout case1],ret is %d,interval is %ld",ret,interval);
    }
    t->join();
    break;
  }
  
  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    watcher->start();
    int ret = rwLock->getReadLock()->lock(100);
    long interval = watcher->stop();
    if(ret != 0 || interval > 5) {
        TEST_FAIL("[TestReadLock ReadLock Lock Timeout case2],ret is %d,interval is %ld",ret,interval);
    }
    break;
  }

  TEST_OK("[TestReadLock ReadLock Lock Timeout case100]");
}
