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

void testHttpHeaderSelfDefine() {
  
  HttpHeader h = createHttpHeader();
  h->set(createString("tag1"),createString("valuehahaha"));
  h->set(createString("tag2"),createString("valuehahaha2"));
  h->set(createString("tag3"),createString("valuehahaha3"));
  
  auto v1 = h->get(createString("tag1"));
  if(v1 == nullptr || !v1->equals(createString("valuehahaha"))) {
      TEST_FAIL("[HttpHeader test SelfDefine case1]");
  }
  
  auto v2 = h->get(createString("tag2"));
  if(v2 == nullptr || !v2->equals(createString("valuehahaha2"))) {
      TEST_FAIL("[HttpHeader test SelfDefine case2]");
  }
  
  auto v3 = h->get(createString("tag3"));
  if(v3 == nullptr || !v3->equals(createString("valuehahaha3"))) {
      TEST_FAIL("[HttpHeader test SelfDefine case3]");
  }
  
  TEST_OK("[HttpHeader test SelfDefine case100]");

}
