#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_Size() {
    while(1) {
      ConcurrentHashSet<String> set = ConcurrentHashSet<String>::New();
      set->add(String::New("a"));
      set->add(String::New("b"));
      set->add(String::New("c"));
      
      Thread t1 = Thread::New([&]{
          set->syncWriteAction([]{
             usleep(200*1000);
          });
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          auto v = set->size();
          auto cost = w->stop();
          if(cost < 95||cost > 105) {
              TEST_FAIL("ConcurrentHashMap Size case1,cost is %d",cost);
          }
          
          if(v != 3) {
              TEST_FAIL("ConcurrentHashMap Size case2");
          }
      });
      
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set->size() != 3) {
          TEST_FAIL("ConcurrentHashMap Size case3 size is %d",set->size());
      }
      
      if(!set->contains(String::New("a")) 
        || !set->contains(String::New("c"))
        ||  !set->contains(String::New("b"))) {
          TEST_FAIL("ConcurrentHashMap Size case4");
      }
      break;
    }
    
    while(1) {
      ConcurrentHashSet<String> set = ConcurrentHashSet<String>::New();
      set->add(String::New("a"));
      set->add(String::New("b"));
      set->add(String::New("c"));
      
      Thread t1 = Thread::New([&]{
          set->syncReadAction([]{
             usleep(200*1000);
          });
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
          w->start();
          auto v = set->size();
          auto cost = w->stop();
          if(cost > 5) {
              TEST_FAIL("ConcurrentHashMap Size case5,cost is %d",cost);
          }
          
          if(v != 3) {
              TEST_FAIL("ConcurrentHashMap Size case6");
          }
      });
      
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    TEST_OK("ConcurrentHashMap Size case100");
}
