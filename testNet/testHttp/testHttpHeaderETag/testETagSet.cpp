#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderETag.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void testEtagSet() {
  while(1) {
    HttpHeaderETag tag = HttpHeaderETag::New();
    tag->setWeakCheck(true);
    tag->setValue(String::New("abc"));

    if(!tag->isWeakCheck()) {
      TEST_FAIL("[HttpHeaderETag test set case1]");
    }

    if(!tag->getValue()->sameAs("abc")) {
      TEST_FAIL("[HttpHeaderETag test set case2]");
    }
    break;
  }

  TEST_OK("[HttpHeaderETag test set case100]");

}
