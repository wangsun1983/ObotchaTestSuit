#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentType.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testGetSetType() {
  
  HttpHeaderContentType type = createHttpHeaderContentType();
  type->setType(createString("a"));
  type->setCharSet(createString("b"));
  type->setBoundary(createString("c"));
  
  if(!type->getType()->equals("a")
    ||!type->getCharSet()->equals("b")
    ||!type->getBoundary()->equals("c")) {
    TEST_FAIL("[HttpHeaderContentType test GetSetType case1]");
  }
  
  TEST_OK("[HttpHeaderContentType test GetSetType case100]");

}
