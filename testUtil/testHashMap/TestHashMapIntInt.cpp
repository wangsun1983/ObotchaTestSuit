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
      HashMap<int,int> map = createHashMap<int,int>();
      for(int i = 0;i < 1024;i++) {
        map->put(i,i * 100);
      }

      if(map->size() != 1024) {
        TEST_FAIL("[HashMap <int,int> Test  case1]");
      }

      for(int i = 0;i < 1024;i++) {
        if(map->get(i) != i * 100) {
          TEST_FAIL("[HashMap <int,int> Test  case2]");
        }
      }

      break;
    }

    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(100,222);
      if(map->get(100) != 222) {
        TEST_FAIL("[HashMap <int,int> Test  case3]");
      }

      map->put(100,333);
      if(map->get(100) != 333) {
        TEST_FAIL("[HashMap <int,int> Test  case4]");
      }

      auto v = map->remove(100);
      if(v != 333) {
        TEST_FAIL("[HashMap <int,int> Test  case5]");
      }

      try {
        auto v2 = map->get(100);
        TEST_FAIL("[HashMap <int,int> Test  case6]");
      } catch(...) {

      }

      break;
    }

    TEST_OK("[HashMap <int,int> Test  case100]");
}
