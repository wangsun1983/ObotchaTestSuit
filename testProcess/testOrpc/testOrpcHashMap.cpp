#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "HashMap.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestMapKey) IMPLEMENTS(Serializable) {
public:
    int v1;
    DECLARE_REFLECT_FIELD(MyTestMapKey,v1);
};

DECLARE_CLASS(MyTestMapValue) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;
    DECLARE_REFLECT_FIELD(MyTestMapValue,m1,m2);
};

DECLARE_CLASS(MyTestDataMap) IMPLEMENTS(Serializable) {
public:
    HashMap<MyTestMapKey,MyTestMapValue> map;

    DECLARE_REFLECT_FIELD(MyTestDataMap,map);
};

void testOrpcHashMap() {
    MyTestDataMap mm = createMyTestDataMap();
    mm->map = createHashMap<MyTestMapKey,MyTestMapValue>();

    MyTestMapKey key1 = createMyTestMapKey();
    key1->v1 = 111;

    MyTestMapValue value1 = createMyTestMapValue();
    value1->m1 = createString("value1");
    value1->m2 = 111222;

    MyTestMapKey key2 = createMyTestMapKey();
    key1->v1 = 222;

    MyTestMapValue value2 = createMyTestMapValue();
    value2->m1 = createString("value2");
    value2->m2 = 333444;

    mm->map->put(key2,value2);

    ByteArray data = mm->toByteArray();
    printf("data size is %d \n",data->size());

    MyTestDataMap mm2 = createMyTestDataMap();
    mm2->import(data);

    printf("mm2 size is %d \n",mm2->map->size());
}
