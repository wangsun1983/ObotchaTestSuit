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
  
  HttpHeaderContentType type = HttpHeaderContentType::New();
  type->setType(String::New("a"));
  type->setCharSet(String::New("b"));
  type->setBoundary(String::New("c"));
  
  if(!type->getType()->sameAs("a")
    ||!type->getCharSet()->sameAs("b")
    ||!type->getBoundary()->sameAs("c")) {
    TEST_FAIL("[HttpHeaderContentType test GetSetType case1]");
  }
  
  TEST_OK("[HttpHeaderContentType test GetSetType case100]");

}
