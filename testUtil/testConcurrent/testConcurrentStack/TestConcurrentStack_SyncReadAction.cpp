#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentStack.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentStack_SyncReadAction() {
    while(1) {
      ConcurrentStack<String> list = createConcurrentStack<String>();
      list->push(createString("a"));
      Thread t1 = createThread([&]{
         list->syncReadAction([]{
             usleep(200*1000);
         });
      });
      
      Thread t2 = createThread([&]{
         usleep(100*1000);
         TimeWatcher watcher = createTimeWatcher();
         watcher->start();
         list->push(createString("b"));
         auto ret = watcher->stop();
         if(ret < 95 || ret > 105) {
             TEST_FAIL("ConcurrentStack SyncReadAction case1");
         }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    while(1) {
      ConcurrentStack<String> list = createConcurrentStack<String>();
      list->push(createString("a"));
      Thread t1 = createThread([&]{
         list->syncReadAction([]{
             usleep(200*1000);
         });
      });
      
      Thread t2 = createThread([&]{
         usleep(100*1000);
         TimeWatcher watcher = createTimeWatcher();
         watcher->start();
         list->top();
         auto ret = watcher->stop();
         if(ret > 5) {
             TEST_FAIL("ConcurrentStack SyncReadAction case2");
         }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ConcurrentStack SyncReadAction case100");
}
