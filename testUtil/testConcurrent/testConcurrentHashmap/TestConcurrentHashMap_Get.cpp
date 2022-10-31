#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashMap.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentHashMap_Get() {
    while(1) {
      ConcurrentHashMap<String,String> map = createConcurrentHashMap<String,String>();
      map->put(createString("abc"),createString("abc"));
      Thread t1 = createThread([&map]{
          for(int i = 0;i < 1024*16;i++) {
                map->put(createString(i),createString(i));
          }
      });

      Thread t2 = createThread([&map]{
          for(int i = 1024*16;i < 1024*32;i++) {
                map->put(createString(i),createString(i));
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
