#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptLanguage.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLanguageParse() {
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = createHttpHeaderAcceptLanguage();
    encoding1->import("fr-CH,fr;q=0.9,en;q=0.8,de;q=0.7,*;q=0.5");
    auto languages = encoding1->get();
    if(languages->size() != 5) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case1]");
      break;
    }

    if(!languages->get(0)->lang->equals("fr-CH")
      || !languages->get(1)->lang->equals("fr")
      || !languages->get(2)->lang->equals("en")
      || !languages->get(3)->lang->equals("de")
      || !languages->get(4)->lang->equals("*")) {
        TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case2]");
        break;
    }
    
    if(st(Math)::compareFloat(languages->get(0)->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case2_1] ,weight is %f",languages->get(0)->weight);
      break;
    }

    if(st(Math)::compareFloat(languages->get(1)->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case3] ,weight is %f",languages->get(1)->weight);
      break;
    }

    if(st(Math)::compareFloat(languages->get(2)->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case4]");
      break;
    }

    if(st(Math)::compareFloat(languages->get(3)->weight,0.7) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case5]");
      break;
    }

    if(st(Math)::compareFloat(languages->get(4)->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case6]");
      break;
    }
    break;
  }
  
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = createHttpHeaderAcceptLanguage();
    encoding1->import("fr;q=0.9,en,en_a,en_b;q=0.8,de;q=0.7,*;q=0.5");
    auto languages = encoding1->get();
    auto l = languages->get(0);
    if(!l->lang->equals("fr") || st(Math)::compareFloat(l->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case7],lan is %s,weight is %f",l->lang->toChars(),l->weight);
      break;
    }
    
    l = languages->get(1);
    if(!l->lang->equals("en") || st(Math)::compareFloat(l->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case8]");
      break;
    }
    
    l = languages->get(2);
    if(!l->lang->equals("en_a") || st(Math)::compareFloat(l->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case9]");
      break;
    }
    
    l = languages->get(3);
    if(!l->lang->equals("en_b") || st(Math)::compareFloat(l->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case10]");
      break;
    }

    l = languages->get(4);
    if(!l->lang->equals("de") || st(Math)::compareFloat(l->weight,0.7) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case11]");
      break;
    }
  
    l = languages->get(5);
    if(!l->lang->equals("*") || st(Math)::compareFloat(l->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case12]");
      break;
    }
  
    break;
  }
  
  while(1) {
    HttpHeaderAcceptLanguage encoding1 = createHttpHeaderAcceptLanguage();
    encoding1->import("fr-CH,fr,en");
    auto languages = encoding1->get();
    auto l = languages->get(0);
    if(!l->lang->equals("fr-CH") || st(Math)::compareFloat(l->weight,1.0) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case13],lan is %s,weight is %f",l->lang->toChars(),l->weight);
      break;
    }
    
    l = languages->get(1);
    if(!l->lang->equals("fr") || st(Math)::compareFloat(l->weight,1.0) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case14],lan is %s,weight is %f",l->lang->toChars(),l->weight);
      break;
    }
    
    l = languages->get(2);
    if(!l->lang->equals("en") || st(Math)::compareFloat(l->weight,1.0) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test Parse case15],lan is %s,weight is %f",l->lang->toChars(),l->weight);
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptLanguage test Parse case100]");

}
