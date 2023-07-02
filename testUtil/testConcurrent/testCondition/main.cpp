#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "AutoLock.hpp"
#include "Integer.hpp"

using namespace obotcha;

extern void testConditionWait();
extern void testConditionNotify();
extern void testConditionNotifyAll();
extern void testConditionDoubleLock();
extern void testConditionWaitAutoLock();
extern void testConditionGetCount();
extern void testConditionWaitWithOwner();

int main() {
  testConditionGetCount();
  testConditionDoubleLock();
  testConditionWait();
  testConditionNotify();
  testConditionNotifyAll();
  testConditionWaitAutoLock();
  testConditionWaitWithOwner();
  return 0;
}
