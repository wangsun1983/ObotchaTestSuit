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
#include "LinkedList.hpp"

using namespace obotcha;

void testLinkedList() {
    while(1) {
      LinkedList<int> list = createLinkedList<int>();
      int sum = 0;
      for(int i = 0;i < 128;i++) {
        sum += i;
        list->putLast(i);
      }

      int sum2 = 0;
      ForEveryOne(v,list) {
        sum2 += v;
      }

      if(sum != sum2) {
        TEST_FAIL("ForEveryOne LinkedList case1");
      }

      break;
    }

    while(1) {
      LinkedList<String> list = createLinkedList<String>();
      list->putLast(createString("a"));
      list->putLast(createString("b"));
      list->putLast(createString("c"));
      list->putLast(createString("d"));
      list->putLast(createString("e"));
      list->putLast(createString("f"));

      String abc = "";
      ForEveryOne(v,list) {
        abc = abc->append(v);
      }

      if(!abc->equals("abcdef")) {
        TEST_FAIL("ForEveryOne LinkedList case2");
      }

      break;
    }

    while(1) {
      LinkedList<String> list = createLinkedList<String>();
      int count = 0;
      ForEveryOne(s,list) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne LinkedList case3");
      }
      break;
    }

    TEST_OK("ForEveryOne LinkedList case100");
}