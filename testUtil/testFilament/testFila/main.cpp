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

extern void testSimpleSleep();
extern void testSleepInThread();
extern void testSleepInterrupt();

int main() {
  testSleepInterrupt();
  testSleepInThread();
  testSimpleSleep();
  return 0;
}
