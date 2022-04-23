#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "PosixShareMemory.hpp"

using namespace obotcha;

extern void testPosixShareMemory();
extern void testPosixShareMemoryEpoll();

int main() {
  //testPosixShareMemoryEpoll();
  testPosixShareMemory();
  return 0;    
}
