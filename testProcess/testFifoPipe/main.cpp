#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "FifoPipe.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"
#include "Error.hpp"

using namespace obotcha;

extern void testSyncFifoPipe();
extern void testFifoPipeAsync();

int main() {
  
  testFifoPipeAsync();

  testSyncFifoPipe();
  return 0;
}
