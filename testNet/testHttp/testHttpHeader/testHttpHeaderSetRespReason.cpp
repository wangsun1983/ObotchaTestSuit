#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderParser.hpp"
#include "ByteRingArrayReader.hpp"
#include "HttpMethod.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "Math.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testResponseReason() {
  while(1) {
    HttpHeader header = createHttpHeader();
    auto ret = header->setResponseReason(createString("abc"));
    if(ret) {
        TEST_FAIL("[HttpHeader test Response Reason case1]");
    }
    
    ret = header->setResponseReason(createString(" length required "));
    if(!ret) {
        TEST_FAIL("[HttpHeader test Response Reason case2]");
    }
    break;
  }

  TEST_OK("[HttpHeader test Response Reason case100]");
}
