#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ProcessMq.hpp"
#include "System.hpp"

using namespace obotcha;

extern int testProcessMq();
extern void testProcessMqMultiClient();
extern void testAsyncProcessMq();
extern void testAsyncProcessMqLambda();

int main() {
  testAsyncProcessMqLambda();

   testAsyncProcessMq();
	
   testProcessMqMultiClient();
   testProcessMq();
   

  return 0;
}
