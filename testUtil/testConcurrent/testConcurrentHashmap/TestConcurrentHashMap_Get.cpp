#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashMap.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentHashMap_Get() {
    while(1) {
      ConcurrentHashMap<String,String> map = ConcurrentHashMap<String,String>::New();
      Thread t1 = Thread::New([&]{
        map->syncWriteAction([]{
            usleep(200*1000);
        });
      });

      Thread t2 = Thread::New([&map]{
        usleep(100*1000);
        TimeWatcher watch = TimeWatcher::New();
        watch->start();
        map->get(String::New("a"));
        auto ret = watch->stop();
        if(ret < 95 || ret > 105) {
            TEST_FAIL("ConcurrentHashMap Get case1");
        }
      });

      t1->start();
      t2->start();

      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ConcurrentHashMap Get test100");
}
