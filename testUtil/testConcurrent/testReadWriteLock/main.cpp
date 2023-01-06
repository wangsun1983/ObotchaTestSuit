#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "Integer.hpp"
#include "AutoLock.hpp"
#include "Mutex.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testReadLock_Lock();
extern void testWriteLock_Lock();
extern void testReadWriteLock_Lock();
extern void testReadLock_TryLock();
extern void testWriteLock_TryLock();
extern void testReadWriteLock_Acquire();
extern void testReadLock_LoopLock();
extern void testReadLock_LockTimeout();
extern void testWriteLock_LockTimeout();
extern void testReadWriteLock_GetName();

int main() {
  testReadLock_LockTimeout();
  testWriteLock_LockTimeout();
  testReadLock_LoopLock();
  testReadWriteLock_Acquire();
  testReadLock_Lock();
  testWriteLock_Lock();
  testReadWriteLock_Lock();
  testReadLock_TryLock();
  testWriteLock_TryLock();
  testReadWriteLock_GetName();
  return 1;
}
