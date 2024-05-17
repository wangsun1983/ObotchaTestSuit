#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_putLast() {
    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      list->putLast(String::New("bbcc"));
      
      Thread t1 = Thread::New([&]{
          list->acquireReadLock()->lock();
          usleep(200*1000);
          list->takeFirst();
          list->acquireReadLock()->unlock();
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          list->putLast(String::New("a"));
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList putLast case1,cost is %d",r);
          }
          
          if(list->size() != 1) {
              TEST_FAIL("ConcurrentLinkedList putLast case2");
          }
          
          if(!list->takeFirst()->equals(String::New("a"))) {
              TEST_FAIL("ConcurrentLinkedList putLast case3");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      list->putLast(String::New("bbcc"));
      
      Thread t1 = Thread::New([&]{
          list->syncWriteAction([&]{
              usleep(200*1000);
              list->takeFirst();
          });
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          list->putLast(String::New("a"));
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList putLast case4,cost is %d",r);
          }
          
          if(list->size() != 1) {
              TEST_FAIL("ConcurrentLinkedList putLast case5");
          }
          
          if(!list->takeFirst()->equals(String::New("a"))) {
              TEST_FAIL("ConcurrentLinkedList putLast case6");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    TEST_OK("ConcurrentLinkedList putLast case100");
}
