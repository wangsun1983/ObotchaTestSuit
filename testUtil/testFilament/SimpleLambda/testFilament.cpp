#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace std;
using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(150);

int main(void) {
    FilaRoutine croutine = FilaRoutine::New();
    croutine->start();

    croutine->execute([] {
      for(int i = 0;i<50;i++) {
          latch->countDown();
          poll(NULL, 0, 500);
      }
    });

    croutine->execute([] {
      for(int i = 0;i<50;i++) {
          latch->countDown();
          poll(NULL, 0, 1000);
      }
    });

    croutine->execute([] {
      for(int i = 0;i<50;i++) {
          latch->countDown();
          poll(NULL, 0, 200);
      }
    });

    latch->await();

    TEST_OK("Filament simple lambda case100");
  }
