#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestArrayData) IMPLEMENTS(Serializable){
public:
    enum MessageType {
        //message type
        ShakeHand = 1<<1,
        Subscribe = 1<<2,
        UnSubscribe = 1<<3,
        Publish = 1<<4,
        PublishOneShot = 1<<5,
        MessageAck = 1<<6,
        MaxMessageType = 1<<7,

        //psersist
        Persistent = 1<<10,
        Acknowledge = 1<<11,
    };

    _MyTestArrayData(){

    }

    _MyTestArrayData(String channel,ByteArray data,uint32_t flags) {
      this->data = data;
      this->channel = channel;
      this->flags = flags;
    }

    bool equals(MyTestArrayData v) {
        return flags == v->flags && data->equals(v->data) && channel->equals(v->channel);
    }

    ByteArray toByteArray() {
      return serialize();
    }

private:
    ByteArray data;
    String channel;
    String token;
    uint32_t flags;
    int retryTimes;

public:
    DECLARE_REFLECT_FIELD(MyTestArrayData,channel,data,token,flags,retryTimes);
};

void testByteArray() {
    ByteArray data = createByteArray(1024);
    data[0] = 1;
    data[1] = 2;
    data[2] = 12;
    data[3] = 16;

    MyTestArrayData d1 = createMyTestArrayData("aaa",data,12);

    ByteArray serializedData = d1->toByteArray();
    printf("serialize size is %d \n",serializedData->size());
    MyTestArrayData rs = createMyTestArrayData();
    rs->deserialize(serializedData);

    if(!rs->equals(d1)) {
        TEST_FAIL("testSerializable testByteArray case1");
    }

    TEST_OK("testSerializable testByteArray case100");
}
