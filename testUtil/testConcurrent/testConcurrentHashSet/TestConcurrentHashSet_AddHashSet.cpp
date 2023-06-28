#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_AddHashSet() {
    while(1) {
      HashSet<String> set = createHashSet<String>();
      set->add(createString("a"));
      set->add(createString("b"));
      set->add(createString("c"));
      
      ConcurrentHashSet<String> set2 = createConcurrentHashSet<String>();
      set2->add(createString("e"));
      set2->add(set);
      
      if(set2->size() != 4) {
          TEST_FAIL("ConcurrentHashMap Add Hashset case1,size is %d",set2->size());
      }
      
      if(!set2->contains(createString("a")) ||!set2->contains(createString("b"))
        ||!set2->contains(createString("c")) || !set2->contains(createString("e"))) {
            TEST_FAIL("ConcurrentHashMap Add Hashset case2");
      }
      break;
    }
    
    while(1) {
      HashSet<String> set = createHashSet<String>();
      set->add(createString("a"));
      set->add(createString("b"));
      set->add(createString("c"));
      
      ConcurrentHashSet<String> set2 = createConcurrentHashSet<String>();
      
      Thread t1 = createThread([&]{
          set2->acquireReadLock()->lock();
          usleep(1000*200);
          set2->acquireReadLock()->unlock();
      });
      
      Thread t2 = createThread([&]{
          usleep(100*1000);
          TimeWatcher w = createTimeWatcher();
          w->start();
          set2->add(set);
          auto r = w->stop();
          if(r < 95 || r > 105) {
              TEST_FAIL("ConcurrentHashMap Add Hashset case3");
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set2->size() != 3) {
          TEST_FAIL("ConcurrentHashMap Add Hashset case4");
      }
      
      if(!set2->contains(createString("a")) ||!set2->contains(createString("b"))
        ||!set2->contains(createString("c"))) {
            TEST_FAIL("ConcurrentHashMap Add Hashset case5");
      }
      break;
    }

    TEST_OK("ConcurrentHashMap Add Hashset case100");
}
