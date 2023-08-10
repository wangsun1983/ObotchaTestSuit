#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderXFrameOptions.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testXFrameOptionsToString() {
  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("deny");
    if(!options->toString()->sameAs("deny")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("sameorigin");
    if(!options->toString()->sameAs("sameorigin")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("allow-from https://example.com/");
    if(!options->toString()->sameAs("allow-from https://example.com/")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case3]");
      break;
    }

    break;
  }
  
  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("allow-from https://example.com/");
    HttpHeader header = createHttpHeader();
    header->setXFrameOptions(options);
    
    options = header->getXFrameOptions();
    if(!options->toString()->sameAs("allow-from https://example.com/")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test toString case4]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeaderXFrameOptions test toString case100]");

}
