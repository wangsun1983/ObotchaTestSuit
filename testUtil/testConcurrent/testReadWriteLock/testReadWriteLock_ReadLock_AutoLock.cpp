#include <stdio.h>
#include <unistd.h>

#include "ReadWriteLock.hpp"
#include "Runnable.hpp"
#include "Thread.hpp"
#include "System.hpp"
#include "AtomicNumber.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "AutoLock.hpp"

using namespace obotcha;

void testReadLock_AutoLock() {
  TimeWatcher w = createTimeWatcher();
  
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    
    Thread t = createThread([&] {
		AutoLock l(rwLock->getReadLock());
		usleep(1000*200);
    });
	t->start();
	
    Thread t1 = createThread([&] {
		AutoLock l(rwLock->getWriteLock());
    });

    Thread t2 = createThread([&] {
		AutoLock l(rwLock->getWriteLock());
    });
	usleep(1000*100);
	t1->start();
	t2->start();
	
	w->start();
    t1->join();
	t2->join();
	auto ret = w->stop();
	if(ret < 95 || ret >105) {
		TEST_OK("[TestReadLock AutoLock case1]");
	}
	
    break;
  }
  
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    
    Thread t = createThread([&] {
  		AutoLock l(rwLock->getReadLock());
  		usleep(1000*200);
    });
  	t->start();
  	
    Thread t1 = createThread([&] {
  		AutoLock l(rwLock->getReadLock());
    });
  
    Thread t2 = createThread([&] {
  		AutoLock l(rwLock->getReadLock());
    });
  	usleep(1000*100);
  	t1->start();
  	t2->start();
  	
  	w->start();
    t1->join();
  	t2->join();
  	auto ret = w->stop();
  	if(ret >5) {
  		TEST_OK("[TestReadLock AutoLock case2]");
  	}
  	
    break;
  }

  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
    
    Thread t = createThread([&] {
  		AutoLock l(rwLock->getReadLock());
  		usleep(1000*200);
    });
  	t->start();
  	
    Thread t1 = createThread([&] {
  		AutoLock l(rwLock->getWriteLock());
		usleep(1000*300);
    });
	
	Thread t2 = createThread([&] {
		AutoLock l(rwLock->getWriteLock());
	});
  
  	usleep(1000*100);
  	t1->start();
  	t2->start();
  	
  	w->start();
    t1->join();
  	t2->join();
  	auto ret = w->stop();
  	if(ret < 395 || ret >405) {
  		TEST_OK("[TestReadLock AutoLock case3]");
  	}
    break;
  }
  
  TEST_OK("[TestReadLock AutoLock case100]");
}
