#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_toArray() {
    while(1) {
      ConcurrentLinkedList<String> list = createConcurrentLinkedList<String>();
      list->putFirst(createString("100"));
      list->putFirst(createString("20"));
      
      Thread t1 = createThread([&]{
          list->acquireReadLock()->lock();
          usleep(200*1000);
          list->acquireReadLock()->unlock();
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          auto v = list->toArray();
          auto r = w->stop();
          if(r > 5) {
              TEST_FAIL("ConcurrentLinkedList toArray case1,cost is %d",r);
          }
          
          if(v->size() != 2) {
              TEST_FAIL("ConcurrentLinkedList toArray case2");
          }
          
          if(!v->get(0)->equals(createString("20")) || !v->get(1)->equals(createString("100"))) {
              TEST_FAIL("ConcurrentLinkedList toArray case3");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    while(1) {
      ConcurrentLinkedList<String> list = createConcurrentLinkedList<String>();
      list->putFirst(createString("100"));
      list->putFirst(createString("20"));
      
      Thread t1 = createThread([&]{
          list->syncWriteAction([]{
              usleep(200*1000);
          });
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          auto v = list->toArray();
          auto r = w->stop();
          if(r < 95 || r > 105) {
              TEST_FAIL("ConcurrentLinkedList toArray case4,cost is %d",r);
          }
          
          if(!v->get(0)->equals(createString("20")) || !v->get(1)->equals(createString("100"))) {
              TEST_FAIL("ConcurrentLinkedList toArray case5");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 2) {
          TEST_FAIL("ConcurrentLinkedList toArray case6");
      }
      break;
    }

    TEST_OK("ConcurrentLinkedList toArray case100");
}