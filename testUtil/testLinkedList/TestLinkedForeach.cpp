#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "String.hpp"
using namespace obotcha;

void testLinkeListForeach() {

    //case1 string iterator
    while(1) {
      LinkedList<String> list = LinkedList<String>::New();
      list->putLast("a");
      list->putLast("b");
      list->putLast("c");
      list->putLast("d");
      list->putLast("e");

      std::string result[5] = {"a","b","c","d","e"};
      int index = 0;
      ForEveryOne(v,list){
          if(!v->equals(String::New(result[index]))) {
            TEST_FAIL("LinkedList ForEveryOne test1,v is %s,result is %s",v->toChars(),result[index].c_str());
          }
          index++;
      }

      if(index != 5) {
        TEST_FAIL("LinkedList ForEveryOne test2,index is %d",index);
      }
      break;
    }

    while(1) {
      LinkedList<String> list = LinkedList<String>::New();
      list->putLast("a");
      list->putLast("b");
      list->putLast("c");
      list->putLast("d");
      list->putLast("e");

      auto iterator = list->getIterator();
      iterator->remove();
      std::string result[4] = {"b","c","d","e"};
      int index = 0;
      ForEveryOne(v,list) {
        if(!v->equals(String::New(result[index]))) {
          TEST_FAIL("LinkedList ForEveryOne test3,v is %s,result is %s",v->toChars(),result[index].c_str());
        }
        index++;
      }

      if(index != 4) {
        TEST_FAIL("LinkedList ForEveryOne test4,index is %d",index);
      }
      break;
    }


    TEST_OK("LinkedList ForEveryOne test100");
}
