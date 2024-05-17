#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentStack.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentStack_SyncWriteAction() {
    while(1) {
      ConcurrentStack<String> list = ConcurrentStack<String>::New();
      list->push(String::New("a"));
      Thread t1 = Thread::New([&]{
         list->syncWriteAction([]{
             usleep(200*1000);
         });
      });
      
      Thread t2 = Thread::New([&]{
         usleep(100*1000);
         TimeWatcher watcher = TimeWatcher::New();
         watcher->start();
         list->push(String::New("b"));
         auto ret = watcher->stop();
         if(ret < 95 || ret > 105) {
             TEST_FAIL("ConcurrentStack SyncWriteAction case1");
         }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }
    
    while(1) {
      ConcurrentStack<String> list = ConcurrentStack<String>::New();
      list->push(String::New("a"));
      Thread t1 = Thread::New([&]{
         list->syncWriteAction([]{
             usleep(200*1000);
         });
      });
      
      Thread t2 = Thread::New([&]{
         usleep(100*1000);
         TimeWatcher watcher = TimeWatcher::New();
         watcher->start();
         list->top();
         auto ret = watcher->stop();
         if(ret < 95 || ret > 105) {
             TEST_FAIL("ConcurrentStack SyncWriteAction case2");
         }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      break;
    }

    TEST_OK("ConcurrentStack SyncWriteAction case100");
}
