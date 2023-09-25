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

extern void testFilaMutexIsOwner();
extern void testFilaMutexLock();
extern void testMutexUnlock();
extern void testFilaMutexLockTimeout();

int main() {
  testFilaMutexLockTimeout();
  testMutexUnlock();
  testFilaMutexIsOwner();
  testFilaMutexLock();

  return 0;
}
