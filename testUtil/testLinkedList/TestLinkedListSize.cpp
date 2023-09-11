#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"
#include "String.hpp"

using namespace obotcha;

void testLinkedListSize() {

    //case1 string takeFirst
    while(1) {
      LinkedList<String> list = createLinkedList<String>();
      list->putLast("a");
      list->putLast("b");
      list->putLast("c");
      list->putLast("d");
      list->putLast("e");
      if(list->size() != 5) {
        TEST_FAIL("LinkedList size test1,list->size is %d",list->size());
      }

      list->takeFirst();
      if(list->size() != 4) {
        TEST_FAIL("LinkedList size test2,list->size is %d",list->size());
      }

      list->takeLast();
      if(list->size() != 3) {
        TEST_FAIL("LinkedList size test3,list->size is %d",list->size());
      }

      list->putFirst("f");
      if(list->size() != 4) {
        TEST_FAIL("LinkedList size test4,list->size is %d",list->size());
      }
      break;
    }

    TEST_OK("LinkedList size test100");


}
