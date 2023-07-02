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
      ConcurrentStack<String> list = createConcurrentStack<String>();
      Thread t1 = createThread([&]{
          for(int i = 0;i < 32*1024;i++) {
              list->push(createString(i));
          }
      });
      
      Thread t2 = createThread([&]{
          for(int i = 32*1024;i < 64*1024;i++) {
              list->push(createString(i));
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 64*1024) {
          TEST_FAIL("ConcurrentStack push case1");
      }
      
      HashMap<String,Boolean> maps = createHashMap<String,Boolean>();
      ForEveryOne(v,list) {
          maps->put(v,createBoolean(true));
      }
      
      if(maps->size() != 64*1024) {
          TEST_FAIL("ConcurrentStack push case2");
      }
      
      for(int i = 0;i < 64*1024;i++) {
          if(maps->get(createString(v)) == nullptr) {
              TEST_FAIL("ConcurrentStack push case3,index is %d",i);
              break;
          }
      }
      break;
    }

    TEST_OK("ConcurrentStack push case100");
}
