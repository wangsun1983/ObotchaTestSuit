#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  //_Integer(int v);
  while(1) {
      Integer v1 = createInteger(10);
      if(v1->toValue() != 10){
          TEST_FAIL("Integer construct test1");
          break;
      }

      TEST_OK("Boolean construct test");
      break;
  }

  //  _Integer(Integer v);
  while(1) {
    Integer v1 = createInteger(11);
    Integer v2 = createInteger(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Integer construct test3");
      break;
    }

    Integer v3;
    try {
      Integer v4 = createInteger(v3);
      TEST_FAIL("Integer construct test4");
    } catch(InitializeException e) {}

    TEST_OK("Integer construct test5");
    break;
  }

  //int toValue();
  while(1) {
    Integer v1 = createInteger(11);
    Integer v2 = createInteger(v1);
    if(v2->toValue() != 11) {
      TEST_FAIL("Integer toValue test1");
      break;
    }

    TEST_OK("Integer toValue test1");
    break;
  }

  //bool equals(Integer p);
  while(1) {
    Integer v1 = createInteger(11);
    Integer v2 = createInteger(11);
    if(!v1->equals(v2)) {
      TEST_FAIL("Integer equals test1");
      break;
    }

    TEST_OK("Integer equals test3");
    break;
  }

  //bool equals(int p);
  while(1) {
    Integer v1 = createInteger(11);
    if(!v1->equals(11)) {
      TEST_FAIL("Integer equals test4");
      break;
    }

    TEST_OK("Integer equals test5");
    break;
  }

  //==
  while(1) {
    Integer v1 = createInteger(12);
    Integer v2 = createInteger(12);
    if(v1 != v2) {
      TEST_FAIL("Integer [==] test1");
      break;
    }

    TEST_OK("Integer [==] test1");
    break;
  }

}
