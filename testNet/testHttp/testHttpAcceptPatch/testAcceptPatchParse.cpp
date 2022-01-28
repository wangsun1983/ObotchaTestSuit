#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptPatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPatchParse() {
  while(1) {
    HttpHeaderAcceptPatch encoding1 = createHttpHeaderAcceptPatch();
    encoding1->import("application/example, text/example");
    auto encodings = encoding1->get();
    if(encodings->size() != 2) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case1]");
      break;
    }

    if(!encodings->get(0)->type->equals("application/example")
      || !encodings->get(1)->type->equals("text/example")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test Parse case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeaderAcceptPatch encoding1 = createHttpHeaderAcceptPatch();
    encoding1->import("text/example;charset=utf-8");
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case3]");
      break;
    }

    if(!encodings->get(0)->type->equals("text/example")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test Parse case4]");
        break;
    }

    if(!encodings->get(0)->charset->equals("utf-8")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test Parse case4]");
        break;
    }

    break;
  }

  while(1) {
    HttpHeaderAcceptPatch encoding1 = createHttpHeaderAcceptPatch();
    encoding1->import("application/merge-patch+json");
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAcceptPatch test Parse case5]");
      break;
    }

    if(!encodings->get(0)->type->equals("application/merge-patch+json")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test Parse case6]");
        break;
    }

    break;
  }

  TEST_OK("[HttpHeaderAcceptPatch test Parse case100]");

}
