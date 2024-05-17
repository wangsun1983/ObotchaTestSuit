#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_peekLast() {
    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      list->putFirst(String::New("100"));
      list->putFirst(String::New("20"));
      
      Thread t1 = Thread::New([&]{
          list->acquireReadLock()->lock();
          usleep(200*1000);
          list->acquireReadLock()->unlock();
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          auto v = list->peekLast();
          auto r = w->stop();
          if(r > 5) {
              TEST_FAIL("ConcurrentLinkedList peekLast case1,cost is %d",r);
          }
          
          if(!v->equals(String::New("100"))) {
              TEST_FAIL("ConcurrentLinkedList peekLast case2");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 2) {
          TEST_FAIL("ConcurrentLinkedList peekLast case3");
      }
      break;
    }
    
    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      list->putFirst(String::New("100"));
      list->putFirst(String::New("20"));
      
      Thread t1 = Thread::New([&]{
          list->syncWriteAction([]{
              usleep(200*1000);
          });
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          auto v = list->peekLast();
          auto r = w->stop();
          if(r < 95 || r > 105) {
              TEST_FAIL("ConcurrentLinkedList peekLast case4,cost is %d",r);
          }
          
          if(!v->equals(String::New("100"))) {
              TEST_FAIL("ConcurrentLinkedList peekLast case5");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 2) {
          TEST_FAIL("ConcurrentLinkedList peekLast case6");
      }
      break;
    }

    TEST_OK("ConcurrentLinkedList peekLast case100");
}
