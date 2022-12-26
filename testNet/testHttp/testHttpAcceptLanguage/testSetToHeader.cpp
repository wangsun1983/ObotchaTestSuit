#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptLanguage.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpHeader.hpp"

using namespace obotcha;

void testSetToHeader() {
  while(1) {
    HttpHeader header = createHttpHeader();
    header->set(createString("Accept-Language"),
                createString("fr-CH,fr;q=0.9,en;q=0.8,de;q=0.7,*;q=0.5"));
    auto encoding1 = header->getAcceptLanguage();
    auto languages = encoding1->get();
    if(languages->size() != 5) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test SetToHeader case1]");
      break;
    }

    if(!languages->get(0)->lang->equals("fr-CH")
      || !languages->get(1)->lang->equals("fr")
      || !languages->get(2)->lang->equals("en")
      || !languages->get(3)->lang->equals("de")
      || !languages->get(4)->lang->equals("*")) {
        TEST_FAIL("[HttpHeaderAcceptLanguage test SetToHeader case2]");
        break;
    }

    if(st(Math)::compareFloat(languages->get(1)->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test SetToHeader case3] [FAILED],weight is %f",languages->get(1)->weight);
      break;
    }

    if(st(Math)::compareFloat(languages->get(2)->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test SetToHeader case4]");
      break;
    }

    if(st(Math)::compareFloat(languages->get(3)->weight,0.7) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test SetToHeader case5]");
      break;
    }

    if(st(Math)::compareFloat(languages->get(4)->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderAcceptLanguage test SetToHeader case6]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderAcceptLanguage test SetToHeader case100]");

}
