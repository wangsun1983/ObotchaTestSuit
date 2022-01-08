#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(KeyData) {
public:
  uint64_t value;

  uint64_t hashcode() {
      return value;
  }
};

void testHashMapKeyCompare() {
    HashMap<KeyData,String> map = createHashMap<KeyData,String>();
    KeyData k = createKeyData();
    k->value = 100;

    map->put(k,createString("hello world"));

    KeyData k2 = createKeyData();
    k2->value = 100;

    String v1 = map->get(k2);
    if(v1 != nullptr) {
        TEST_FAIL("[HashMap KeyCompare Test case1]");
        return;
    }

    KeyData k3 = createKeyData();
    k3->value = 1;
    String v3 = map->get(k3);
    if(v3 != nullptr) {
        TEST_FAIL("[HashMap KeyCompare Test case3]");
        return;
    }

    TEST_OK("[HashMap KeyCompare Test case4]");
    return;

}
