#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_PeekFirst() {
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
          list->peekFirst();
          auto r = w->stop();
          if(r > 5) {
              TEST_FAIL("ConcurrentLinkedList peekFirst case1,cost is %d",r);
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 2) {
          TEST_FAIL("ConcurrentLinkedList peekFirst case2");
      }
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
          list->peekFirst();
          auto r = w->stop();
          if(r < 95 || r > 105) {
              TEST_FAIL("ConcurrentLinkedList peekFirst case3,cost is %d",r);
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 2) {
          TEST_FAIL("ConcurrentLinkedList peekFirst case4");
      }
      break;
    }

    TEST_OK("ConcurrentLinkedList peekFirst case100");
}
