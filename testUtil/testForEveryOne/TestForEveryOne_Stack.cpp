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
#include "Stack.hpp"

using namespace obotcha;

void testStack() {
    while(1) {
      Stack<int> list = createStack<int>();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->push(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne Stack case1");
      }

      break;
    }

    while(1) {
      Stack<String> list = createStack<String>();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne Stack case3");
      }
      break;
    }

    TEST_OK("ForEveryOne Stack case100");
}
