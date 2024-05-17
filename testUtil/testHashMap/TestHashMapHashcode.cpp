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
      return name->append(String::New(number))->hashcode();
    }

    bool equals(TestHashCodeData t) {
      return name->equals(t->name) && number == t->number;
    }
};

void testHashMapHashcode() {
    HashMap<TestHashCodeData,String> map = HashMap<TestHashCodeData,String>::New();
    map->put(TestHashCodeData::New(String::New("a"),1),String::New("this is a"));
    map->put(TestHashCodeData::New(String::New("b"),1),String::New("this is b"));

    String str = map->get(TestHashCodeData::New(String::New("a"),1));
    if(str == nullptr && !str->sameAs("this is a")) {
      TEST_FAIL("hashmap hashcode test case1");
    }

    String str2 = map->get(TestHashCodeData::New(String::New("b"),1));
    if(str2 == nullptr && !str2->sameAs("this is b")) {
      TEST_FAIL("hashmap hashcode test case2");
    }

    TEST_OK("hashmap hashcode test case100");
}
