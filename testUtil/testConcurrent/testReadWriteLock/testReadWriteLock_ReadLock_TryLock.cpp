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

void testReadLock_TryLock() {
  TimeWatcher watcher = createTimeWatcher();

  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    rwLock->getWriteLock()->lock();
    AtomicInteger value = createAtomicInteger(0);
    Thread t = createThread([&rwLock,&value]{
      int ret = rwLock->getReadLock()->tryLock();
      if(ret != -EBUSY) {
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
    AtomicInteger value = createAtomicInteger(0);
    Thread t = createThread([&rwLock,&value]{
      int ret = rwLock->getReadLock()->tryLock();
      if(ret != 0) {
        TEST_FAIL("[TestReadLock ReadLock TryLock case3],ret is %d",ret);
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
  
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    auto readlock = rwLock->getReadLock();
    auto writelock = rwLock->getWriteLock();
    Thread t1 = createThread([&] {
        readlock->tryLock();
        int ret = readlock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock ReadLock TryLock case5],ret is %d",ret);
        }
        usleep(300*1000);
        readlock->unlock();
        readlock->unlock();
    });
    
    Thread t2 = createThread([&] {
        usleep(100*1000);
        int ret = readlock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock ReadLock TryLock case5],ret is %d",ret);
        }
        usleep(200*1000);
        readlock->unlock();
    });
    
    Thread t3 = createThread([&] {
        usleep(200*1000);
        TimeWatcher watcher = createTimeWatcher();
        watcher->start();
        writelock->lock();
        auto v = watcher->stop();
        if(v < 95 || v > 105) {
            TEST_FAIL("[TestReadLock ReadLock TryLock case6],v is %d",v);
        }
    });
    
    t1->start();
    t2->start();
    t3->start();
    
    t1->join();
    t2->join();
    t3->join();
    break;
  }
  
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    auto readlock = rwLock->getReadLock();
    auto writelock = rwLock->getWriteLock();
    Thread t1 = createThread([&] {
        readlock->tryLock();
        readlock->tryLock();
        usleep(200*1000);
        readlock->unlock();
        usleep(100*1000);
        readlock->unlock();
    });
    
    Thread t2 = createThread([&] {
        usleep(100*1000);
        int ret = writelock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock ReadLock TryLock case7],ret is %d",ret);
        }
        
        usleep(150*1000);
        ret = writelock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock ReadLock TryLock case8],ret is %d",ret);
        }
        
        usleep(200*1000);
        ret = writelock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock ReadLock TryLock case9],ret is %d",ret);
        }
    });
    
    t1->start();
    t2->start();
    
    t1->join();
    t2->join();
    break;
  }
  
  TEST_OK("[TestReadLock ReadLock TryLock case100]");
}
