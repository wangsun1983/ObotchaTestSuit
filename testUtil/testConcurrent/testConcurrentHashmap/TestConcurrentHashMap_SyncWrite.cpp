#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashMap.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentHashMap_SyncWrite() {
    while(1) {
      ConcurrentHashMap<String,String> map = createConcurrentHashMap<String,String>();
      Thread t1 = createThread([&]{
        map->syncWriteAction([]{
            usleep(200*1000);
        });
      });

      Thread t2 = createThread([&map]{
        usleep(100*1000);
        TimeWatcher watch = createTimeWatcher();
        watch->start();
        map->put(createString("a"),createString("b"));
        auto ret = watch->stop();
        if(ret < 95 || ret > 105) {
            TEST_FAIL("ConcurrentHashMap SyncWrite case1");
        }
      });

      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }
    
    
    TEST_OK("ConcurrentHashMap SyncWrite test100");
}
