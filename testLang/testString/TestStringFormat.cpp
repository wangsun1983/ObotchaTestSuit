#include <stdio.h>
#include <iostream>
#include <type_traits>

#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void formattest() {

    while(1) {
    String str = st(String)::format("i say %s","hello");
    if(!str->equals("i say hello")){
      TEST_FAIL("[String Format Test {format()} case1]");
      break;
    }

    str = st(String)::format("%d,%s",1,"a");
    if(!str->equals("1,a")) {
      TEST_FAIL("[String Format Test {format()} case2]");
      break;
    }

    TEST_OK("[String Format Test {format()} case3]");
    break;
  }
}
