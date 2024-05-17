#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptLanguage.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testLanguageToString() {
 
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = HttpHeaderAcceptLanguage::New();
    encoding1->load("fr-CH,fr;q=0.9,en;q=0.8,de;q=0.7,*;q=0.5");
    if(!encoding1->toString()->sameAs("fr-CH,fr;q=0.9,en;q=0.8,de;q=0.7,*;q=0.5")) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test toString case1],str is %s",encoding1->toString()->toChars());
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = HttpHeaderAcceptLanguage::New();
    encoding1->add(String::New("fr-CH"),0.9);
    encoding1->add(String::New("fr"),0.8);
    
    if(!encoding1->toString()->sameAs("fr-CH;q=0.9,fr;q=0.8")) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test toString case2],str is %s",encoding1->toString()->toChars());
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = HttpHeaderAcceptLanguage::New();
    encoding1->add(String::New("fr-CH"),1.0);
    encoding1->add(String::New("fr"),1.0);
    
    if(!encoding1->toString()->sameAs("fr-CH,fr")) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test toString case3],str is [%s]",encoding1->toString()->toChars());
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = HttpHeaderAcceptLanguage::New();
    encoding1->add(String::New("fr-CH"),1.0);
    encoding1->add(String::New("fr"),1.0);
    HttpHeader header = HttpHeader::New();
    header->setAcceptLanguage(encoding1);
    
    auto encoding2 = header->getAcceptLanguage();
    if(!encoding2->toString()->sameAs("fr-CH,fr")) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test toString case4],str is [%s]",encoding1->toString()->toChars());
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptLanguage encoding1 = HttpHeaderAcceptLanguage::New();
    encoding1->load("en-us,en;q=0.5");
    if(!encoding1->toString()->sameAs("en-us,en;q=0.5")) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test toString case5],str is %s",encoding1->toString()->toChars());
    }
    break;
  }


  TEST_OK("[HttpHeaderAcceptLanguage test toString case100]");

}
