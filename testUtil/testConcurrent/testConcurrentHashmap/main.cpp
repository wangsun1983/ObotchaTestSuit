#include <stdio.h>
#include <unistd.h>

#include "ConcurrentQueue.hpp"


using namespace obotcha;

extern void testConcurrentHashMap_Size();
extern void testConcurrentHashMap_Get();
extern void testConcurrentHashMap_Remove();
extern void testConcurrentHashMap_Put();
extern void testConcurrentHashMap_SyncRead();
extern void testConcurrentHashMap_SyncWrite();

int main() {
  testConcurrentHashMap_SyncWrite();
  testConcurrentHashMap_SyncRead();
  testConcurrentHashMap_Put();
  testConcurrentHashMap_Size();
  testConcurrentHashMap_Get();
  testConcurrentHashMap_Remove();
  return 0;
}
