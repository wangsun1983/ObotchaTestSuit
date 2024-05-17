#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "AtomicInteger.hpp"
#include "StrongPointer.hpp"
#include "RedisClient.hpp"

using namespace obotcha;

int main() {
    RedisClient client = RedisClient::New();
    client->connect(String::New("127.0.0.1"),6379,100);
    int value1 = client->set(String::New("tag1"),String::New("haha"));
    String value2 = client->getValue(String::New("tag1"));
    printf("value2 is %s \n",value2->toChars());
}
