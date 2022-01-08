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
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(LoopThreadJoinRun1) IMPLEMENTS(Runnable) {
public:

  void run() {
      //value->incrementAndGet();
      //TEST_FAIL("sleep1 start");
      st(Thread)::interruptableSleep(5);
      //TEST_FAIL("sleep2 start");
  }
};

DECLARE_CLASS(LoopThreadJoinRun2) IMPLEMENTS(Runnable) {
public:

  void run() {
      //value->incrementAndGet();
      //TEST_FAIL("sleep1 start");
      sleep(1000);
      //TEST_FAIL("sleep2 start");
  }
};

void testThreadLoopJoin() {
  //test1
  ArrayList<Thread> list = createArrayList<Thread>();

  for(int i = 0;i<1024*32;i++) {
      Thread t = createThread(createLoopThreadJoinRun1());
      int ret = t->start();
      list->add(t);
  }
  
  for(int i = 0;i<1024*32;i++) {
      list->get(i)->join();
  }

  list->clear();
  //test2
  ArrayList<Thread> list2 = createArrayList<Thread>();

  for(int i = 0;i<1024*8;i++) {
      Thread t = createThread(createLoopThreadJoinRun2());
      int ret = t->start();
      list2->add(t);
  }

  for(int i = 0;i<1024*8;i++) {
      list2->get(i)->join(10);
  }
  
  for(int i = 0;i<1024*8;i++) {
      if(list2->get(i)->getStatus() != st(Thread)::Running) {
        TEST_FAIL("[Thread Test {Loop join()} special case1");
        break;
      }
  }
  
  list2->clear();

  TEST_OK("[Thread Test {Loop join()} special case2]");

}
