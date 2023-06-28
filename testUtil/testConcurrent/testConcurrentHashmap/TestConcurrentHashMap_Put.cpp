#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashMap.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentHashMap_Put() {
    while(1) {
      ConcurrentHashMap<String,String> map = createConcurrentHashMap<String,String>();
      Thread t1 = createThread([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(createString(i),createString(i));
        }
      });

      Thread t2 = createThread([&map]{
        for(int i = 32*1024;i < 64*1024;i++) {
          map->put(createString(i),createString(i));
        }
      });

      t1->start();
      t2->start();

      t1->join();
      t2->join();

      if(map->size() != 64*1024) {
          TEST_FAIL("ConcurrentHashMap Put test1");
      }
      
      for(int i = 0;i < 1024*64;i++) {
        auto value = map->get(createString(i));
        if(!value->equals(createString(i))) {
            TEST_FAIL("ConcurrentHashMap Put test2,i is %d,str is %s",i,value->toChars());
        }
      }
      break;
    }
    
    while(1) {
      ConcurrentHashMap<String,String> map = createConcurrentHashMap<String,String>();
      Thread t1 = createThread([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(createString(i),createString(i));
        }
      });

      Thread t2 = createThread([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(createString(i),createString(i*1024));
        }
      });

      t1->start();
      t2->start();

      t1->join();
      t2->join();

      if(map->size() != 32*1024) {
          TEST_FAIL("ConcurrentHashMap Put test3");
      }
      
      for(int i = 0;i < 1024*32;i++) {
        auto value = map->get(createString(i));
        if(!value->equals(createString(i)) && !value->equals(createString(i*1024))) {
            TEST_FAIL("ConcurrentHashMap Put test2");
        }
      }
      break;
    }
    
    while(1) {
        ConcurrentHashMap<String,String> map = createConcurrentHashMap<String,String>();
        Thread t1 = createThread([&] {
            usleep(1000*100);
            TimeWatcher watcher = createTimeWatcher();
            watcher->start();
            map->put(createString("a"),createString("b"));
            auto cost = watcher->stop();
            if(cost < 95 || cost > 105) {
                TEST_FAIL("ConcurrentHashMap Put test3,cost is %d",cost);
            }
        });
        
        Thread t2 = createThread([&] {
            map->acquireReadLock()->lock();
            usleep(200 * 1000);
            map->acquireReadLock()->unlock();
        });
        
        t1->start();
        t2->start();
        
        t1->join();
        t2->join();
        break;
    }
    
    TEST_OK("ConcurrentHashMap Put test100");
}
