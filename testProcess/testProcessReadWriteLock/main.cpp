#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"

using namespace obotcha;
extern int testProcessReadWriteLock();
extern int testReadWriteLock();
extern int testWriteReadLock();
extern int testWriteWriteLock();
extern int testReadReadLock();
extern int testReadLockTimeout();
extern int testWriteLockTimeout();
extern int testWriteTryLock();
extern int testReadTryLock();
extern int testLockInThread();

int main() {
  if(testProcessReadWriteLock() == -1) {
	  return 0;
  }
  
  if(testReadWriteLock() == -1) {
	  return 0;
  }

  if(testWriteReadLock() == -1) {
	  return 0;
  }
  
  if(testWriteWriteLock() == -1) {
	  return 0;
  }
  
  if(testReadReadLock() == -1) {
	  return 0;
  }
  
  if(testReadLockTimeout() == -1) {
	  return 0;
  }
  
  if(testWriteLockTimeout() == -1) {
	  return 0;
  }
  
  if(testWriteTryLock() == -1) {
	  return 0;
  }
  
  if(testReadTryLock() == -1) {
	  return 0;
  }
  
  if(testLockInThread() == -1) {
	  return 0;
  }
  
  return 0;
}
