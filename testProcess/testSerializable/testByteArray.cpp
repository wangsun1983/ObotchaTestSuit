#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestArrayData) IMPLEMENTS(Serializable) {
public:
    ByteArray data;
    DECLARE_REFLECT_FIELD(MyTestArrayData,data);
};

void testByteArray() {

    MyTestArrayData d1 = createMyTestArrayData();
    d1->data = createByteArray(4);
    d1->data[0] = 1;
    d1->data[1] = 2;
    d1->data[2] = 12;
    d1->data[3] = 16;

    ByteArray serializedData = d1->serialize();
    for(int i = 0;i < serializedData->size();i++) {
      printf("[%d] is %d \n",i,serializedData[i]);
    }

    MyTestArrayData rs = createMyTestArrayData();
    rs->deserialize(serializedData);

    for(int i = 0;i < 4;i++) {
      printf("[%d] is %d \n",i,rs->data[i]);
    }
}
