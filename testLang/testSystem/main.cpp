#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "System.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

#define CPU_NUMS 12

extern int normalTest();
extern void testArrayCopy();
extern void testExecute();
extern void testSleep();

int main() {
  testSleep();
  testArrayCopy();
  testExecute();
  //while(1){}
}
