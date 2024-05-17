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
    HashMap<KeyData,String> map = HashMap<KeyData,String>::New();
    KeyData k = KeyData::New();
    k->value = 100;

    map->put(k,String::New("hello world"));

    KeyData k2 = KeyData::New();
    k2->value = 100;

    String v1 = map->get(k2);
    if(v1 != nullptr) {
        TEST_FAIL("[HashMap KeyCompare Test case1]");
        return;
    }

    KeyData k3 = KeyData::New();
    k3->value = 1;
    String v3 = map->get(k3);
    if(v3 != nullptr) {
        TEST_FAIL("[HashMap KeyCompare Test case3]");
        return;
    }

    TEST_OK("[HashMap KeyCompare Test case4]");
    return;

}
