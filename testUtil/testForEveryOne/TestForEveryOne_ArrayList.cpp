#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testArrayList() {
    while(1) {
      ArrayList<int> list = createArrayList<int>();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->add(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne ArrayLit case1");
      }

      break;
    }

    while(1) {
      ArrayList<String> list = createArrayList<String>();
      list->add(createString("a"));
      list->add(createString("b"));
      list->add(createString("c"));
      list->add(createString("d"));
      list->add(createString("e"));
      list->add(createString("f"));

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(!abc->equals("abcdef")) {
        TEST_FAIL("ForEveryOne ArrayLit case2");
      }

      break;
    }

    while(1) {
      ArrayList<String> list = createArrayList<String>();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne ArrayLit case3");
      }
      break;
    }

    TEST_OK("ForEveryOne ArrayLit case100");
}
