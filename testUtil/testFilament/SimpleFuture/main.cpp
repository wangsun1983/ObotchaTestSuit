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

int main() {
  testFutureGetInteger();
  testFutureGetUint32();
  testFutureGetString();
  return 0;
}
