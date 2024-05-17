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
      ConcurrentHashMap<String,String> map = ConcurrentHashMap<String,String>::New();
      Thread t1 = Thread::New([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(String::New(i),String::New(i));
        }
      });

      Thread t2 = Thread::New([&map]{
        for(int i = 32*1024;i < 64*1024;i++) {
          map->put(String::New(i),String::New(i));
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
        auto value = map->get(String::New(i));
        if(!value->equals(String::New(i))) {
            TEST_FAIL("ConcurrentHashMap Put test2,i is %d,str is %s",i,value->toChars());
        }
      }
      break;
    }
    
    while(1) {
      ConcurrentHashMap<String,String> map = ConcurrentHashMap<String,String>::New();
      Thread t1 = Thread::New([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(String::New(i),String::New(i));
        }
      });

      Thread t2 = Thread::New([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(String::New(i),String::New(i*1024));
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
        auto value = map->get(String::New(i));
        if(!value->equals(String::New(i)) && !value->equals(String::New(i*1024))) {
            TEST_FAIL("ConcurrentHashMap Put test2");
        }
      }
      break;
    }
    
    while(1) {
        ConcurrentHashMap<String,String> map = ConcurrentHashMap<String,String>::New();
        Thread t1 = Thread::New([&] {
            usleep(1000*100);
            TimeWatcher watcher = TimeWatcher::New();
            watcher->start();
            map->put(String::New("a"),String::New("b"));
            auto cost = watcher->stop();
            if(cost < 95 || cost > 105) {
                TEST_FAIL("ConcurrentHashMap Put test3,cost is %d",cost);
            }
        });
        
        Thread t2 = Thread::New([&] {
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
