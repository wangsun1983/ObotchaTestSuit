#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "List.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "List.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testList() {
    while(1) {
      List<int> list = createList<int>(128);
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list[i] = i;
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne List case1,sum is %d,sum2 is %d",sum,sum2);
      }

      break;
    }

    while(1) {
      List<String> list = createList<String>(6);
      list[0] = createString("a");
      list[1] = createString("b");
      list[2] = createString("c");
      list[3] = createString("d");
      list[4] = createString("e");
      list[5] = createString("f");

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(!abc->sameAs("abcdef")) {
        TEST_FAIL("ForEveryOne List case2");
      }

      break;
    }

    while(1) {
      List<String> list = createList<String>(2);
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 2) {
        TEST_FAIL("ForEveryOne List case3");
      }
      break;
    }

    TEST_OK("ForEveryOne List case100");
}
