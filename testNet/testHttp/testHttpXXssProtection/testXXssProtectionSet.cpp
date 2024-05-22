#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAccept.hpp"
#include "Math.hpp"
#include "HttpHeaderXXssProtection.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void testXXssProtectionSet() {
  while(1) {
    HttpHeaderXXssProtection p = HttpHeaderXXssProtection::New();
    p->set(st(HttpHeaderXXssProtection)::Block);
    if(p->getType() != st(HttpHeaderXXssProtection)::Block) {
      TEST_FAIL("[HttpHeaderXXssProtection test set case1]");    
    }

    p->set(st(HttpHeaderXXssProtection)::Disable);
    if(p->getType() != st(HttpHeaderXXssProtection)::Disable) {
      TEST_FAIL("[HttpHeaderXXssProtection test set case2]");    
    }

    p->set(st(HttpHeaderXXssProtection)::Enable);
    if(p->getType() != st(HttpHeaderXXssProtection)::Enable) {
      TEST_FAIL("[HttpHeaderXXssProtection test set case3]");    
    }

    p->set(st(HttpHeaderXXssProtection)::Report,String::New("aabb.hpp"));
    if(p->getType() != st(HttpHeaderXXssProtection)::Report) {
      TEST_FAIL("[HttpHeaderXXssProtection test set case4]");    
    }

    if(!p->getReportUrl()->sameAs("aabb.hpp")) {
      TEST_FAIL("[HttpHeaderXXssProtection test set case5]");    
    }
    break;
  }

  TEST_OK("[HttpHeaderXXssProtection test set case100]");

}
