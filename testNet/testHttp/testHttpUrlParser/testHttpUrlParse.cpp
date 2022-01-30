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

void testHttpUrlParse() {
  while(1) {
    const char *raw= "/demo";
    HttpUrl url = createHttpUrl(raw);
    if(!url->getPath()->equals("demo")) {
      TEST_FAIL("[HttpUrlParse test Parse case1]");
    }

    if(!url->toString()->equals("/demo")) {
      TEST_FAIL("[HttpUrlParse test Parse case1_1]");
    }
    break;
  }

  while(1) {
    String request =  "http://su:abc@localhost:1234/test.cgi?a=b&c=d#fffsss";
    //HttpUrlParser parser = createHttpUrl(request);
    //HttpUrl url = parser->parseUrl(request);
    HttpUrl url = createHttpUrl(request);
    if(!url->getScheme()->equals("http")) {
      TEST_FAIL("[HttpUrlParse test Parse case2],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(!url->getUser()->equals("su")) {
      TEST_FAIL("[HttpUrlParse test Parse case3]");
      break;
    }

    if(!url->getHost()->equals("localhost")) {
      TEST_FAIL("[HttpUrlParse test Parse case3_1]");
      break;
    }

    if(url->getPort() != 1234) {
      TEST_FAIL("[HttpUrlParse test Parse case3_2]");
      break;
    }

    if(!url->getPassword()->equals("abc")) {
      TEST_FAIL("[HttpUrlParse test Parse case4]");
      break;
    }

    if(!url->getPath()->equals("test.cgi")) {
      TEST_FAIL("[HttpUrlParse test Parse case5] path is %s",url->getPath()->toChars());
      break;
    }

    if(!url->getFragment()->equals("fffsss")) {
      TEST_FAIL("[HttpUrlParse test Parse case6]");
      break;
    }

    auto query = url->getQuery();
    auto map = query->getValues();

    if(!map->get("a")->equals("b")) {
      TEST_FAIL("[HttpUrlParse test Parse case8]");
      break;
    }

    if(!map->get("c")->equals("d")) {
      TEST_FAIL("[HttpUrlParse test Parse case10]");
      break;
    }
    break;
  }

  while(1) {
    String request =  "http://abdd@localhost/test.cgi?a=b&c=d";
    HttpUrl url = createHttpUrl(request);
    if(!url->getScheme()->equals("http")) {
      TEST_FAIL("[HttpUrlParse test Parse case11],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(!url->getUser()->equals("abdd")) {
      TEST_FAIL("[HttpUrlParse test Parse case12]");
      break;
    }

    if(!url->getHost()->equals("localhost")) {
      TEST_FAIL("[HttpUrlParse test Parse case13]");
      break;
    }

    if(url->getPort() != -1) {
      TEST_FAIL("[HttpUrlParse test Parse case14]");
      break;
    }

    if(url->getPassword() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case15]");
      break;
    }

    if(!url->getPath()->equals("test.cgi")) {
      TEST_FAIL("[HttpUrlParse test Parse case16] path is %s",url->getPath()->toChars());
      break;
    }

    if(url->getFragment() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case17]");
      break;
    }

    auto query = url->getQuery();
    auto map = query->getValues();
    if(!map->get("a")->equals("b")) {
      TEST_FAIL("[HttpUrlParse test Parse case19]");
      break;
    }

    if(!map->get("c")->equals("d")) {
      TEST_FAIL("[HttpUrlParse test Parse case21]");
      break;
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://su:abc@localhost/test/wangsl/01234");
    if(!url->getScheme()->equals("https")) {
      TEST_FAIL("[HttpUrlParse test Parse case22],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(!url->getUser()->equals("su")) {
      TEST_FAIL("[HttpUrlParse test Parse case23]");
      break;
    }

    if(!url->getPassword()->equals("abc")) {
      TEST_FAIL("[HttpUrlParse test Parse case24]");
      break;
    }

    if(!url->getHost()->equals("localhost")) {
      TEST_FAIL("[HttpUrlParse test Parse case25]");
      break;
    }

    if(!url->getPath()->equals("test/wangsl/01234")) {
      TEST_FAIL("[HttpUrlParse test Parse case26] path is %s",url->getPath()->toChars());
      break;
    }

    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://ssaabb/test/wangsl/01234");
    if(!url->getScheme()->equals("https")) {
      TEST_FAIL("[HttpUrlParse test Parse case27],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(url->getUser() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case28]");
      break;
    }

    if(url->getPassword() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case29]");
      break;
    }

    if(!url->getHost()->equals("ssaabb")) {
      TEST_FAIL("[HttpUrlParse test Parse case30]");
      break;
    }

    if(!url->getPath()->equals("test/wangsl/01234")) {
      TEST_FAIL("[HttpUrlParse test Parse case31]");
      break;
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://ssaabb:123");
    if(!url->getScheme()->equals("https")) {
      TEST_FAIL("[HttpUrlParse test Parse case32],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(url->getUser() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case33]");
      break;
    }

    if(url->getPassword() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case34]");
      break;
    }

    if(!url->getHost()->equals("ssaabb")) {
      TEST_FAIL("[HttpUrlParse test Parse case35]");
      break;
    }

    if(url->getPort() != 123) {
      TEST_FAIL("[HttpUrlParse test Parse case36]");
      break;
    }

    if(url->getPath() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case37]");
      break;
    }
    break;
  }

  while(1) {
    String request =  "su:abc@localhost:1234/test.cgi?a=b&c=d#fffsss";
    //HttpUrlParser parser = createHttpUrl(request);
    //HttpUrl url = parser->parseUrl(request);
    HttpUrl url = createHttpUrl(request);
    if(url->getScheme() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case38],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(!url->getUser()->equals("su")) {
      TEST_FAIL("[HttpUrlParse test Parse case39]");
      break;
    }

    if(!url->getHost()->equals("localhost")) {
      TEST_FAIL("[HttpUrlParse test Parse case40]");
      break;
    }

    if(url->getPort() != 1234) {
      TEST_FAIL("[HttpUrlParse test Parse case41]");
      break;
    }

    if(!url->getPassword()->equals("abc")) {
      TEST_FAIL("[HttpUrlParse test Parse case42]");
      break;
    }

    if(!url->getPath()->equals("test.cgi")) {
      TEST_FAIL("[HttpUrlParse test Parse case43] path is %s",url->getPath()->toChars());
      break;
    }

    if(!url->getFragment()->equals("fffsss")) {
      TEST_FAIL("[HttpUrlParse test Parse case44]");
      break;
    }

    auto query = url->getQuery();
    auto map = query->getValues();

    if(!map->get("a")->equals("b")) {
      TEST_FAIL("[HttpUrlParse test Parse case46]");
      break;
    }

    if(!map->get("c")->equals("d")) {
      TEST_FAIL("[HttpUrlParse test Parse case48]");
      break;
    }
    break;
  }

  while(1) {
    HttpUrl url =  createHttpUrl("https://ssaabb:123#frag");
    if(!url->getScheme()->equals("https")) {
      TEST_FAIL("[HttpUrlParse test Parse case49],scheme is %s",url->getScheme()->toChars());
      break;
    }

    if(url->getUser() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case50]");
      break;
    }

    if(url->getPassword() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case51]");
      break;
    }

    if(!url->getHost()->equals("ssaabb")) {
      TEST_FAIL("[HttpUrlParse test Parse case52]");
      break;
    }

    if(url->getPort() != 123) {
      TEST_FAIL("[HttpUrlParse test Parse case53]");
      break;
    }

    if(url->getPath() != nullptr) {
      TEST_FAIL("[HttpUrlParse test Parse case54]");
      break;
    }

    if(!url->getFragment()->equals("frag")) {
      TEST_FAIL("[HttpUrlParse test Parse case55]");
      break;
    }
    break;
  }

  TEST_OK("[HttpUrlParse test Parse case100]");

}
