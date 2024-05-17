#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"
#include "String.hpp"

using namespace obotcha;

void testLinkeListQueueIterator() {

    //case1 string iterator
    while(1) {
      LinkedList<String> list = LinkedList<String>::New();
      list->putLast("a");
      list->putLast("b");
      list->putLast("c");
      list->putLast("d");
      list->putLast("e");

      std::string result[5] = {"a","b","c","d","e"};
      auto iterator = list->getIterator();
      int index = 0;
      while(iterator->hasValue()) {
          String v = iterator->getValue();
          if(!v->equals(String::New(result[index]))) {
            TEST_FAIL("LinkedList Iterator test1,v is %s,result is %s",v->toChars(),result[index].c_str());
          }
          index++;
          iterator->next();
      }

      if(index != 5) {
        TEST_FAIL("LinkedList Iterator test2,index is %d",index);
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
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(!v->equals(String::New(result[index]))) {
          TEST_FAIL("LinkedList Iterator test3,v is %s,result is %s",v->toChars(),result[index].c_str());
        }
        index++;
        iterator->next();
      }

      if(index != 4) {
        TEST_FAIL("LinkedList Iterator test4,index is %d",index);
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

      int index = 0;
      auto iterator = list->getIterator();
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(v->sameAs("b")) {
          iterator->remove();
          continue;
        }
        index++;
        iterator->next();
      }

      if(index != 4) {
        TEST_FAIL("LinkedList Iterator test5,index is %d",index);
      }

      std::string result[4] = {"a","c","d","e"};
      if(list->size() != 4) {
        TEST_FAIL("LinkedList Iterator test6");
      }

      auto iterator2 = list->getIterator();
      index = 0;
      while(iterator2->hasValue()) {
        String v = iterator2->getValue();
        if(!v->equals(String::New(result[index]))) {
          TEST_FAIL("LinkedList Iterator test7,v is %s,result is %s",v->toChars(),result[index].c_str());
        }
        index++;
        iterator2->next();
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
      int index = 0;
      auto iterator = list->getIterator();
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(v->sameAs("e")) {
          iterator->remove();
          continue;
        }
        index++;
        iterator->next();
      }

      if(iterator->hasValue()) {
        TEST_FAIL("LinkedList Iterator test8");
      }

      std::string result[4] = {"a","b","c","d"};
      if(list->size() != 4) {
        TEST_FAIL("LinkedList Iterator test9");
      }

      iterator = list->getIterator();
      index = 0;
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(!v->equals(String::New(result[index]))) {
          TEST_FAIL("LinkedList Iterator test10,v is %s,result is %s,index is %d",v->toChars(),result[index].c_str(),index);
        }
        index++;
        iterator->next();
      }

      if(index != 4) {
        TEST_FAIL("LinkedList Iterator test10");
      }
      break;
    }

    TEST_OK("LinkedList Iterator test100");


}
