#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaCroutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace std;
using namespace obotcha;

CountDownLatch latch = createCountDownLatch(150);

int main(void) {
    FilaCroutine croutine = createFilaCroutine();
    croutine->start();

    croutine->submit([] {
      for(int i = 0;i<50;i++) {
          latch->countDown();
          poll(NULL, 0, 500);
      }
    });

    croutine->submit([] {
      for(int i = 0;i<50;i++) {
          latch->countDown();
          poll(NULL, 0, 1000);
      }
    });

    croutine->submit([] {
      for(int i = 0;i<50;i++) {
          latch->countDown();
          poll(NULL, 0, 200);
      }
    });

    latch->await();

    TEST_OK("Filament simple lambda case100");
  }
