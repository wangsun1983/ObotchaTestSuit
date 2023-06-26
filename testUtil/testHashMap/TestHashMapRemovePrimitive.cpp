#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Float.hpp"
#include "Float.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapRemovePrimitive() {

    //void put(T t,U u)/get(T t)
    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      map->put(2,200);

      FetchRet(isFind,value) = map->removePrimitive(1);
      if(!isFind) {
        TEST_FAIL("[HashMap removePrimitive case1]");
      }

      if(value != 100) {
        TEST_FAIL("[HashMap removePrimitive case2]");
      }

      if(map->size() != 1) {
        TEST_FAIL("[HashMap removePrimitive case3]");
      }

      FetchRet(isFind2,ignore) = map->getPrimitive(100);
      if(isFind2) {
        TEST_FAIL("[HashMap removePrimitive case4]");
      }
      break;
    }

    TEST_OK("[HashMap removePrimitive case100]");
}
