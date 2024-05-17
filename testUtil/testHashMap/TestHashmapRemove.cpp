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
      HashMap<String,String> map = HashMap<String,String>::New();
      map->put(String::New("a"),String::New("b"));

      auto value = map->remove(String::New("a"));
      if(value == nullptr || !value->sameAs("b")) {
          TEST_FAIL("[HashMap Remove Test case1]");
      }
      break;
    }

    TEST_OK("[HashMap Remove Test case100]");
}
