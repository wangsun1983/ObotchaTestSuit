#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchUser.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    //HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    header->set(createString("Sec-Fetch-User"),createString("?1"));
    //save->import("?1");
    auto save = header->getSecFetchUser();
    if(!save->get()->equals("?1")) {
      TEST_FAIL("[HttpHeaderSecFetchUser test SetToHeader case1]");
      break;
    }
    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    //HttpHeaderSecFetchUser save = createHttpHeaderSecFetchUser();
    header->set(createString("Sec-Fetch-User"),createString("?0"));
    auto save = header->getSecFetchUser();
    if(!save->get()->equals("?0")) {
      TEST_FAIL("[HttpHeaderSecFetchUser test SetToHeader case2]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderSecFetchUser test SetToHeader case100]");

}
