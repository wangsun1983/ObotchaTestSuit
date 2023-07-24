#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderVary.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderVary match = createHttpHeaderVary();
    match->load("no-referrer, User-Agent");
    if(!match->toString()->sameAs("no-referrer, User-Agent")) {
      TEST_FAIL("[HttpHeaderVary test toString case1]");
    }
    break;
  }
  
  while(1) {
    HttpHeaderVary match = createHttpHeaderVary();
    ArrayList<String> list = createArrayList<String>();
    list->add(createString("no-referrer"));
    list->add(createString("User-Agent"));
    match->set(list);
    if(!match->toString()->sameAs("no-referrer, User-Agent")) {
      TEST_FAIL("[HttpHeaderVary test toString case2]");
    }
    break;
  }

  TEST_OK("[HttpHeaderVary test toString case100]");
}
