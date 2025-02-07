#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptPatch.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testPatchToString() {
  while(1) {
    HttpHeaderAcceptPatch encoding1 = HttpHeaderAcceptPatch::New();
    encoding1->load("application/example,text/example");
    if(!encoding1->toString()->sameAs("application/example,text/example")) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case1]");
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptPatch encoding1 = HttpHeaderAcceptPatch::New();
    encoding1->load("text/example;charset=utf-8");
    if(!encoding1->toString()->sameAs("text/example;charset=utf-8")) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case2]");
    }

    break;
  }

  while(1) {
    HttpHeaderAcceptPatch encoding1 = HttpHeaderAcceptPatch::New();
    encoding1->load("application/merge-patch+json");
    if(!encoding1->toString()->sameAs("application/merge-patch+json")) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case3]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptPatch encoding1 = HttpHeaderAcceptPatch::New();
    encoding1->load("application/merge-patch+json");
    HttpHeader header = HttpHeader::New();
    header->setAcceptPatch(encoding1);
    
    auto encoding2 = header->getAcceptPatch();
    if(!encoding2->toString()->sameAs("application/merge-patch+json")) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case4]");
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptPatch test toString case100]");

}
