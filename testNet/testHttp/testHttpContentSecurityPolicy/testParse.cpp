#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderContentSecurityPolicy.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpHeaderContentSecurityPolicy policy = createHttpHeaderContentSecurityPolicy();
    policy->import("default-src   'self' ; img-src * ; media-src media1.com   media2.com   ; script-src   userscripts.example.com");
    ArrayList<HttpHeaderContentSecurityPolicyItem> policies = policy->get();
    if(policies->size() != 4) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case1] [FAILED]--- ,size is %d\n",policies->size());
      break;
    }

    HttpHeaderContentSecurityPolicyItem item = policies->get(0);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandDefaultSrc) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case2] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    ArrayList<Integer> rules = item->rules;
    if(rules->size() != 1) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case3] [FAILED]---\n");
      break;
    }

    if(rules->get(0)->toValue() != st(HttpHeaderContentSecurityPolicy)::RuleSelf) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case4] [FAILED]---\n");
      break;
    }

    if(item->sources->size() != 0) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case5] [FAILED]---\n");
      break;
    }

    //img-src *
    item = policies->get(1);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandImgSrc) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case6] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case7] [FAILED]---\n");
      break;
    }

    if(item->sources->size() == 0) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case8] [FAILED]---\n");
      break;
    }

    if(!item->sources->get(0)->equals("*")) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case9] [FAILED]---\n");
      break;
    }

    //media-src media1.com   media2.com
    item = policies->get(2);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandMediaSrc) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case10] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case11] [FAILED]---\n");
      break;
    }

    if(item->sources->size() != 2) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case12] [FAILED]---\n");
      break;
    }

    if(!item->sources->get(0)->equals("media1.com")) {
      String str = item->sources->get(0);
      printf("---[HttpHeaderContentSecurityPolicy test Parse case13] [FAILED]---,str is [%s]\n",str->toChars());
      break;
    }

    if(!item->sources->get(1)->equals("media2.com")) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case14] [FAILED]---\n");
      break;
    }

    //script-src   userscripts.example.com
    item = policies->get(3);
    if(item->command != st(HttpHeaderContentSecurityPolicy)::CommandScriptSrc) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case15] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case16] [FAILED]---,size is %d\n",rules->size());
      break;
    }

    if(item->sources->size() != 1) {
      printf("---[HttpHeaderContentSecurityPolicy test Parse case17] [FAILED]---\n");
      break;
    }

    if(!item->sources->get(0)->equals("userscripts.example.com")) {
      String str = item->sources->get(0);

      printf("---[HttpHeaderContentSecurityPolicy test Parse case18] [FAILED]---str is [%s]\n",str->toChars());
      break;
    }
    break;
  }

  printf("---[HttpHeaderContentSecurityPolicy test Parse case100] [OK]--- \n");

}
