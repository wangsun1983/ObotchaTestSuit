#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentStack.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentStack_Size() {
    while(1) {
      ConcurrentStack<String> list = createConcurrentStack<String>();
      Thread t1 = createThread([&]{
          for(int i = 0;i < 32*1024;i++) {
              list->push(createString(i));
          }
      });
      
      Thread t2 = createThread([&]{
          for(int i = 0;i < 32*1024;i++) {
              list->push(createString(i));
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(list->size() != 64*1024) {
          TEST_FAIL("ConcurrentStack size case1");
      }
      break;
    }

    TEST_OK("ConcurrentStack size case100");
}
