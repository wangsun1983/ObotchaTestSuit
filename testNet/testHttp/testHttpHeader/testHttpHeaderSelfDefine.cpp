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
  
  HttpHeader h = HttpHeader::New();
  h->set(String::New("tag1"),String::New("valuehahaha"));
  h->set(String::New("tag2"),String::New("valuehahaha2"));
  h->set(String::New("tag3"),String::New("valuehahaha3"));
  
  auto v1 = h->get(String::New("tag1"));
  if(v1 == nullptr || !v1->equals(String::New("valuehahaha"))) {
      TEST_FAIL("[HttpHeader test SelfDefine case1]");
  }
  
  auto v2 = h->get(String::New("tag2"));
  if(v2 == nullptr || !v2->equals(String::New("valuehahaha2"))) {
      TEST_FAIL("[HttpHeader test SelfDefine case2]");
  }
  
  auto v3 = h->get(String::New("tag3"));
  if(v3 == nullptr || !v3->equals(String::New("valuehahaha3"))) {
      TEST_FAIL("[HttpHeader test SelfDefine case3]");
  }
  
  TEST_OK("[HttpHeader test SelfDefine case100]");

}
