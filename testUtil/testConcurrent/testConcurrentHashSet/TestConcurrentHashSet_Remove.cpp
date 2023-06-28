#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_Remove() {
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
          set->remove(createString("b"));
          auto cost = w->stop();
          if(cost < 95||cost > 105) {
              TEST_FAIL("ConcurrentHashMap Remove case1");
          }
      });
      
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set->size() != 2) {
          TEST_FAIL("ConcurrentHashMap Remove case1 size is %d",set->size());
      }
      
      if(!set->contains(createString("a")) || !set->contains(createString("c"))) {
          TEST_FAIL("ConcurrentHashMap Remove case2");
      }
      break;
    }
    
    while(1) {
      ConcurrentHashSet<String> set = createConcurrentHashSet<String>();
      for(int i = 0;i < 32*1024;i++) {
          set->add(createString(i));
      }
      
      Thread t1 = createThread([&]{
          for(int i = 0;i < 32*1024;i++) {
              set->remove(createString(i));
          }
      });
      
      Thread t2 = createThread([&]{
          for(int i = 32*1024;i >0;i--) {
              set->remove(createString(i));
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set->size() != 0) {
          TEST_FAIL("ConcurrentHashMap Remove case3");
      }
      break;
    }

    TEST_OK("ConcurrentHashMap Remove test100");
}
