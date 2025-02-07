#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpCookieParser.hpp"
#include "TestLog.hpp"
#include "Calendar.hpp"

using namespace obotcha;

void testCookieParse() {
  while(1) {
    String cookie = "yummy_cookie=choco; tasty_cookie=strawberry;Secure; Domain=example.com;Path=/abc;HttpOnly;Expires=Wed, 21 Oct 2015 07:28:00 GMT;max-age=600";
    ArrayList<HttpCookie> cookies = st(HttpCookieParser)::parse(cookie);
    if(cookies == nullptr || cookies->size() != 2) {
      TEST_FAIL("[HttpCookie test Parse case1]");
      break;
    }

    auto cookie1 = cookies->get(0);
    if(!cookie1->getName()->sameAs("yummy_cookie") || !cookie1->getValue()->sameAs("choco")) {
      TEST_FAIL("[HttpCookie test Parse case2]");
      break;
    }

    auto cookie2 = cookies->get(1);
    if(!cookie2->getName()->sameAs("tasty_cookie") || !cookie2->getValue()->sameAs("strawberry")) {
      TEST_FAIL("[HttpCookie test Parse case3]");
      break;
    }
    
    if(!cookie1->getPropertySecure()) {
      TEST_FAIL("[HttpCookie test Parse case4]");
      break;
    }
       
    if(cookie1->getPropertyPath() == nullptr 
        || !cookie1->getPropertyPath()->sameAs("/abc")) {
      printf("path is %s \n",cookie1->getPropertyPath()->toChars());
      TEST_FAIL("[HttpCookie test Parse case5]");
      break;
    }
    
    if(cookie1->getPropertyDomain() == nullptr 
        || !cookie1->getPropertyDomain()->sameAs("example.com")) {
      TEST_FAIL("[HttpCookie test Parse case6]");
      break;
    }
    
    if(cookie1->getPropertyDomain() == nullptr 
        || !cookie1->getPropertyDomain()->sameAs("example.com")) {
      TEST_FAIL("[HttpCookie test Parse case6]");
      break;
    }
    
    if(cookie1->getPropertyMaxAge() != 600) {
      TEST_FAIL("[HttpCookie test Parse case7]");
      break;
    }
    
    //Wed, 21 Oct 2015 07:28:00 GMT
    HttpDate expire = cookie1->getPropertyExpires();
    if(expire == nullptr ||
       expire->toDateTime()->year() != 2015 ||
       expire->toDateTime()->month() != st(Calendar)::October ||
       expire->toDateTime()->dayOfMonth() != 21 ||
       expire->toDateTime()->dayOfWeek() != st(Calendar)::Wednesday){
      TEST_FAIL("[HttpCookie test Parse case8]");
      break;
    }
    
    if(expire == nullptr ||
       expire->toDateTime()->hour() != 7 ||
       expire->toDateTime()->minute() != 28 ||
       expire->toDateTime()->dayOfMonth() != 21 ||
       expire->toDateTime()->second() != 0){
      TEST_FAIL("[HttpCookie test Parse case9]");
      break;
    }
    
    //cookie2
    if(!cookie2->getPropertySecure()) {
      TEST_FAIL("[HttpCookie test Parse case10]");
      break;
    }
       
    if(cookie2->getPropertyPath() == nullptr 
        || !cookie2->getPropertyPath()->sameAs("/abc")) {
      printf("path is %s \n",cookie1->getPropertyPath()->toChars());
      TEST_FAIL("[HttpCookie test Parse case11]");
      break;
    }
    
    if(cookie2->getPropertyDomain() == nullptr 
        || !cookie2->getPropertyDomain()->sameAs("example.com")) {
      TEST_FAIL("[HttpCookie test Parse case12]");
      break;
    }
    
    if(cookie2->getPropertyDomain() == nullptr 
        || !cookie2->getPropertyDomain()->sameAs("example.com")) {
      TEST_FAIL("[HttpCookie test Parse case13]");
      break;
    }
    
    if(cookie2->getPropertyMaxAge() != 600) {
      TEST_FAIL("[HttpCookie test Parse case14]");
      break;
    }
    
    //Wed, 21 Oct 2015 07:28:00 GMT
    expire = cookie2->getPropertyExpires();
    if(expire == nullptr ||
       expire->toDateTime()->year() != 2015 ||
       expire->toDateTime()->month() != st(Calendar)::October ||
       expire->toDateTime()->dayOfMonth() != 21 ||
       expire->toDateTime()->dayOfWeek() != st(Calendar)::Wednesday){
      TEST_FAIL("[HttpCookie test Parse case15]");
      break;
    }
    
    if(expire == nullptr ||
       expire->toDateTime()->hour() != 7 ||
       expire->toDateTime()->minute() != 28 ||
       expire->toDateTime()->dayOfMonth() != 21 ||
       expire->toDateTime()->second() != 0){
      TEST_FAIL("[HttpCookie test Parse case16]");
      break;
    }
    
    break;
  }
  
  while(1) {
    String cookie = "yummy_cookie=choco; tasty_cookie=strawberry";
    ArrayList<HttpCookie> cookies = st(HttpCookieParser)::parse(cookie);
    if(cookies == nullptr || cookies->size() != 2) {
      TEST_FAIL("[HttpCookie test Parse case17]");
      break;
    }
    break;
  }
  TEST_OK("[HttpCookie test Parse case100]");

}
