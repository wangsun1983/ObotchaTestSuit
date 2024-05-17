#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Mutex.hpp"
#include "AutoLock.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "InterruptedException.hpp"
#include "TestLog.hpp"


using namespace obotcha;



DECLARE_CLASS(JoinRun1) IMPLEMENTS(Runnable) {
public:

  void run() {

  }

};


void testThreadQuickJoin() {

  while(1) {
    for(int i = 0;i < 1024*32;i++) {
      Thread t = Thread::New(JoinRun1::New());
      t->start();
      t->join();
    }
    TEST_OK("[Thread Test {Quick Join()} case1]");
    break;
  }

}
