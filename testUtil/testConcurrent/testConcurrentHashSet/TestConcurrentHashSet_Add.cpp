#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashSet.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"
#include "Thread.hpp"

using namespace obotcha;

void testConcurrentHashSet_Add() {
    while(1) {
      ConcurrentHashSet<String> set = createConcurrentHashSet<String>();
      Thread t1 = createThread([&]{
          for(int i = 0;i < 1024*32;i++) {
              set->add(createString(i));
          }
      });
      
      Thread t2 = createThread([&]{
          for(int i = 0;i < 1024*32;i++) {
              set->add(createString(i));
          }
      });
      
      t1->start();
      t2->start();
      
      t1->join();
      t2->join();
      
      if(set->size() != 1024*32) {
          TEST_FAIL("ConcurrentHashMap Get test1,size is %d",set->size());
      }
      
      for(int i = 0;i < 1024*32;i++) {
            if(!set->contains(createString(i)))  {
                TEST_FAIL("ConcurrentHashMap Get test2,i is %d",i);
            }
      }
      break;
    }

    TEST_OK("ConcurrentHashMap Get test100");
}
