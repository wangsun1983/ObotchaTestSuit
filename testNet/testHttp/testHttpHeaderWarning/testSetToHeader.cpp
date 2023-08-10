#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderWarning.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("warning"),createString("112 - \"cache down\" \"Wed, 21 Oct 2015 07:28:00 GMT\""));
    auto warning = header->getWarning();
    if(warning->getCode() != 112) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case1]");
      break;
    }

    if(!warning->getAgent()->sameAs("-")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case2]");
      break;
    }

    if(!warning->getText()->sameAs("cache down")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case3]");
      break;
    }

    if(!warning->getDateTime()->toString()->sameAs("Wed, 21 Oct 2015 07:28:00 GMT")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case4]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    //HttpHeaderWarning warning = createHttpHeaderWarning();
    //warning->load("110 anderson/1.3.37 \"Response is stale\"");
    header->set(createString("warning"),createString("110 anderson/1.3.37 \"Response is stale\""));
    auto warning = header->getWarning();
    
    if(warning->getCode() != 110) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case5]");
      break;
    }

    if(!warning->getAgent()->sameAs("anderson/1.3.37")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case6]");
      break;
    }

    if(!warning->getText()->sameAs("Response is stale")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case7]");
      break;
    }

    if(warning->getDateTime() != nullptr) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case8]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeader header = createHttpHeader();
    HttpHeaderWarning warning_base = createHttpHeaderWarning();
    warning_base->load("110 anderson/1.3.37 \"Response is stale\"");
    header->setWarning(warning_base);
    
    auto warning = header->getWarning();
    
    if(warning->getCode() != 110) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case9]");
      break;
    }

    if(!warning->getAgent()->sameAs("anderson/1.3.37")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case10]");
      break;
    }

    if(!warning->getText()->sameAs("Response is stale")) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case11]");
      break;
    }

    if(warning->getDateTime() != nullptr) {
      TEST_FAIL("[HttpHeaderWarning test setToHeader case12]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderWarning test setToHeader case100]");
}
