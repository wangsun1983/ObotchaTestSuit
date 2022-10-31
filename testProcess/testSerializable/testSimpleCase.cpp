#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"
#include "ByteArrayWriter.hpp"
#include "Uint32.hpp"

using namespace obotcha;

DECLARE_CLASS(MqMessage) IMPLEMENTS(Serializable) {
public:
    ByteArray data;
    String channel;
    String token;
    uint32_t flags;
    int retryTimes;

    ByteArray generatePacket() {
      ByteArray serializeData = serialize();
      ByteArray finalData = createByteArray(serializeData->size() + sizeof(uint32_t));
      ByteArrayWriter writer = createByteArrayWriter(finalData);
      writer->write<uint32_t>(serializeData->size());
      writer->write(serializeData);

      return finalData;
  }

  static MqMessage generateMessage(ByteArray data) {
      ByteArray msgData = createByteArray(data->toValue() + sizeof(uint32_t),data->size() - sizeof(uint32_t),true);
      MqMessage msg = createMqMessage();
      msg->deserialize(msgData);
      //msg->mPacketData = data;
      return msg;
  }

public:
    DECLARE_REFLECT_FIELD(MqMessage,channel,data,token,flags,retryTimes);
};


void testSimpleCase() {
    MqMessage mq = createMqMessage();
    mq->channel = createString("info11");
    auto data = mq->generatePacket();
    data->dump("aaa");
  
}
