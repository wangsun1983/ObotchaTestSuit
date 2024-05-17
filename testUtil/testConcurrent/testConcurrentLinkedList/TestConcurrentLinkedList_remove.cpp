#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentLinkedList.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentLinkedList_remove() {
    while(1) {
      ConcurrentLinkedList<String> list = ConcurrentLinkedList<String>::New();
      list->putFirst(String::New("bbcc"));
      
      Thread t1 = Thread::New([&]{
          list->acquireReadLock()->lock();
          usleep(200*1000);
          list->acquireReadLock()->unlock();
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          list->remove(String::New("bbcc"));
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList remove case1,cost is %d",r);
          }
          
          if(list->size() != 0) {
              TEST_FAIL("ConcurrentLinkedList remove case2");
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
      list->remove(String::New("bbcc"));
      
      Thread t1 = Thread::New([&]{
          list->syncWriteAction([&]{
              usleep(200*1000);
          });
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          list->remove(String::New("bbcc"));
          auto r = w->stop();
          if(r > 105 || r < 95) {
              TEST_FAIL("ConcurrentLinkedList remove case3,cost is %d",r);
          }
          
          if(list->size() != 0) {
              TEST_FAIL("ConcurrentLinkedList remove case4");
          }
      });
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    TEST_OK("ConcurrentLinkedList remove case100");
}
