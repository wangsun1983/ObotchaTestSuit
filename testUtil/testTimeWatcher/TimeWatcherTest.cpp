#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {

  while(1) {
      TimeWatcher t = createTimeWatcher();
      t->start();
      sleep(5);
      //t->stop();
      long interval = t->stop();
      if(interval > 5005 || interval < 4995) {
          TEST_FAIL("[TimeWatcher Test {start/stop()} case1],interval is %ld",interval);
          break;
      }

      TEST_OK("[TimeWatcher Test {start/stop()} case1]");
      break;
  }
  

}
