#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpSession.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyData) {
public:
  int v1;
  int v2;
};

void testHttpSession() {
  while(1) {
    MyData data = createMyData();
    data->v1 = 100;
    data->v2 = 123;

    HttpSession ss = createHttpSession();
    ss->setAttribute("a",createString("value_a"));
    ss->setAttribute("b",data);

    if(ss->size() != 2) {
      TEST_FAIL("[testHttpSession test Parse case1]");
      break;
    }

    String value1 = ss->getAttribute<String>("a");
    if(value1 == nullptr || !value1->sameAs("value_a")) {
      TEST_FAIL("[testHttpSession test Parse case2]");
      break;
    }

    MyData value2 = ss->getAttribute<MyData>("b");
    if(value2 == nullptr || value2->v1 != 100 || value2->v2 != 123) {
      TEST_FAIL("[testHttpSession test Parse case3]");
      break;
    }

    MyData value3 = ss->getAttribute<MyData>("c");
    if(value3 != nullptr) {
      TEST_FAIL("[testHttpSession test Parse case4]");
      break;
    }

    ss->removeAttribute("a");
    if(ss->size() != 1) {
      TEST_FAIL("[testHttpSession test Parse case5]");
      break;
    }

    ss->invalidate();
    if(ss->size() != 0) {
      TEST_FAIL("[testHttpSession test Parse case6]");
      break;
    }

    ss->setAttribute("a",createString("value_a"));
    ss->setAttribute("b",data);

    ArrayList<String> names = ss->getAttributeNames();
    if(names->size() != 2) {
      TEST_FAIL("[testHttpSession test Parse case7]");
      break;
    }

    if(!names->contains(createString("a")) || !names->contains(createString("b"))) {
      TEST_FAIL("[testHttpSession test Parse case8]");
      break;
    }

    break;
  }

  TEST_OK("[testHttpSession test Parse case100]");
}
