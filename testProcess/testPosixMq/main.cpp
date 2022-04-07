#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "PosixMq.hpp"
#include "System.hpp"

using namespace obotcha;

extern int testPosixMq();
extern void testPosixMqMultiClient();
extern void testAsyncPosixMq();
extern void testAsyncPosixMqLambda();

int main() {
  testAsyncPosixMqLambda();

  testAsyncPosixMq();

  testPosixMqMultiClient();

  testPosixMq();
  return 0;
}
