#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderUpgrade.hpp"
#include "Math.hpp"
#include "Calendar.hpp"
#include "TestLog.hpp"
#include "HttpHeaderCrossOriginEmbedderPolicy.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Cross-Origin-Embedder-Policy"),String::New("unsafe-none"));
    auto policy = header->getCrossOriginEmbedderPolicy();
    if(!policy->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test setToHeader case1]");
    }
    break;
  }

  while(1) {
    HttpHeader header = HttpHeader::New();
    header->set(String::New("Cross-Origin-Embedder-Policy"),String::New("unsafe-none"));
    auto policy = header->getCrossOriginEmbedderPolicy();    
    header->setCrossOriginEmbedderPolicy(policy);
    
    auto policy2 = header->getCrossOriginEmbedderPolicy();
    if(!policy2->isUnSafeNone()) {
      TEST_FAIL("[CrossOriginEmbedderPolicy test setToHeader case2]");
    }
    break;
  }

  TEST_OK("[CrossOriginEmbedderPolicy test setToHeader case100]");
}
