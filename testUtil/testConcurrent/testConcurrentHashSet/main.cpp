#include <stdio.h>
#include <unistd.h>

#include "ConcurrentQueue.hpp"

using namespace obotcha;

extern void testConcurrentHashSet_Add();
extern void testConcurrentHashSet_Contains();
extern void testConcurrentHashSet_AddHashSet();
extern void testConcurrentHashSet_Clear();
extern void testConcurrentHashSet_Remove();
extern void testConcurrentHashSet_Get();
extern void testConcurrentHashSet_Size();

int main() {
  testConcurrentHashSet_Size();
  testConcurrentHashSet_Get();
  testConcurrentHashSet_Remove();
  testConcurrentHashSet_Add();
  testConcurrentHashSet_Contains();
  testConcurrentHashSet_AddHashSet();
  testConcurrentHashSet_Clear();
  return 0;
}
