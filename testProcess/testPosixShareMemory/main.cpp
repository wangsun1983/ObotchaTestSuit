#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ShareMemory.hpp"

using namespace obotcha;

extern void testShareMemory();
extern void testShareMemoryEpoll();
extern void testShareMemoryClose();
extern void testShareMemoryClear();

int main() {
  //testShareMemoryEpoll();
  testShareMemory();
  testShareMemoryClose();
  testShareMemoryClear();
  return 0;    
}
