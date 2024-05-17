#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "HttpHeaderAge.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
  while(1) {
    HttpHeaderAge c = HttpHeaderAge::New();
    c->load("600");
    if(!c->toString()->sameAs("600")) {
      TEST_FAIL("[HttpHeaderAge test toString case1]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAge c = HttpHeaderAge::New();
    c->set(600);
    if(!c->toString()->sameAs("600")) {
      TEST_FAIL("[HttpHeaderAge test toString case2]");
      break;
    }
    
    if(c->get() != 600) {
      TEST_FAIL("[HttpHeaderAge test toString case3]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAge test toString case100]");

}
