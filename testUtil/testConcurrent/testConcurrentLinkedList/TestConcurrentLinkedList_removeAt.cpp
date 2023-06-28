#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_removeAt() {
    while(1) {
      ConcurrentLinkedList<String> list = createConcurrentLinkedList<String>();
      list->putFirst(createString("bbcc"));
      
      Thread t1 = createThread([&]{
          list->acquireReadLock()->lock();
          usleep(200*1000);
          list->acquireReadLock()->unlock();
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          list->removeAt(0);
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList removeAt case1,cost is %d",r);
          }
          
          if(list->size() != 0) {
              TEST_FAIL("ConcurrentLinkedList removeAt case2");
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
      list->remove(createString("bbcc"));
      
      Thread t1 = createThread([&]{
          list->syncWriteAction([&]{
              usleep(200*1000);
          });
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          list->removeAt(0);
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList removeAt case3,cost is %d",r);
          }
          
          if(list->size() != 0) {
              TEST_FAIL("ConcurrentLinkedList removeAt case4");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    TEST_OK("ConcurrentLinkedList removeAt case100");
}
