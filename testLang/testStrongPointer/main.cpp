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


extern void testOperatorEqual();
extern void testNullCompare();

int main() {
  testOperatorEqual();
  testNullCompare();
  //while(1){}
  return 0;
}
