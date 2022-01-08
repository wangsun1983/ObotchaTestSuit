#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Boolean.hpp"
#include "Boolean.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapIntInt() {
    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      int v = map->get(1);
      if(v != 100) {
        TEST_FAIL("[HashMap<int,int>} test1]");
        break;
      }
      break;
    }

    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      bool isExcpetion = false;
      try {
        map->get(2);
      } catch(...) {
        isExcpetion = true;
      }

      if(!isExcpetion) {
        TEST_FAIL("[HashMap<int,int>} test2]");
        break;
      }
      break;
    }

    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      map->put(1,200);
      map->put(2,100);
      if(map->size() != 2) {
        TEST_FAIL("[HashMap<int,int>} test3]");
        break;
      }

      int v1 = map->get(1);
      int v2 = map->get(2);

      if(v1 != 200 || v2 != 100) {
        TEST_FAIL("[HashMap<int,int>} test4]");
        break;
      }
      break;
    }

    TEST_OK("[HashMap<int,int>} test100]");
}
