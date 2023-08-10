#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderXFrameOptions.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testXFrameOptionsParse() {
  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("deny");
    if(!options->option->sameAs("deny")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case1] ,option is %s ",options->option->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("sameorigin");
    if(!options->option->sameAs("sameorigin")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("allow-from https://example.com/");
    if(!options->option->sameAs("allow-from")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case3]");
      break;
    }

    if(!options->uri->sameAs("https://example.com/")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case4],uri is %s",options->uri->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderXFrameOptions test Parse case100]");

}
