#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderAge.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader h = createHttpHeader();
    h->set(createString("Age"),
           createString("600"));
           
    HttpHeaderAge c = h->getAge();
    if(c->get() != 600) {
      TEST_FAIL("[HttpHeaderAge test SetToHeader case1]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAge test SetToHeader case100]");
}
