#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_Contains() {
    while(1) {
      ConcurrentHashSet<String> set = createConcurrentHashSet<String>();
      Thread t1 = createThread([&]{
          for(int i = 0;i < 1024*32;i++) {
              set->add(createString(i));
          }
      });
      
      int count = 0;
      Thread t2 = createThread([&]{
        for(int i = 0;i < 32*1024;i++) {
            while(1) {
                if(set->contains(createString(i))) {
                    count++;
                    break;
                }
                usleep(1000);
            }
        }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
    
      TimeWatcher w = createTimeWatcher();
      w->start();
      int ret = t2->join(500);
      auto cost = w->stop();
      
      if(ret != 0) {
        TEST_FAIL("ConcurrentHashMap Contains test1");
      }
      
      if(cost > 50) {
        TEST_FAIL("ConcurrentHashMap Contains test2");
      }
      
      if(count != 32*1024) {
        TEST_FAIL("ConcurrentHashMap Contains test3");
      }
      
      break;
    }

    TEST_OK("ConcurrentHashMap Contains test100");
}
