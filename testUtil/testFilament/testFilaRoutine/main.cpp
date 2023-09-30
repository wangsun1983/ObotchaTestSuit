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

extern void testFilaRoutineShutdown();
extern void testFilaRoutineAwait();
extern void testFilaRoutineGetSize();
extern void testFilaRoutineIsTerminated();
extern void testFilaRoutineSubmit();
extern void testFilaRoutineExecute();
extern void testFilaRoutineShutdownInSleep();

int main() {
  testFilaRoutineShutdownInSleep();
  testFilaRoutineExecute();
  testFilaRoutineSubmit();
  testFilaRoutineIsTerminated();
  testFilaRoutineGetSize();
  testFilaRoutineAwait();
  testFilaRoutineShutdown();
  return 0;
}
