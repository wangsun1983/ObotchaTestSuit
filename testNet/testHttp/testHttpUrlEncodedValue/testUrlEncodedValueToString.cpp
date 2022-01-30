#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpUrlEncodedValue.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testUrlEncodedValueToString() {
  while(1) {
    //abc=1&bbb=qq&ccc=ffds
    HttpUrlEncodedValue v = createHttpUrlEncodedValue();
    v->set("abc","1");
    v->set("bbb","qq");
    v->set("ccc","ffds");
    if(!v->toString()->equals("ccc=ffds&abc=1&bbb=qq")) {
      TEST_FAIL("[HttpUrlEncodedValue test toString case1] v is %s",v->toString()->toChars());
    }
    break;
  }

  TEST_OK("[HttpUrlEncodedValue test toString case100]");

}
