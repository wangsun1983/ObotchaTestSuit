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

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Patch"),
                createString("application/example, text/example"));
    auto encoding1 = header->getAcceptPatch();
    auto encodings = encoding1->get();
    if(encodings->size() != 2) {
      TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case1]");
      break;
    }

    if(!encodings->get(0)->type->equals("application/example")
      || !encodings->get(1)->type->equals("text/example")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case2]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Patch"),
                createString("text/example;charset=utf-8"));
    auto encoding1 = header->getAcceptPatch();
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case3]");
      break;
    }

    if(!encodings->get(0)->type->equals("text/example")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case4]");
        break;
    }

    if(!encodings->get(0)->charset->equals("utf-8")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case4]");
        break;
    }

    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Patch"),
                createString("application/merge-patch+json"));
    auto encoding1 = header->getAcceptPatch();
    auto encodings = encoding1->get();
    if(encodings->size() != 1) {
      TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case5]");
      break;
    }

    if(!encodings->get(0)->type->equals("application/merge-patch+json")) {
        TEST_FAIL("[HttpHeaderAcceptPatch test SetToHeader case6]");
        break;
    }

    break;
  }

  TEST_OK("[HttpHeaderAcceptPatch test SetToHeader case100]");

}
