#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Float.hpp"
#include "Float.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapGetPrimitive() {

    //void put(T t,U u)/get(T t)
    while(1) {
      HashMap<int,int> map = createHashMap<int,int>();
      map->put(1,100);
      map->put(2,200);

      FetchRet(isFind,value) = map->getPrimitive(1);
      if(!isFind) {
        TEST_FAIL("[HashMap GetPrimitive case1]");
      }

      if(value != 100) {
        TEST_FAIL("[HashMap GetPrimitive case2]");
      }

      FetchRet(isFind2,ignore) = map->getPrimitive(100);
      if(isFind2) {
        TEST_FAIL("[HashMap GetPrimitive case3]");
      }
      break;
    }

    TEST_OK("[HashMap GetPrimitive case100]");
}
