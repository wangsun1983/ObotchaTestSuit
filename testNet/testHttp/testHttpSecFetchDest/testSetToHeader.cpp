#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchDest.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Sec-Fetch-Dest"),createString("audio"));
    auto save = header->getSecFetchDest();
    save->load("audio");
    if(!save->get()->sameAs("audio")) {
      TEST_FAIL("[HttpHeaderSecFetchDest test Parse case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Sec-Fetch-Dest"),createString("track"));
    auto save = header->getSecFetchDest();
    if(!save->get()->sameAs("track")) {
      TEST_FAIL("[HttpHeaderSecFetchDest test Parse case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchDest test Parse case100]");

}
