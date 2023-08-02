#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Double.hpp"
#include "Double.hpp"
#include "TestLog.hpp"


using namespace obotcha;

DECLARE_CLASS(TestHashCodeData) {
public:
    _TestHashCodeData(String n,int num) {
      name = n;
      number = num;
    }

    String name;
    int number;

    uint64_t hashcode() {
      return name->append(createString(number))->hashcode();
    }

    bool equals(TestHashCodeData t) {
      return name->equals(t->name) && number == t->number;
    }
};

void testHashMapHashcode() {
    HashMap<TestHashCodeData,String> map = createHashMap<TestHashCodeData,String>();
    map->put(createTestHashCodeData(createString("a"),1),createString("this is a"));
    map->put(createTestHashCodeData(createString("b"),1),createString("this is b"));

    String str = map->get(createTestHashCodeData(createString("a"),1));
    if(str == nullptr && !str->sameAs("this is a")) {
      TEST_FAIL("hashmap hashcode test case1");
    }

    String str2 = map->get(createTestHashCodeData(createString("b"),1));
    if(str2 == nullptr && !str2->sameAs("this is b")) {
      TEST_FAIL("hashmap hashcode test case2");
    }

    TEST_OK("hashmap hashcode test case100");
}
