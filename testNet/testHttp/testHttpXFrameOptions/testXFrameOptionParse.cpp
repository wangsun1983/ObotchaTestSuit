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
    if(!options->option->equals("deny")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case1] ,option is %s ",options->option->toChars());
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("sameorigin");
    if(!options->option->equals("sameorigin")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case2]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeaderXFrameOptions options = createHttpHeaderXFrameOptions();
    options->load("allow-from https://example.com/");
    if(!options->option->equals("allow-from")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case3]");
      break;
    }

    if(!options->uri->equals("https://example.com/")) {
      TEST_FAIL("[HttpHeaderXFrameOptions test Parse case4],uri is %s",options->uri->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderXFrameOptions test Parse case100]");

}
