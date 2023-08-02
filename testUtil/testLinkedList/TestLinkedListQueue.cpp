#include <stdio.h>
#include <unistd.h>

#include "LinkedList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLinkeListQueue() {

    //case1 string takeFirst
    while(1) {
      LinkedList<String> list = createLinkedList<String>();
      list->putLast("a");
      list->putLast("b");
      list->putLast("c");
      list->putLast("d");
      list->putLast("e");

      std::vector<std::string> vect;
      vect.push_back("a");
      vect.push_back("b");
      vect.push_back("c");
      vect.push_back("d");
      vect.push_back("e");

      int size = list->size();
      int count = 0;
      while(size > 0) {
        String ss = list->takeFirst();
        if(!ss->sameAs(vect[count])) {
          TEST_FAIL("LinkedList queue test1");
        }
        count++;
        size--;
      }
      break;
    }

    //case2 int takeFirst
    while(1) {
      LinkedList<Integer> list = createLinkedList<Integer>();
      list->putLast(createInteger(1));
      list->putLast(createInteger(2));
      list->putLast(createInteger(3));
      list->putLast(createInteger(4));
      list->putLast(createInteger(5));

      std::vector<int> vect;
      vect.push_back(1);
      vect.push_back(2);
      vect.push_back(3);
      vect.push_back(4);
      vect.push_back(5);

      int size = list->size();
      int count = 0;
      while(size > 0) {
        int ss = list->takeFirst()->toValue();
        if(ss != vect[count]) {
          TEST_FAIL("LinkedList queue test2");
        }
        count++;
        size--;
      }
      break;
    }

    //case3 string takeFirst
    while(1) {
      LinkedList<String> list = createLinkedList<String>();
      list->putLast("a");
      list->putLast("b");
      list->putLast("c");
      list->putLast("d");
      list->putLast("e");

      std::vector<std::string> vect;
      vect.push_back("e");
      vect.push_back("d");
      vect.push_back("c");
      vect.push_back("b");
      vect.push_back("a");

      int size = list->size();
      int count = 0;
      while(size > 0) {
        String ss = list->takeLast();
        if(!ss->sameAs(vect[count])) {
          TEST_FAIL("LinkedList queue test3");
        }
        count++;
        size--;
      }
      break;
    }

    //case4 int takeFirst
    while(1) {
      LinkedList<Integer> list = createLinkedList<Integer>();
      list->putLast(createInteger(1));
      list->putLast(createInteger(2));
      list->putLast(createInteger(3));
      list->putLast(createInteger(4));
      list->putLast(createInteger(5));

      std::vector<int> vect;
      vect.push_back(5);
      vect.push_back(4);
      vect.push_back(3);
      vect.push_back(2);
      vect.push_back(1);

      int size = list->size();
      int count = 0;
      while(size > 0) {
        int ss = list->takeLast()->toValue();
        if(ss != vect[count]) {
          TEST_FAIL("LinkedList queue test4");
        }
        count++;
        size--;
      }
      break;
    }

    TEST_OK("LinkedList queue test100");


}
