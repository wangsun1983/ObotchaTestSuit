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

void testReadLock_UnlockException() {
  while(1) {
    ReadWriteLock rwLock = createReadWriteLock();
	try {
		rwLock->getWriteLock()->unlock();
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case1]");
	} catch(...) {}
	
	try {
		rwLock->getReadLock()->unlock();
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case2]");
	} catch(...) {}
	
	rwLock->getWriteLock()->lock();
	try {
		rwLock->getReadLock()->unlock();
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case3]");
	} catch(...) {
	}
	
	try {
		rwLock->getWriteLock()->unlock();
	} catch(...) {
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case4]");
	}
	
	rwLock->getReadLock()->lock();
	try {
		rwLock->getWriteLock()->unlock();
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case5]");
	} catch(...) {
	}
	
	try {
		rwLock->getReadLock()->unlock();
	} catch(...) {
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case6]");
	}
    
    break;
  }
  
  while(1) {
	  ReadWriteLock rwLock = createReadWriteLock();
	  rwLock->getReadLock()->lock();
	  try {
	  	rwLock->getReadLock()->unlock();
	  } catch(...) {
	  	TEST_FAIL("[TestReadLock ReadLock Lock Exception case7]");
	  }
	  
	  try {
	  	rwLock->getReadLock()->unlock();
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case8]");
	  } catch(...) {
	  	
	  }
	  
	  rwLock->getWriteLock()->lock();
	  try {
	  	rwLock->getWriteLock()->unlock();
	  } catch(...) {
	  	TEST_FAIL("[TestReadLock ReadLock Lock Exception case9]");
	  }
	  
	  try {
	  	rwLock->getWriteLock()->unlock();
		TEST_FAIL("[TestReadLock ReadLock Lock Exception case10]");
	  } catch(...) {
	  }
	  break;
  }

  TEST_OK("[TestReadLock ReadLock Lock Exception case100]");
}
