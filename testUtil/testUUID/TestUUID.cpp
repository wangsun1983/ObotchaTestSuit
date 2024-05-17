#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
    //String toValue();
    UUID uuid = UUID::New();
    HashMap<String,Integer> map = HashMap<String,Integer>::New();

    for(int i = 0;i<1024*1024;i++) {
          UUID uuid = UUID::New();
          String s = uuid->generate();
          if(map->get(s) != nullptr) {
              TEST_FAIL("[UUID Test case0]");
          }
          map->put(s,Integer::New(0));
    }

    TEST_OK("[UUID Test case2]");

    for(int i = 0;i<1024*1024;i++) {
          UUID uuid = UUID::New(st(UUID)::Type::Random);
          String s = uuid->generate();
          if(map->get(s) != nullptr) {
              TEST_FAIL("[UUID Test case3]");
          }
          map->put(s,Integer::New(0));
    }
    TEST_OK("[UUID Test case3]");

    for(int i = 0;i<1024*1024;i++) {
          UUID uuid = UUID::New(st(UUID)::Type::Time);
          String s = uuid->generate();
          if(map->get(s) != nullptr) {
              TEST_FAIL("[UUID Test case4]");
          }
          map->put(s,Integer::New(0));
    }
    TEST_OK("[UUID Test case5]");

    for(int i = 0;i<1024*1024;i++) {
          UUID uuid = UUID::New(st(UUID)::Type::TimeSafe);
          String s = uuid->generate();
          if(map->get(s) != nullptr) {
              TEST_FAIL("[UUID Test case6]");
          }
          map->put(s,Integer::New(0));
    }

    TEST_OK("[UUID Test case100]");
}
