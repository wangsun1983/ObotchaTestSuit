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
      });

      Thread t2 = createThread([&map]{
      });

      t1->start();
      t2->start();

      t1->join();
      t2->join();


      break;
    }

    TEST_OK("ConcurrentHashMap Get test100");
}
