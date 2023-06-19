#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int remove_mark_value = 100;

DECLARE_CLASS(RemoveCaseRunnable) IMPLEMENTS(Runnable){
public:
  void run() {
    remove_mark_value = 1;
  }
};

DECLARE_CLASS(RemoveCaseRunnable1) IMPLEMENTS(Runnable){
public:
  void run() {
    remove_mark_value = 1;
  }
};

DECLARE_CLASS(RemoveCaseRunnable2) IMPLEMENTS(Runnable){
public:
  void run() {
    remove_mark_value = 2;
  }
};

void testHandlerRemoveRunnable() {
  HandlerThread t = createHandlerThread();
  t->start();

  while(1) {
    Handler h = createHandler(t->getLooper());
    RemoveCaseRunnable r = createRemoveCaseRunnable();
    h->postDelayed(1000,r);
    usleep(100*1000);

    h->removeCallbacks(r);

    int size = h->size();
    if(size != 0) {
      TEST_FAIL("[Handler Test {RemoveRunnable} case1],size is %d",size);
    }
    sleep(1);

    if(remove_mark_value != 100) {
      TEST_FAIL("[Handler Test {RemoveRunnable} case2]");
    }
    break;
  }

  while(1) {
    remove_mark_value = -1;
    Handler h = createHandler(t->getLooper());
    RemoveCaseRunnable1 r1 = createRemoveCaseRunnable1();
    RemoveCaseRunnable2 r2 = createRemoveCaseRunnable2();
    h->postDelayed(1000,r1);
    h->postDelayed(1000,r2);
    usleep(100*1000);
    h->removeCallbacks(r1);

    int size = h->size();
    if(size != 1) {
      TEST_FAIL("[Handler Test {RemoveRunnable} case3],size is %d",size);
    }
    sleep(1);

    if(remove_mark_value != 2) {
      TEST_FAIL("[Handler Test {RemoveRunnable} case4],remove_mark_value is %d",remove_mark_value);
    }
    break;
  }

  TEST_OK("[Handler Test {RemoveRunnable} case100]");
}
