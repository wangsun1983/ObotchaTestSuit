#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderDigest.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Digest"),
                createString(" sha-256=X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE="));
    
    auto digest = header->getDigest();
    ArrayList<HttpHeaderDigestItem> list = digest->getDigests();
    if(list->size() != 1) {
      TEST_FAIL("[HttpHeaderDigest test SetToHeader case1]");
      break;
    }

    auto item = list->get(0);
    if(!item->algorithm->sameAs("sha-256") || !item->value->sameAs("X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=")) {
      TEST_FAIL("[HttpHeaderDigest test SetToHeader case2]");
      break;
    }

    break;
  }

  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Digest"),
                createString(" sha-256=X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=,unixsum=30637 "));
    
    auto digest = header->getDigest();
    ArrayList<HttpHeaderDigestItem> list = digest->getDigests();
    if(list->size() != 2) {
      TEST_FAIL("[HttpHeaderDigest test SetToHeader case1]");
      break;
    }

    auto item = list->get(0);
    if(!item->algorithm->sameAs("sha-256") || !item->value->sameAs("X48E9qOokqqrvdts8nOJRJN3OWDUoyWxBf7kbu9DBPE=")) {
      TEST_FAIL("[HttpHeaderDigest test SetToHeader case2]");
      break;
    }

    item = list->get(1);
    if(!item->algorithm->sameAs("unixsum") || !item->value->sameAs("30637")) {
      TEST_FAIL("[HttpHeaderDigest test SetToHeader case2]");
      break;
    }

    break;
  }
  
  TEST_OK("[HttpHeaderDigest test SetToHeader case100]");
}
