#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentStack.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testConcurrentStack_Push() {
    while(1) {
      ConcurrentStack<String> list = ConcurrentStack<String>::New();
      Thread t1 = Thread::New([&]{
          for(int i = 0;i < 32*1024;i++) {
              list->push(String::New(i));
          }
      });
      
      Thread t2 = Thread::New([&]{
          for(int i = 32*1024;i < 64*1024;i++) {
              list->push(String::New(i));
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 64*1024) {
          TEST_FAIL("ConcurrentStack push case1");
      }
      
      HashMap<String,Boolean> maps = HashMap<String,Boolean>::New();
      ForEveryOne(v,list) {
          maps->put(v,Boolean::New(true));
      }
      
      if(maps->size() != 64*1024) {
          TEST_FAIL("ConcurrentStack push case2");
      }
      
      for(int i = 0;i < 64*1024;i++) {
          if(maps->get(String::New(v)) == nullptr) {
              TEST_FAIL("ConcurrentStack push case3,index is %d",i);
              break;
          }
      }
      break;
    }

    TEST_OK("ConcurrentStack push case100");
}
