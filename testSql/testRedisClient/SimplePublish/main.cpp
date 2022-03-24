#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "AtomicInteger.hpp"
#include "StrongPointer.hpp"
#include "RedisConnection.hpp"
#include "CountDownLatch.hpp"

using namespace obotcha;

RedisConnection c;
CountDownLatch latch = createCountDownLatch(1);


DECLARE_CLASS(RedisListener) IMPLEMENTS(RedisSubscribeListener) {
public:
    void onEvent(int event,String key,String value) {
        if(value != nullptr) {
            printf("key is %s , value is %s \n",key->toChars(),value->toChars());
            c->unsubscribe("abc",AutoClone(this));
            latch->countDown();
        } else {
            printf("key is %s \n",key->toChars());
        }
    }
};

int main() {
    c = createRedisConnection();
    c->connect(createString("127.0.0.1"),6379,100);
    auto l = createRedisListener();
    //c->subscribe("abc",l);
    c->publish("ff","t1ffffssss");

    //latch->await();
    //c->unsubscribe("abc",l);
    while(1) {
        sleep(1);
    }
}
