#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptRanges.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Accept-Ranges"),
                String::New("bytes"));
    //HttpHeaderAcceptRanges ranges = HttpHeaderAcceptRanges::New();
    //ranges->load("bytes");
    auto ranges = header->getAcceptRanges();
    if(!ranges->get()->sameAs("bytes")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test Parse case1]");
        break;
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Accept-Ranges"),
                String::New("none"));
    //HttpHeaderAcceptRanges ranges = HttpHeaderAcceptRanges::New();
    //ranges->load("bytes");
    auto ranges = header->getAcceptRanges();

    if(!ranges->get()->sameAs("none")) {
        TEST_FAIL("[HttpHeaderAcceptRanges test Parse case2]");
        break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptRanges test Parse case100]");

}
