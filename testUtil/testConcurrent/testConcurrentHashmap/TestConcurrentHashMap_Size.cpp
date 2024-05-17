#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashMap.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentHashMap_Size() {
    while(1) {
      ConcurrentHashMap<String,String> map = ConcurrentHashMap<String,String>::New();
      Thread t1 = Thread::New([&map]{
        for(int i = 0;i < 32*1024;i++) {
          map->put(String::New(i),String::New(i));
        }
      });

      Thread t2 = Thread::New([&map]{
        for(int i = 32*1024;i < 64*1024;i++) {
          map->put(String::New(i),String::New(i));
        }
      });

      t1->start();
      t2->start();

      t1->join();
      t2->join();

      if(map->size() != 64*1024) {
          TEST_FAIL("ConcurrentHashMap Size test1");
      }
      break;
    }

    TEST_OK("ConcurrentHashMap Size test100");
}
