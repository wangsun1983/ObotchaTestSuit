#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Float.hpp"
#include "Float.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapAppend() {

    //void put(T t,U u)/get(T t)
    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      map->put(2,200);

      HashMap<int,int> map2 = createHashMap<int,int>();
      map2->put(3,300);
      map2->put(4,400);

      map->append(map2);

      if(map->size() != 4) {
        TEST_FAIL("[HashMap Append case1]");
      }

      if(map->get(1) != 100 || map->get(2) != 200
        ||map->get(3) != 300 || map->get(4) != 400) {
        TEST_FAIL("[HashMap Append case2]");
      }
      break;
    }

    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      map->put(2,200);

      HashMap<int,int> map2 = createHashMap<int,int>();
      map2->put(1,300);
      map2->put(2,400);

      map->append(map2);

      if(map->size() != 2) {
        TEST_FAIL("[HashMap Append case3]");
      }

      if(map->get(1) != 100 || map->get(2) != 200) {
        TEST_FAIL("[HashMap Append case4],v1 is %d,v2 is %d",map->get(1),map->get(2));
      }
      break;
    }

    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      HashMap<int,int> map2 = createHashMap<int,int>();
      map2->put(1,300);
      map2->put(2,400);

      map->append(map2);

      if(map->size() != 2) {
        TEST_FAIL("[HashMap Append case3]");
      }

      if(map->get(1) != 300 || map->get(2) != 400) {
        TEST_FAIL("[HashMap Append case5],v1 is %d,v2 is %d",map->get(1),map->get(2));
      }
      break;
    }

    TEST_OK("[HashMap Append case100]");
}
