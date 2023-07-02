#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentStack.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testConcurrentStack_Pop() {
    while(1) {
      ConcurrentStack<String> list = createConcurrentStack<String>();
      for(int i = 0;i<64*1024;i++) {
          list->push(createString(i));
      }
      
      if(list->size() != 64*1024) {
          TEST_FAIL("ConcurrentStack pop case1");
      }
      
      ConcurrentHashMap<String,Boolean> maps = createConcurrentHashMap<String,Boolean>();
      Thread t1 = createThread([&]{
          while(list->size() != 0) {
            auto v = list->pop();
            if(v != nullptr) {
                maps->put(v,createBoolean(true));
            }
          }
      });
      
      Thread t2 = createThread([&]{
          while(list->size() != 0) {
            auto v = list->pop();
            if(v != nullptr) {
                maps->put(v,createBoolean(true));
            }
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(maps->size() != 64*1024) {
        TEST_FAIL("ConcurrentStack pop case2,size is %d",maps->size());
      }
      
      for(int i = 0;i < 64*1024;i++) {
        if(maps->get(createString(i)) == nullptr) {
            TEST_FAIL("ConcurrentStack pop case3,index is %d",i);
            break;
        }
      }
      break;
    }

    TEST_OK("ConcurrentStack pop case100");
}
