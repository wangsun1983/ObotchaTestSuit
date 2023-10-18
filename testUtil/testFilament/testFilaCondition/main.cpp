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

extern void testWaitTimeout();
extern void testNotify();
extern void testWaitCounts();
extern void testNotifyAll();
int main() {
	testNotifyAll();
   //testWaitCounts();
  //testNotify();
  //testWaitTimeout();
  return 0;
}
