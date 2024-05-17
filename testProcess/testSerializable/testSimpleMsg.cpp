#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TestMqMessage) IMPLEMENTS(Serializable){
public:
    enum MessageType {
        ShakeHand = 0,
        Subscribe,
        UnSubscribe,
        Publish,
        PublishStick,
    };
    _TestMqMessage() {}
    _TestMqMessage(int type,String channel,ByteArray data) {
      this->type = type;
      this->channel = channel;
      this->data = data;
    }
    
    ByteArray toByteArray() {
      return serialize();
    }


    int type;
    ByteArray data;
    String channel;

    bool equals(TestMqMessage s) {
        return type == s->type && channel->equals(s->channel) && data->equals(s->data);
    }

    DECLARE_REFLECT_FIELD(TestMqMessage,type,channel,data);
};

void testSimpleMsg() {
    String v = String::New("11");
    TestMqMessage msg = TestMqMessage::New(1,"abc",v->toByteArray());
    ByteArray data = Serialize(msg);
    
    TestMqMessage msg2 = DeSerialize<TestMqMessage>(data);

    if(msg2->type != msg->type) {
        TEST_FAIL("Serializable testSimpleMsg case1");
    }

    if(!msg2->channel->equals(msg->channel)) {
        TEST_FAIL("Serializable testSimpleMsg case2");
    }

    if(!msg2->data->equals(msg->data)) {
        TEST_FAIL("Serializable testSimpleMsg case3");

        printf("msg2 data!!!!! \n");
        for(int i = 0;i < msg2->data->size();i++) {
            printf("data[%d] is %x \n",i,msg2->data[i]);
        }

        printf("msg data!!!!! \n");
        for(int i = 0;i < msg2->data->size();i++) {
            printf("data[%d] is %x \n",i,msg2->data[i]);
        }
    }

    TEST_OK("Serializable testSimpleMsg case100");
}
