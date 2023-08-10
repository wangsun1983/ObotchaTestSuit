#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentSecurityPolicy.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentSecurityPolicy policy = createHttpHeaderContentSecurityPolicy();
    policy->load("default-src   'self' ; img-src * ; media-src media1.com   media2.com   ; script-src   userscripts.example.com");
    ArrayList<HttpHeaderContentSecurityPolicyItem> policies = policy->get();
    if(policies->size() != 4) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case1],size is %d",policies->size());
      break;
    }

    HttpHeaderContentSecurityPolicyItem item = policies->get(0);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandDefaultSrc) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case2],item->command is %d",item->command);
      break;
    }

    ArrayList<Integer> rules = item->rules;
    if(rules->size() != 1) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case3]");
      break;
    }

    if(rules->get(0)->toValue() != st(HttpHeaderContentSecurityPolicy)::RuleSelf) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case4]");
      break;
    }

    if(item->sources->size() != 0) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case5]");
      break;
    }

    //img-src *
    item = policies->get(1);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandImgSrc) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case6],item->command is %d",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case7]");
      break;
    }

    if(item->sources->size() == 0) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case8]");
      break;
    }

    if(!item->sources->get(0)->sameAs("*")) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case9]");
      break;
    }

    //media-src media1.com   media2.com
    item = policies->get(2);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandMediaSrc) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case10],item->command is %d",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case11]");
      break;
    }

    if(item->sources->size() != 2) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case12]");
      break;
    }

    if(!item->sources->get(0)->sameAs("media1.com")) {
      String str = item->sources->get(0);
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case13],str is [%s]",str->toChars());
      break;
    }

    if(!item->sources->get(1)->sameAs("media2.com")) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case14]");
      break;
    }

    //script-src   userscripts.example.com
    item = policies->get(3);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandScriptSrc) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case15],item->command is %d",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case16],size is %d",rules->size());
      break;
    }

    if(item->sources->size() != 1) {
      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case17]");
      break;
    }

    if(!item->sources->get(0)->sameAs("userscripts.example.com")) {
      String str = item->sources->get(0);

      TEST_FAIL("[HttpHeaderContentSecurityPolicy test Parse case18]str is [%s]",str->toChars());
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderContentSecurityPolicy test Parse case100]");

}
