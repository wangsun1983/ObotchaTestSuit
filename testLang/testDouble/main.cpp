#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Double.hpp"
#include "StrongPointer.hpp"

using namespace obotcha;

extern void basetest();
extern void equaltest();
extern void testToString();
extern void hashtest();
extern void compareTest();

int main() {
  basetest();
  equaltest();
  testToString();
  hashtest();
  compareTest();
  return 0;
}
