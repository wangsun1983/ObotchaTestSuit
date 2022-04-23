#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestArrayData) IMPLEMENTS(Serializable) {
public:
    int value;
    ByteArray data;
    String name;

    bool equals(MyTestArrayData v) {
        return value == v->value && data->equals(v->data) && name->equals(v->name);
    }

    DECLARE_REFLECT_FIELD(MyTestArrayData,data,value,name);
};

void testByteArray() {

    MyTestArrayData d1 = createMyTestArrayData();
    d1->data = createByteArray(4);
    d1->data[0] = 1;
    d1->data[1] = 2;
    d1->data[2] = 12;
    d1->data[3] = 16;
    d1->value = 0;
    d1->name = createString("aaa");

    ByteArray serializedData = d1->serialize();

    MyTestArrayData rs = createMyTestArrayData();
    rs->deserialize(serializedData);

    if(!rs->equals(d1)) {
        TEST_FAIL("testSerializable testByteArray case1");
    }

    TEST_OK("testSerializable testByteArray case100");
}
