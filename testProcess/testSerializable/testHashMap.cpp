#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestMapKey) IMPLEMENTS(Serializable) {
public:
    int v1;
    
    bool equals(MyTestMapKey s) {
        return v1 == s->v1;
    }

    DECLARE_REFLECT_FIELD(MyTestMapKey,v1);
};

DECLARE_CLASS(MyTestMapValue) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;

    bool equals(MyTestMapValue s) {
        return m1->equals(s->m1) && m2 == s->m2;
    }
    DECLARE_REFLECT_FIELD(MyTestMapValue,m1,m2);
};

DECLARE_CLASS(MyTestDataMap) IMPLEMENTS(Serializable) {
public:
    HashMap<MyTestMapKey,MyTestMapValue> map;

    DECLARE_REFLECT_FIELD(MyTestDataMap,map);
};

void testOrpcHashMap() {
    MyTestDataMap mm = MyTestDataMap::New();
    mm->map = HashMap<MyTestMapKey,MyTestMapValue>::New();

    MyTestMapKey key1 = MyTestMapKey::New();
    key1->v1 = 111;

    MyTestMapValue value1 = MyTestMapValue::New();
    value1->m1 = String::New("value1");
    value1->m2 = 111222;

    MyTestMapKey key2 = MyTestMapKey::New();
    key2->v1 = 222;

    MyTestMapValue value2 = MyTestMapValue::New();
    value2->m1 = String::New("value2");
    value2->m2 = 333444;

    mm->map->put(key1,value1);
    mm->map->put(key2,value2);

    ByteArray data = mm->serialize();

    
    MyTestDataMap result = DeSerialize<MyTestDataMap>(data);

    if(result->map->size() != mm->map->size()) {
        TEST_FAIL("testSerializable testHashmap case1");
    }

    auto keysets1 = result->map->keySet();
    auto keysets2 = mm->map->keySet();
    for(int i = 0;i < keysets1->size();i++) {
        auto v1 = keysets1->get(i);
        auto v2 = keysets2->get(keysets1->size() - i - 1);
        if(!v1->equals(v2)) {
            TEST_FAIL("testSerializable testHashmap case2");
            break;
        }
    }

    auto entrySets1 = result->map->entrySet();
    auto entrySets2 = mm->map->entrySet();
    for(int i = 0;i < entrySets1->size();i++) {
        auto v1 = entrySets1->get(i);
        auto v2 = entrySets1->get(i);
        if(!v1->equals(v2)) {
            TEST_FAIL("testSerializable testHashmap case3");
            break;
        }
    }

    TEST_OK("testSerializable testHashmap case100");
}
