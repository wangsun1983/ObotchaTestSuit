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
          set->remove(String::New("b"));
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
      
      if(!set->contains(String::New("a")) || !set->contains(String::New("c"))) {
          TEST_FAIL("ConcurrentHashMap Remove case2");
      }
      break;
    }
    
    while(1) {
      ConcurrentHashSet<String> set = ConcurrentHashSet<String>::New();
      for(int i = 0;i < 32*1024;i++) {
          set->add(String::New(i));
      }
      
      Thread t1 = Thread::New([&]{
          for(int i = 0;i < 32*1024;i++) {
              set->remove(String::New(i));
          }
      });
      
      Thread t2 = Thread::New([&]{
          for(int i = 32*1024;i >0;i--) {
              set->remove(String::New(i));
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
