#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkeListBase() {

    //case1 string putLast
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        std::vector<std::string> list;
        list.push_back("a");
        list.push_back("b");
        list.push_back("c");

        mList->putLast(createString("a"));
        mList->putLast(createString("b"));
        mList->putLast(createString("c"));

        if(mList->size() != 3) {
          TEST_FAIL("LinkedList base test1");
          break;
        }

        LinkedListIterator<String> iterator = mList->getIterator();
        int count = 0;
        while(iterator->hasValue()) {
          String v1 = iterator->getValue();
          if(!v1->sameAs(list[count])) {
            TEST_FAIL("v1 is %s,vv is %s ",v1->toChars(),list[count].c_str());
            TEST_FAIL("LinkedList base test2");
            break;
          }
          iterator->next();
          count++;
        }

        break;
    }

    //case2 int putLast
    while(1) {
        LinkedList<int> mList = createLinkedList<int>();

        std::vector<int> list;
        list.push_back(4);
        list.push_back(5);
        list.push_back(6);

        mList->putLast(4);
        mList->putLast(5);
        mList->putLast(6);

        if(mList->size() != 3) {
          TEST_FAIL("LinkedList base test3,size is %d ",mList->size());
          break;
        }

        LinkedListIterator<int> iterator = mList->getIterator();
        int count = 0;
        while(iterator->hasValue()) {
          int v1 = iterator->getValue();
          if(v1 != list[count]) {
            TEST_FAIL("LinkedList base test4,v1 is %d,vv is %d ",v1,list[count]);
            break;
          }
          iterator->next();
          count++;
        }

        break;
    }

    //case3 string putFirst
    while(1) {
        LinkedList<String> mList = createLinkedList<String>();
        std::vector<std::string> list;
        list.push_back("c");
        list.push_back("b");
        list.push_back("a");

        mList->putFirst(createString("a"));
        mList->putFirst(createString("b"));
        mList->putFirst(createString("c"));

        if(mList->size() != 3) {
          TEST_FAIL("LinkedList base test5");
          break;
        }

        LinkedListIterator<String> iterator = mList->getIterator();
        int count = 0;
        while(iterator->hasValue()) {
          String v1 = iterator->getValue();
          if(!v1->sameAs(list[count])) {
            TEST_FAIL("LinkedList base test5,v1 is %s,vv is %s ",v1->toChars(),list[count].c_str());
            break;
          }
          iterator->next();
          count++;
        }

        break;
    }

    //case4 int putFirst
    while(1) {
        LinkedList<int> mList = createLinkedList<int>();

        std::vector<int> list;
        list.push_back(6);
        list.push_back(5);
        list.push_back(4);

        mList->putFirst(4);
        mList->putFirst(5);
        mList->putFirst(6);

        if(mList->size() != 3) {
          TEST_FAIL("LinkedList base test6,size is %d ",mList->size());
          break;
        }

        LinkedListIterator<int> iterator = mList->getIterator();
        int count = 0;
        while(iterator->hasValue()) {
          int v1 = iterator->getValue();
          if(v1 != list[count]) {
            TEST_FAIL("LinkedList base test7,v1 is %d,vv is %d ",v1,list[count]);
            break;
          }
          iterator->next();
          count++;
        }

        break;
    }

    //case4 String iterator remove
    while(1) {
      LinkedList<String> mList = createLinkedList<String>();
      std::vector<std::string> list;
      list.push_back("a");
      //list.push_back("b");
      list.push_back("c");

      mList->putLast("a");
      mList->putLast("b");
      mList->putLast("c");

      LinkedListIterator<String> iterator = mList->getIterator();
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(v->sameAs("b")) {
          iterator->remove();
          continue;
        }
        iterator->next();
      }

      if(mList->size() != 2) {
        TEST_FAIL("LinkedList base test8");
      }

      iterator = mList->getIterator();
      int count = 0;
      while(iterator->hasValue()) {
          String v = iterator->getValue();
          if(!v->sameAs(list[count])) {
            TEST_FAIL("LinkedList base test9,v1 is %s,vv is %s ",v->toChars(),list[count].c_str());

            break;
          }
          iterator->next();
          count++;
      }
      break;
    }

    //case5 String iterator remove
    while(1) {
      LinkedList<Integer> mList = createLinkedList<Integer>();
      std::vector<int> list;
      list.push_back(4);
      //list.push_back(5);
      list.push_back(6);

      mList->putLast(createInteger(4));
      mList->putLast(createInteger(5));
      mList->putLast(createInteger(6));

      LinkedListIterator<Integer> iterator = mList->getIterator();
      while(iterator->hasValue()) {
        int v = iterator->getValue()->toValue();
        if(v == 5) {
          iterator->remove();
          continue;
        }
        iterator->next();
      }

      if(mList->size() != 2) {
        TEST_FAIL("LinkedList base test10");
      }

      iterator = mList->getIterator();
      int count = 0;
      while(iterator->hasValue()) {
          int v = iterator->getValue()->toValue();
          if(v != list[count]) {
            TEST_FAIL("LinkedList base test11,v1 is %d,vv is %d ",v,list[count]);

            break;
          }
          iterator->next();
          count++;
      }
      break;
    }

    TEST_OK("LinkedList base test100");

}
