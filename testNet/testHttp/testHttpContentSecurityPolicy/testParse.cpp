#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpContentSecurityPolicy.hpp"
#include "Math.hpp"

using namespace obotcha;

void testParse() {
  while(1) {
    HttpContentSecurityPolicy policy = createHttpContentSecurityPolicy();
    policy->import("default-src   'self' ; img-src * ; media-src media1.com   media2.com   ; script-src   userscripts.example.com");
    ArrayList<HttpContentSecurityPolicyItem> policies = policy->get();
    if(policies->size() != 4) {
      printf("---[HttpContentSecurityPolicy test Parse case1] [FAILED]--- ,size is %d\n",policies->size());
      break;
    }

    HttpContentSecurityPolicyItem item = policies->get(0);
    if(item->command != st(HttpContentSecurityPolicy)::CommandDefaultSrc) {
      printf("---[HttpContentSecurityPolicy test Parse case2] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    ArrayList<Integer> rules = item->rules;
    if(rules->size() != 1) {
      printf("---[HttpContentSecurityPolicy test Parse case3] [FAILED]---\n");
      break;
    }

    if(rules->get(0)->toValue() != st(HttpContentSecurityPolicy)::RuleSelf) {
      printf("---[HttpContentSecurityPolicy test Parse case4] [FAILED]---\n");
      break;
    }

    if(item->sources->size() != 0) {
      printf("---[HttpContentSecurityPolicy test Parse case5] [FAILED]---\n");
      break;
    }

    //img-src *
    item = policies->get(1);
    if(item->command != st(HttpContentSecurityPolicy)::CommandImgSrc) {
      printf("---[HttpContentSecurityPolicy test Parse case6] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      printf("---[HttpContentSecurityPolicy test Parse case7] [FAILED]---\n");
      break;
    }

    if(item->sources->size() == 0) {
      printf("---[HttpContentSecurityPolicy test Parse case8] [FAILED]---\n");
      break;
    }

    if(!item->sources->get(0)->equals("*")) {
      printf("---[HttpContentSecurityPolicy test Parse case9] [FAILED]---\n");
      break;
    }

    //media-src media1.com   media2.com
    item = policies->get(2);
    if(item->command != st(HttpContentSecurityPolicy)::CommandMediaSrc) {
      printf("---[HttpContentSecurityPolicy test Parse case10] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      printf("---[HttpContentSecurityPolicy test Parse case11] [FAILED]---\n");
      break;
    }

    if(item->sources->size() != 2) {
      printf("---[HttpContentSecurityPolicy test Parse case12] [FAILED]---\n");
      break;
    }

    if(!item->sources->get(0)->equals("media1.com")) {
      String str = item->sources->get(0);
      printf("---[HttpContentSecurityPolicy test Parse case13] [FAILED]---,str is [%s]\n",str->toChars());
      break;
    }

    if(!item->sources->get(1)->equals("media2.com")) {
      printf("---[HttpContentSecurityPolicy test Parse case14] [FAILED]---\n");
      break;
    }

    //script-src   userscripts.example.com
    item = policies->get(3);
    if(item->command != st(HttpContentSecurityPolicy)::CommandScriptSrc) {
      printf("---[HttpContentSecurityPolicy test Parse case15] [FAILED]--- ,item->command is %d\n",item->command);
      break;
    }

    rules = item->rules;
    if(rules->size() != 0) {
      printf("---[HttpContentSecurityPolicy test Parse case16] [FAILED]---,size is %d\n",rules->size());
      break;
    }

    if(item->sources->size() != 1) {
      printf("---[HttpContentSecurityPolicy test Parse case17] [FAILED]---\n");
      break;
    }

    if(!item->sources->get(0)->equals("userscripts.example.com")) {
      String str = item->sources->get(0);
      
      printf("---[HttpContentSecurityPolicy test Parse case18] [FAILED]---str is [%s]\n",str->toChars());
      break;
    }
    break;
  }
  
  printf("---[HttpContentSecurityPolicy test Parse case100] [OK]--- \n");

}
