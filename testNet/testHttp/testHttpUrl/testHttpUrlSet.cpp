#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderParser.hpp"
#include "ByteRingArrayReader.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHttpUrlSet() {
  
  while(1) {
    HttpUrl url = createHttpUrl();
    url->setScheme(st(NetProtocol)::Http);
    url->setUser("su");
    url->setHost("localhost");
    url->setPort(1234);
    url->setPassword("abc");
    url->setPath("test.cgi");
    url->setFragment("fffsss");
    
    if(url->toString()->sameAs("http://su:abc@localhost:1234/test.cgi?a=b&c=d#fffsss")) {
        TEST_FAIL("[HttpUrlParse test Set case1],url is %s",url->toString()->toChars());
    }
    break;
  }
  
  

  TEST_OK("[HttpUrlParse test Set case100]");

}
