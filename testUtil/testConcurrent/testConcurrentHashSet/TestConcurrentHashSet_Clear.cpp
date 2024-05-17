#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_Clear() {
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
          set->clear();
          auto cost = w->stop();
          if(cost < 95||cost > 105) {
              TEST_FAIL("ConcurrentHashMap Clear case1");
          }
      });
      
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ConcurrentHashMap Clear test100");
}
