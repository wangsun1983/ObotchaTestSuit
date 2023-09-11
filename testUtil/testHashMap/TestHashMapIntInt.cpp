#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Float.hpp"
#include "Float.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapIntInt() {

    //void put(T t,U u)/get(T t)
    while(1) {
      HashMap<int,Integer> map = createHashMap<int,Integer>();
      for(int i = 0;i < 1024;i++) {
        map->put(i,createInteger(i * 100));
      }

      if(map->size() != 1024) {
        TEST_FAIL("[HashMap <int,int> Test  case1]");
      }

      for(int i = 0;i < 1024;i++) {
        if(map->get(i)->toValue() != i * 100) {
          TEST_FAIL("[HashMap <int,int> Test  case2]");
        }
      }

      break;
    }

    while(1) {
      HashMap<int,Integer> map = createHashMap<int,Integer>();
      map->put(100,createInteger(222));
      if(map->get(100)->toValue() != 222) {
        TEST_FAIL("[HashMap <int,int> Test  case3]");
      }

      map->put(100,createInteger(333));
      if(map->get(100)->toValue() != 333) {
        TEST_FAIL("[HashMap <int,int> Test  case4]");
      }

      auto v = map->remove(100);
      if(v->toValue() != 333) {
        TEST_FAIL("[HashMap <int,int> Test  case5]");
      }
      break;
    }

    TEST_OK("[HashMap <int,int> Test  case100]");
}
