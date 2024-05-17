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

void testWriteLock_TryLock() {
  TimeWatcher watcher = TimeWatcher::New();

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getWriteLock()->lock();
    AtomicInteger value = AtomicInteger::New(0);
    Thread t = Thread::New([&rwLock,&value]{
      int ret = rwLock->getWriteLock()->tryLock();
      if(ret != -EBUSY) {
        TEST_FAIL("[TestReadLock WriteLock TryLock case1]");
      }
      value->incrementAndGet();
    });
    t->start();
    usleep(1000*10);

    if(value->get() != 1) {
      TEST_FAIL("[TestReadLock WriteLock TryLock case2],value is %d",value->get());
    }
    break;
  }

  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    rwLock->getReadLock()->lock();
    AtomicInteger value = AtomicInteger::New(0);
    Thread t = Thread::New([&rwLock,&value]{
      int ret = rwLock->getWriteLock()->tryLock();
      if(ret != -EBUSY) {
        TEST_FAIL("[TestReadLock WriteLock TryLock case3]");
      }
      value->incrementAndGet();
    });
    t->start();
    usleep(1000);

    if(value->get() != 1) {
      TEST_FAIL("[TestReadLock WriteLock TryLock case4]");
    }
    break;
  }
  
  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    auto readlock = rwLock->getReadLock();
    auto writelock = rwLock->getWriteLock();
    
    Thread t1 = Thread::New([&]{
        writelock->tryLock();
        writelock->tryLock();
        usleep(200*1000);
        writelock->unlock();
        usleep(200*1000);
        writelock->unlock();
    });
    
    Thread t2 = Thread::New([&]{
        usleep(100*1000);
        TimeWatcher watcher = TimeWatcher::New();
        int ret = readlock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case5,ret is %d]",ret);
        }

        usleep(150*1000);
        ret = readlock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case6,ret is %d]",ret);
        }
        usleep(300*1000);
        ret = readlock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case7,ret is %d]",ret);
        }
    });
    
    t1->start();
    t2->start();
    
    t1->join();
    t2->join();
    break;
  }
  
  while(1) {
    ReadWriteLock rwLock = ReadWriteLock::New();
    auto readlock = rwLock->getReadLock();
    auto writelock = rwLock->getWriteLock();

    Thread t1 = Thread::New([&] {
        readlock->tryLock();
        int ret = writelock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case8,ret is %d]",ret);
        }
        
        ret = readlock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case9,ret is %d]",ret);
        }
        
        ret = writelock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case9,ret is %d]",ret);
        }
        
        usleep(200*1000);
        writelock->unlock();
        writelock->unlock();
        usleep(200*1000);
        readlock->unlock();
        usleep(200*1000);
        readlock->unlock();
    });
    
    Thread t2 = Thread::New([&] {
        usleep(100*1000);
        int ret = writelock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case10,ret is %d]",ret);
        }
        usleep(200*1000);
        ret = writelock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case11,ret is %d]",ret);
        }
        usleep(200*1000);
        ret = writelock->tryLock();
        if(ret != -EBUSY) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case12,ret is %d]",ret);
        }
        
        usleep(200*1000);
        ret = writelock->tryLock();
        if(ret != 0) {
            TEST_FAIL("[TestReadLock WriteLock TryLock case13,ret is %d]",ret);
        }
    });
    
    t1->start();
    t2->start();
    
    t1->join();
    t2->join();
    break;  
  }
  
  while(1) {
    TimeWatcher watcher = TimeWatcher::New();
    ReadWriteLock rwLock = ReadWriteLock::New();
    auto readlock = rwLock->getReadLock();
    auto writelock = rwLock->getWriteLock();
    Thread t1 = Thread::New([&] {
        writelock->tryLock();
    });    
    Thread t2 = Thread::New([&] {
        usleep(100*1000);
        writelock->lock(1000);
    });
    t1->start();
    t2->start();
    t1->join();
    watcher->start();
    t2->join();
    auto v = watcher->stop();
    if(v < 1095 || v > 1110) {
        TEST_FAIL("[TestReadLock WriteLock TryLock case14,v is %d]",v);
    }
    break;
  }

  TEST_OK("[TestReadLock WriteLock TryLock case100]");
}
