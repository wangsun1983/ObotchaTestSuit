#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_putFirst() {
    while(1) {
      ConcurrentLinkedList<String> list = createConcurrentLinkedList<String>();
      list->putFirst(createString("bbcc"));
      
      Thread t1 = createThread([&]{
          list->acquireReadLock()->lock();
          usleep(200*1000);
          list->takeFirst();
          list->acquireReadLock()->unlock();
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          list->putFirst(createString("a"));
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList putFirst case1,cost is %d",r);
          }
          
          if(list->size() != 1) {
              TEST_FAIL("ConcurrentLinkedList putFirst case2");
          }
          
          if(!list->takeFirst()->equals(createString("a"))) {
              TEST_FAIL("ConcurrentLinkedList putFirst case3");
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
      list->putFirst(createString("bbcc"));
      
      Thread t1 = createThread([&]{
          list->syncWriteAction([&]{
              usleep(200*1000);
              list->takeFirst();
          });
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          list->putFirst(createString("a"));
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList putFirst case4,cost is %d",r);
          }
          
          if(list->size() != 1) {
              TEST_FAIL("ConcurrentLinkedList putFirst case5");
          }
          
          if(!list->takeFirst()->equals(createString("a"))) {
              TEST_FAIL("ConcurrentLinkedList putFirst case6");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    TEST_OK("ConcurrentLinkedList putFirst case100");
}
