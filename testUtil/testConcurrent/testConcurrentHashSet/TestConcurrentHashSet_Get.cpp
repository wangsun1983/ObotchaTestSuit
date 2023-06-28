#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_Get() {
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
          auto v = set->get(0);
          auto cost = w->stop();
          if(cost < 95||cost > 105) {
              TEST_FAIL("ConcurrentHashMap Get case1,cost is %d",cost);
          }
          
          if(!set->contains(v)) {
              TEST_FAIL("ConcurrentHashMap Get case2");
          }
      });
      
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set->size() != 3) {
          TEST_FAIL("ConcurrentHashMap Get case3 size is %d",set->size());
      }
      
      if(!set->contains(createString("a")) 
        || !set->contains(createString("c"))
        ||  !set->contains(createString("b"))) {
          TEST_FAIL("ConcurrentHashMap Get case4");
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
          auto v = set->get(0);
          auto cost = w->stop();
          if(cost > 5) {
              TEST_FAIL("ConcurrentHashMap Get case5,cost is %d",cost);
          }
          
          if(!set->contains(v)) {
              TEST_FAIL("ConcurrentHashMap Get case6");
          }
      });
      
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set->size() != 3) {
          TEST_FAIL("ConcurrentHashMap Get case7 size is %d",set->size());
      }
      
      if(!set->contains(createString("a")) 
        || !set->contains(createString("c"))
        ||  !set->contains(createString("b"))) {
          TEST_FAIL("ConcurrentHashMap Get case8");
      }
      break;
    }
    
    TEST_OK("ConcurrentHashMap Get test100");
}
