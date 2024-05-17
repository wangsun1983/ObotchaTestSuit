#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderParser.hpp"
#include "ByteRingArrayReader.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHttpUrlInetAddress() {
  while(1) {
      HttpUrl url = HttpUrl::New("http://www.baidu.com");
      auto list = url->getInetAddress();
      if(list == nullptr || list->size() == 0) {
        TEST_FAIL("[HttpUrlParse test InetAddress case100]");
      }
      break;
  }

  TEST_OK("[HttpUrlParse test InetAddress case100]");

}
