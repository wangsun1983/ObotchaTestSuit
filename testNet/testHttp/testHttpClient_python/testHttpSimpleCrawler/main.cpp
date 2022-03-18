#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "HttpClient.hpp"
#include "HttpGet.hpp"

using namespace obotcha;

int main() {
    HttpClient c = createHttpClient();
    HttpGet get = createHttpGet("https://www.sina.com.cn/");
    auto r = c->execute(get);
    if(r != nullptr) {
        printf("it is not nullptr \n");
    }

    HttpEntity entity = r->getEntity();

    if(entity != nullptr) {
        printf("getl %s \n",entity->getContent()->toString()->toChars());
    }
    
    c = nullptr;

    return 0;
}
