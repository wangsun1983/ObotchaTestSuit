#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Filament.hpp"
#include "TimeWatcher.hpp"

using namespace std;
using namespace obotcha;

extern void testFutureGetInteger();
extern void testFutureGetUint32();
extern void testFutureGetString();
extern void testFutureGetValue();
extern void testFutureWait();
extern void testFutureWake();

int main() {
  testFutureWake();
  testFutureGetInteger();
  testFutureGetUint32();
  testFutureGetString();
  testFutureGetValue();
  testFutureWait();
  return 0;
}
