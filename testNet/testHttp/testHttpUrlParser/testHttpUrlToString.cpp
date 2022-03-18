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

void testHttpUrlToString() {
  while(1) {
    const char *raw= "/demo";
    HttpUrl url = createHttpUrl(raw);
    if(!url->toString()->equals("/demo")) {
      TEST_FAIL("[HttpUrlToString test case1_1,url is %s]",url->toString()->toChars());
    }
    break;
  }

  while(1) {
    String request =  "http://su:abc@localhost:1234/test.cgi?a=b&c=d#fffsss";
    HttpUrl url = createHttpUrl(request);
    if(!url->toString()->equals("http://su:abc@localhost:1234/test.cgi?c=d&a=b#fffsss")) {
      TEST_FAIL("[HttpUrlToString test case2] url is %s",url->toString()->toChars());
    }
    break;
  }

  while(1) {
    String request =  "http://abdd@localhost/test.cgi?a=b&c=d";
    HttpUrl url = createHttpUrl(request);
    if(!url->toString()->equals("http://abdd@localhost/test.cgi?c=d&a=b")) {
      TEST_FAIL("[HttpUrlToString test case3]");
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://su:abc@localhost/test/wangsl/01234");
    if(!url->toString()->equals("https://su:abc@localhost/test/wangsl/01234")) {
      TEST_FAIL("[HttpUrlToString test case4]");
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://ssaabb/test/wangsl/01234");
    if(!url->toString()->equals("https://ssaabb/test/wangsl/01234")) {
      TEST_FAIL("[HttpUrlToString test case5]");
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://ssaabb:123");
    if(!url->toString()->equals("https://ssaabb:123")) {
      TEST_FAIL("[HttpUrlToString test case6]");
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("su:abc@localhost:1234/test.cgi?a=b&c=d#fffsss");
    if(!url->toString()->equals("su:abc@localhost:1234/test.cgi?c=d&a=b#fffsss")) {
      TEST_FAIL("[HttpUrlToString test case7] [FAILED],url is %s",url->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://ssaabb:123#frag");
    if(!url->toString()->equals("https://ssaabb:123#frag")) {
      TEST_FAIL("[HttpUrlToString test case8] [FAILED] ,url is %s",url->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpUrlToString test case100]");

}
