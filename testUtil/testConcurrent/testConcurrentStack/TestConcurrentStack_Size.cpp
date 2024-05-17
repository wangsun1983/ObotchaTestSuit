#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentStack.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentStack_Size() {
    while(1) {
      ConcurrentStack<String> list = ConcurrentStack<String>::New();
      Thread t1 = Thread::New([&]{
          for(int i = 0;i < 32*1024;i++) {
              list->push(String::New(i));
          }
      });
      
      Thread t2 = Thread::New([&]{
          for(int i = 0;i < 32*1024;i++) {
              list->push(String::New(i));
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
