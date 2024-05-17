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
      HashSet<String> set = HashSet<String>::New();
      set->add(String::New("a"));
      set->add(String::New("b"));
      set->add(String::New("c"));
      
      ConcurrentHashSet<String> set2 = ConcurrentHashSet<String>::New();
      set2->add(String::New("e"));
      set2->add(set);
      
      if(set2->size() != 4) {
          TEST_FAIL("ConcurrentHashMap Add Hashset case1,size is %d",set2->size());
      }
      
      if(!set2->contains(String::New("a")) ||!set2->contains(String::New("b"))
        ||!set2->contains(String::New("c")) || !set2->contains(String::New("e"))) {
            TEST_FAIL("ConcurrentHashMap Add Hashset case2");
      }
      break;
    }
    
    while(1) {
      HashSet<String> set = HashSet<String>::New();
      set->add(String::New("a"));
      set->add(String::New("b"));
      set->add(String::New("c"));
      
      ConcurrentHashSet<String> set2 = ConcurrentHashSet<String>::New();
      
      Thread t1 = Thread::New([&]{
          set2->acquireReadLock()->lock();
          usleep(1000*200);
          set2->acquireReadLock()->unlock();
      });
      
      Thread t2 = Thread::New([&]{
          usleep(100*1000);
          TimeWatcher w = TimeWatcher::New();
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
      
      if(!set2->contains(String::New("a")) ||!set2->contains(String::New("b"))
        ||!set2->contains(String::New("c"))) {
            TEST_FAIL("ConcurrentHashMap Add Hashset case5");
      }
      break;
    }

    TEST_OK("ConcurrentHashMap Add Hashset case100");
}
