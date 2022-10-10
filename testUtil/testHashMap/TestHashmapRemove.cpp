#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapRemove() {

    while(1) {
      HashMap<String,String> map = createHashMap<String,String>();
      map->put(createString("a"),createString("b"));

      auto value = map->remove(createString("a"));
      if(value == nullptr || !value->equals("b")) {
          TEST_FAIL("[HashMap Remove Test case1]");
      }
      break;
    }

    TEST_OK("[HashMap Remove Test case100]");
}
