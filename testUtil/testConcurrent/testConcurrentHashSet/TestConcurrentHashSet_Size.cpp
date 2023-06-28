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
      ConcurrentHashSet<String> set = createConcurrentHashSet<String>();
      set->add(createString("a"));
      set->add(createString("b"));
      set->add(createString("c"));
      
      Thread t1 = createThread([&]{
          set->syncWriteAction([]{
             usleep(200*1000);
          });
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
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
      
      if(!set->contains(createString("a")) 
        || !set->contains(createString("c"))
        ||  !set->contains(createString("b"))) {
          TEST_FAIL("ConcurrentHashMap Size case4");
      }
      break;
    }
    
    while(1) {
      ConcurrentHashSet<String> set = createConcurrentHashSet<String>();
      set->add(createString("a"));
      set->add(createString("b"));
      set->add(createString("c"));
      
      Thread t1 = createThread([&]{
          set->syncReadAction([]{
             usleep(200*1000);
          });
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
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
