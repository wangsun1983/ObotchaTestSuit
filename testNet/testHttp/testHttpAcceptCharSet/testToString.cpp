#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testCharSetToString() {
  while(1) {
    HttpHeaderAcceptCharSet charset = HttpHeaderAcceptCharSet::New();
    charset->load("iso-8859-1");
    if(!charset->toString()->sameAs("iso-8859-1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case1],charset is %s",charset->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptCharSet charset = HttpHeaderAcceptCharSet::New();
    charset->load("utf-8, iso-8859-1");
    if(!charset->toString()->sameAs("utf-8,iso-8859-1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case2] [FAILED],str is %s",charset->toString()->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptCharSet charset = HttpHeaderAcceptCharSet::New();
    charset->load("utf-8, iso-8859-1;q=0.5, *;q=0.1");
    if(!charset->toString()->sameAs("utf-8,iso-8859-1;q=0.5,*;q=0.1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case3]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptCharSet charset = HttpHeaderAcceptCharSet::New();
    charset->load("utf-8, iso-8859-1;q=0.5, *;q=0.1");
    HttpHeader header = HttpHeader::New();
    header->setAcceptCharSet(charset);
    auto charset2 = header->getAcceptCharSet();
    
    if(!charset2->toString()->sameAs("utf-8,iso-8859-1;q=0.5,*;q=0.1")) {
      TEST_FAIL("[HttpHeaderAcceptCharSet test toString case4]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptCharSet test toString case100]");

}
