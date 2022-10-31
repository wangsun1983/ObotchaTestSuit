#include <stdio.h>
#include <unistd.h>

#include "ConcurrentQueue.hpp"


using namespace obotcha;

extern void testConcurrentHashMap_Size();
extern void testConcurrentHashMap_Get();

int main() {
  testConcurrentHashMap_Size();
  testConcurrentHashMap_Get();
  return 0;
}
