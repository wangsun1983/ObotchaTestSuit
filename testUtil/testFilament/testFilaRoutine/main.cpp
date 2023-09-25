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

extern void testFilaRoutineDestroy();

int main() {
  for(int i = 0;i < 1024;i++) {
	testFilaRoutineDestroy();
  }
  return 0;
}
