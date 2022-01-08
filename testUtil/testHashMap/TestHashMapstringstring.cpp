#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Boolean.hpp"
#include "Boolean.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapStringString() {
    while(1) {
      HashMap<std::string,std::string> map = createHashMap<std::string,std::string>();
      map->put("a","this is a");
      std::string v = map->get("a");
      if(v != "this is a") {
        TEST_FAIL("[HashMap<std::string,std::string>} test1]");
        break;
      }
      break;
    }

    while(1) {
      HashMap<std::string,std::string> map = createHashMap<std::string,std::string>();
      map->put("a","this is a");
      bool isException = false;
      try {
        std::string value = map->get("b");
      } catch(...) {
        isException = true;
      }

      if(!isException) {
        TEST_FAIL("[HashMap<std::string,std::string>} test2]");
      }
      break;
    }

    while(1) {
      HashMap<std::string,std::string> map = createHashMap<std::string,std::string>();
      map->put("a","this is a");
      map->put("a","this is not a");
      map->put("b","this is b");
      if(map->size() != 2) {
        TEST_FAIL("[HashMap<std::string,std::string>} test3]");
        break;
      }

      std::string v1 = map->get("a");
      std::string v2 = map->get("b");

      if(v1 != "this is not a" || v2 != "this is b") {
        TEST_FAIL("[HashMap<std::string,std::string>} test3]");
        break;
      }
      break;
    }

    TEST_OK("[HashMap<std::string,std::string>} test100]");
}
