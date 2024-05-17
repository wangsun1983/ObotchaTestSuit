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

void testHashMap() {
    while(1) {
      HashMap<int,String> map = HashMap<int,String>::New();
      int sum = 0;
      for(int i = 0; i < 10;i++) {
        map->put(i,String::New(i));
        sum += i;
      }

      int sum2 = 0;
      String s = "";
      ForEveryOne(pair,map) {
        sum2 += pair->getKey();
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne HashMap case1");
      }

      break;
    }

    while(1) {
      HashMap<int,String> map = HashMap<int,String>::New();
      int count = 0;
      ForEveryOne(pair,map) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne HashMap case3");
      }
      break;
    }


    TEST_OK("ForEveryOne HashMap case100");
}
