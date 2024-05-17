#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TestData1) {
public:
  int i;
};

void testArrayList_MyData() {
  //[ArrayList<T> Test Start]

      //[ArrayList<T> Test {void add(T val)} Start]
      while(1){
          ArrayList<TestData1> list =ArrayList<TestData1>::New();
          TestData1 t1 = TestData1::New();
          t1->i = 1;

          TestData1 t2 = TestData1::New();
          t2->i = 2;

          TestData1 t3 = TestData1::New();
          t3->i = 3;

          TestData1 t4 = TestData1::New();
          t4->i = 4;

          list->add(t1);
          list->add(t2);
          list->add(t3);
          list->add(t4);

          if(list->size() != 4) {
             TEST_FAIL("[ArrayList<T> Test {void add(T val)} Size error]");
             break;
          }

          TestData1 t1_1 = list->get(0);
          TestData1 t1_2 = list->get(1);
          TestData1 t1_3 = list->get(2);
          TestData1 t1_4 = list->get(3);

          if(t1_1->i != 1 || t1_2->i != 2 || t1_3->i != 3 || t1_4->i != 4) {
            TEST_FAIL("[ArrayList<T> Test {void add(T val)} Value error]");
            break;
          }

          TEST_OK("[ArrayList<T> Test {void add(T val)} Start]");
          break;
      }

      //[ArrayList<T> Test {void add(ArrayList<T> list)} Start]
      while(1) {
          ArrayList<TestData1> list1 =ArrayList<TestData1>::New();
          ArrayList<TestData1> list2 =ArrayList<TestData1>::New();

          TestData1 tt1 = TestData1::New();
          tt1->i = 1;

          TestData1 tt2 = TestData1::New();
          tt2->i = 2;

          list1->add(tt1);
          list1->add(tt2);

          TestData1 tt1_1 = TestData1::New();
          tt1_1->i = 1;

          TestData1 tt2_1 = TestData1::New();
          tt2_1->i = 2;

          list2->add(tt1_1);
          list2->add(tt2_1);

          list1->add(list2);

          if(list1->size() != 4) {
            TEST_FAIL("[ArrayList<T> Test {void add(ArrayList<T> list)} Size error]");
            break;
          }

          TestData1 v1_1 = list1->get(0);
          TestData1 v1_2 = list1->get(1);
          TestData1 v1_3 = list1->get(2);
          TestData1 v1_4 = list1->get(3);

          if(v1_1->i != 1 || v1_2->i != 2 || v1_3->i != 1 || v1_4->i != 2) {
            TEST_FAIL("[ArrayList<T> Test {void add(ArrayList<T> list)} Value error]");
            break;
          }

          TEST_OK("[ArrayList<T> Test {void add(ArrayList<T> list)} Start]");
          break;
      }

      //[ArrayList<T> Test {void clear()} Start]
      while(1) {
          ArrayList<TestData1> clist =ArrayList<TestData1>::New();
          TestData1 cl1_1 = TestData1::New();
          cl1_1->i = 1;

          clist->add(cl1_1);
          int size = clist->size();
          clist->clear();
          if(clist->size() != 0 || size != 1) {
              TEST_FAIL("[ArrayList<T> Test {void clear()} Size error]");
              break;
          }

          TEST_OK("[ArrayList<T> Test {void clear()}]");
          break;
      }

      //[ArrayList<T> Test {remove(int index)} Start]
      while(1) {
          ArrayList<TestData1> clist =ArrayList<TestData1>::New();
          TestData1 t1 = TestData1::New();
          t1->i = 1;

          TestData1 t2 = TestData1::New();
          t2->i = 2;

          TestData1 t3 = TestData1::New();
          t3->i = 3;

          clist->add(t1);
          clist->add(t2);
          clist->add(t3);

          TestData1 tt1 = clist->removeAt(0);
          TestData1 tt2 = clist->removeAt(1);

          if(tt1->i != 1 || tt2->i != 3 || clist->size() != 1) {
            TEST_FAIL("[ArrayList<T> Test {remove(int index)} case1]");
            break;
          }

          bool isException = false;
          try {
              TestData1 tt3 = clist->removeAt(100);
          } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
          }

          if(!isException) {
            TEST_FAIL("[ArrayList<T> Test {remove(int index)} case2]");
            break;
          }

          TEST_OK("[ArrayList<T> Test {remove(int index)}]");
          break;
      }

      //[ArrayList<T> Test {remove(T val)} Start]
      while(1) {
          ArrayList<TestData1> clist =ArrayList<TestData1>::New();
          TestData1 t1 = TestData1::New();
          t1->i = 1;

          TestData1 t2 = TestData1::New();
          t2->i = 2;

          TestData1 t3 = TestData1::New();
          t3->i = 3;

          clist->add(t1);
          clist->add(t2);
          clist->add(t3);

          TestData1 tt1 = clist->get(1);
          int result = clist->remove(tt1);
          if(result == -1 || clist->size() != 2) {
            TEST_FAIL("[ArrayList<T> Test {remove(T val)} case1]");
            break;
          }

          result = clist->remove(t1);
          if(result == -1 || clist->size() != 1) {
            TEST_FAIL("[ArrayList<T> Test {remove(T val)} case2]");
            break;
          }

          TestData1 tt3 = TestData1::New();
          tt3->i = 100;
          result =clist->remove(tt3);
          if(result != -1 || clist->size() != 1) {
            TEST_FAIL("[ArrayList<T> Test {remove(T val)} case3]");
            break;
          }
          TEST_OK("[ArrayList<T> Test {remove(T val)}]");
          break;
      }

      //[ArrayList<T> Test {indexOf(T val)} Start]
      while(1) {
          ArrayList<TestData1> clist =ArrayList<TestData1>::New();
          TestData1 t1 = TestData1::New();
          t1->i = 1;

          TestData1 t2 = TestData1::New();
          t2->i = 2;

          TestData1 t3 = TestData1::New();
          t3->i = 3;

          clist->add(t1);
          clist->add(t2);
          clist->add(t3);

          int index = clist->indexOf(t2);
          if(index != 1) {
            TEST_FAIL("[ArrayList<T> Test {indexOf(T val)} case1]");
            break;
          }

          TestData1 t4 = clist->get(2);
          index = clist->indexOf(t4);
          if(index != 2) {
            TEST_FAIL("[ArrayList<T> Test {indexOf(T val)} case2]");
            break;
          }

          TestData1 t5 = t4;
          index = clist->indexOf(t5);
          if(index != 2) {
            TEST_FAIL("[ArrayList<T> Test {indexOf(T val)} case3]");
            break;
          }

          TestData1 t6 = TestData1::New();
          t6->i = 1;
          index = clist->indexOf(t6);
          if(index != -1) {
            TEST_FAIL("[ArrayList<T> Test {indexOf(T val)} case4]");
            break;
          }

          TEST_OK("[ArrayList<T> Test {indexOf(T val)}]");
          break;
      }

      //[ArrayList<T> Test {set(int index,T val)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->add(t1);
        clist->add(t2);
        clist->add(t3);

        TestData1 t4 = TestData1::New();
        t4->i = 4;

        bool isException = false;
        try {
          clist->set(8,t4);
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<T> Test {set(int index,T val)} case1]");
          break;
        }

        int size = clist->size();

        int result = clist->set(2,t4);
        if(result == -1) {
          TEST_FAIL("[ArrayList<T> Test {set(int index,T val)} case2]");
          break;
        }

        if(clist->size() != size) {
          TEST_FAIL("[ArrayList<T> Test {set(int index,T val)} case3]");
          break;
        }

        TestData1 t8 = clist->get(2);
        if(t8->i != t4->i) {
          TEST_FAIL("[ArrayList<T> Test {set(int index,T val)} case4]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {set(int index,T val)}]");
        break;
      }

      //[ArrayList<T> Test {get(int index)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->add(t1);
        clist->add(t2);
        clist->add(t3);

        TestData1 t1_1 = clist->get(0);
        TestData1 t1_2 = clist->get(1);
        TestData1 t1_3 = clist->get(2);

        if(t1_1->i != t1->i
          ||t1_2->i != t2->i
          ||t1_3->i != t3->i) {
            TEST_FAIL("[ArrayList<T> Test {get(int index)} case1]");
            break;
          }

        bool isException = false;
        try {
            TestData1 t1_4 = clist->get(200);
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<T> Test {get(int index)} case2]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {get(int index)}]");
        break;
      }


      //[ArrayList<T> Test {insert(int index,T val)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->add(t1);
        clist->add(t2);
        clist->add(t3);

        int size = clist->size();
        TestData1 t4 = TestData1::New();
        t4->i = 4;
        clist->insert(1,t4);

        TestData1 t5 = clist->get(1);
        TestData1 t6 = clist->get(2);

        if(t5->i != t4->i
         ||t6->i != t2->i) {
           TEST_FAIL("[ArrayList<T> Test {insert(int index,T val) case1]");
           break;
         }

         if(size != clist->size() - 1) {
           TEST_FAIL("[ArrayList<T> Test {insert(int index,T val) case2]");
           break;
         }

         TEST_OK("[ArrayList<T> Test {insert(int index,T val)]");
         break;
      }

      //[ArrayList<T> Test {insert(int index,ArrayList<T> list)} Start]
      while(1){
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->add(t1);
        clist->add(t2);
        clist->add(t3);

        int size = clist->size();

        ArrayList<TestData1> clist2 =ArrayList<TestData1>::New();
        TestData1 t4 = TestData1::New();
        t4->i = 4;

        TestData1 t5 = TestData1::New();
        t5->i = 5;

        clist2->add(t4);
        clist2->add(t5);

        int result = clist->insert(1,clist2);
        if(result != 0) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list) case1]");
          break;
        }

        if((size + clist2->size()) != clist->size()) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list) case2]");
          break;
        }

        TestData1 tt0 = clist->get(0);
        TestData1 tt1 = clist->get(1);
        TestData1 tt2 = clist->get(2);
        TestData1 tt3 = clist->get(3);
        TestData1 tt4 = clist->get(4);

        if(tt0->i != 1 || tt1->i != 4|| tt2->i != 5 || tt3->i != 2 || tt4->i != 3) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list) case3]");
          break;
        }

        bool isException = false;
        try {
          result = clist->insert(100,clist2);
        } catch(ArrayIndexOutOfBoundsException e) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list) case4]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {insert(int index,ArrayList<T> list)]");
        break;
      }

      //[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->add(t1);
        clist->add(t2);
        clist->add(t3);

        ArrayList<TestData1> clist2 =ArrayList<TestData1>::New();
        TestData1 t4 = TestData1::New();
        t4->i = 4;

        TestData1 t5 = TestData1::New();
        t5->i = 5;

        TestData1 t6 = TestData1::New();
        t6->i = 6;

        clist2->add(t4);
        clist2->add(t5);
        clist2->add(t6);

        int result = clist->insert(1,clist2,2);
        if(result != 0) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case1]");
          break;
        }

        TestData1 tt0 = clist->get(0);
        TestData1 tt1 = clist->get(1);
        TestData1 tt2 = clist->get(2);
        TestData1 tt3 = clist->get(3);
        TestData1 tt4 = clist->get(4);
        if(tt0->i != 1 || tt1->i != 4 || tt2->i != 5 || tt3->i != 2|| tt4->i != 3) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case2]");
          break;
        }

        clist->clear();
        clist->add(t1);
        clist->add(t2);
        clist->add(t3);
        bool isException = false;
        try {
            clist->insert(100,clist2,2);
        }catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case3]");
          break;
        }

        int isException2 = false;
        try {
          result = clist->insert(1,clist2,100);
        } catch(ArrayIndexOutOfBoundsException e) {
          isException2 = true;
        }

        if(tt0->i != 1 || tt1->i != 4 || tt2->i != 5 || tt3->i != 2 || tt4->i != 3) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case4]");
          break;
        }

        if(!isException2) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case4_0]");
          break;
        }

        bool isException3 = false;
        try {
            result = clist->insert(-1,clist2,100);
        } catch(ArrayIndexOutOfBoundsException e) {
            isException3 = true;
        }

        if(!isException3) {
            TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case4_1]");
            break;
        }

        if(tt0->i != 1 || tt1->i != 4 || tt2->i != 5 || tt3->i != 2 || tt4->i != 3) {
          TEST_FAIL("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)} case5]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {insert(int index,ArrayList<T> list,int length)}]");
        break;
      }

      //[ArrayList<T> Test {insertFirst(T val)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->insertFirst(t1);
        clist->insertFirst(t2);
        clist->insertFirst(t3);

        TestData1 tt1 = clist->get(0);
        TestData1 tt2 = clist->get(1);
        TestData1 tt3 = clist->get(2);

        if(tt1->i != 3 || tt2->i != 2 || tt3->i != 1) {
          TEST_FAIL("[ArrayList<T> Test {insertFirst(T val)}]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {insertFirst(T val)}]");
        break;
      }

      //[ArrayList<T> Test {insertFirst(ArrayList<T> list)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->add(t1);
        clist->add(t2);
        clist->add(t3);

        ArrayList<TestData1> clist2 =ArrayList<TestData1>::New();
        TestData1 t4 = TestData1::New();
        t4->i = 4;

        TestData1 t5 = TestData1::New();
        t5->i = 5;

        clist2->add(t4);
        clist2->add(t5);

        clist->insertFirst(clist2);

        TestData1 tt0 = clist->get(0);
        TestData1 tt1 = clist->get(1);
        TestData1 tt2 = clist->get(2);
        TestData1 tt3 = clist->get(3);
        TestData1 tt4 = clist->get(4);
        if(tt0->i != 4 || tt1->i != 5 || tt2->i != 1 || tt3->i != 2 || tt4->i != 3) {
          TEST_FAIL("[ArrayList<T> Test {insertFirst(ArrayList<T> list)} case1]");
          break;
        }

        int size = clist->size();
        ArrayList<TestData1>clist3 =ArrayList<TestData1>::New();
        clist->insertFirst(clist3);
        if(clist->size() != size) {
          TEST_FAIL("[ArrayList<T> Test {insertFirst(ArrayList<T> list)} case2]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {insertFirst(ArrayList<T> list)}]");
        break;
      }

      //[ArrayList<T> Test {void insertLast(T v)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->insertLast(t1);
        clist->insertLast(t2);
        clist->insertLast(t3);

        TestData1 tt0 = clist->get(0);
        TestData1 tt1 = clist->get(1);
        TestData1 tt2 = clist->get(2);

        if(tt0->i != 1 || tt1->i != 2 || tt2->i != 3) {
          TEST_FAIL("[ArrayList<T> Test {void insertLast(T v)}]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {void insertLast(T v)}]");
        break;
      }

      //[ArrayList<T> Test {insertLast(ArrayList<T> list)} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        TestData1 t1 = TestData1::New();
        t1->i = 1;

        TestData1 t2 = TestData1::New();
        t2->i = 2;

        TestData1 t3 = TestData1::New();
        t3->i = 3;

        clist->insertLast(t1);
        clist->insertLast(t2);
        clist->insertLast(t3);

        ArrayList<TestData1> clist2 =ArrayList<TestData1>::New();
        TestData1 t4 = TestData1::New();
        t4->i = 4;

        TestData1 t5 = TestData1::New();
        t5->i = 5;

        clist2->add(t4);
        clist2->add(t5);
        clist->add(clist2);

        TestData1 tt0 = clist->get(0);
        TestData1 tt1 = clist->get(1);
        TestData1 tt2 = clist->get(2);
        TestData1 tt3 = clist->get(3);
        TestData1 tt4 = clist->get(4);

        if(tt0->i != 1 || tt1->i != 2 || tt2->i != 3 || tt3->i != 4 || tt4->i != 5) {
          TEST_FAIL("[ArrayList<T> Test {void insertLast(T v)}]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {void insertLast(T v)}]");
        break;
      }

      //[ArrayList<T> Test {size()} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        if(clist->size() != 0) {
          TEST_FAIL("[ArrayList<T> Test {size()} case1]");
          break;
        }

        TestData1 t1 = TestData1::New();
        t1->i = 1;
        clist->add(t1);
        clist->add(t1);
        clist->add(t1);
        clist->add(t1);
        clist->add(t1);
        if(clist->size() != 5) {
          TEST_FAIL("[ArrayList<T> Test {size()} case2]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {size()}]");
        break;
      }

      //[ArrayList<T> Test {getIterator()} Start]
      while(1) {
        ArrayList<TestData1> clist =ArrayList<TestData1>::New();
        auto iterate = clist->getIterator();
        if(iterate == nullptr) {
          TEST_FAIL("[ArrayList<T> Test {getIterator()}]");
          break;
        }

        TEST_OK("[ArrayList<T> Test {getIterator()}]");
        break;
      }


  //[ListIterator<T> Test Start]

    //[ListIterator<T> Test {ListIterator(ArrayList<T> list)} Start]
    while(1) {
      ArrayList<TestData1> clist =ArrayList<TestData1>::New();
      TestData1 t1 = TestData1::New();
      t1->i = 1;

      TestData1 t2 = TestData1::New();
      t2->i = 2;

      TestData1 t3 = TestData1::New();
      t3->i = 3;

      clist->add(t1);
      clist->add(t2);
      clist->add(t3);
      auto iterator = ArrayListIterator<TestData1>::New(clist);

      int index = 1;
      bool isOk = true;
      while(iterator->hasValue()) {
          if(iterator->getValue()->i != index) {
              isOk = false;
              break;
          }
          index++;
          iterator->next();
      }

      if(!isOk) {
        TEST_FAIL("[ArrayList<T> Test {getValue()/hasValue()/next()}]");
        break;
      }

      TEST_OK("[ArrayList<T> Test {getValue()/hasValue()/next()}]");
      break;
    }

    //[ListIterator<T> Test {getValue()} Start]
    while(1) {
      ArrayList<TestData1> clist =ArrayList<TestData1>::New();
      TestData1 t1 = TestData1::New();
      t1->i = 1;

      TestData1 t2 = TestData1::New();
      t2->i = 2;

      TestData1 t3 = TestData1::New();
      t3->i = 3;

      clist->add(t1);
      clist->add(t2);
      clist->add(t3);

      auto iterator = clist->getIterator();
      int index = 1;
      bool isOk = true;
      while(iterator->hasValue()) {
          if(iterator->getValue()->i != index) {
              isOk = false;
              break;
          }
          index++;
          iterator->next();
      }

      if(!isOk) {
        TEST_FAIL("[ArrayList<T> Test {getValue()} case1]");
        break;
      }

      ArrayList<TestData1> clist2 =ArrayList<TestData1>::New();
      auto iterator2 = clist2->getIterator();
      bool isException = false;
      try {
        iterator2->getValue();
      }catch(ArrayIndexOutOfBoundsException e) {
           isException = true;
      }

      if(!isException) {
        TEST_FAIL("[ArrayList<T> Test {getValue()} case2]");
        break;
      }

      TEST_OK("[ArrayList<T> Test {getValue()}]");
      break;
    }

  //--[_ListIterator<T> Test {remove()} Start]
  while(1) {
    ArrayList<TestData1> list =ArrayList<TestData1>::New();
    TestData1 t1 = TestData1::New();
    t1->i = 1;

    TestData1 t2 = TestData1::New();
    t2->i = 2;

    TestData1 t3 = TestData1::New();
    t3->i = 3;

    TestData1 t4 = TestData1::New();
    t4->i = 4;

    TestData1 t5 = TestData1::New();
    t5->i = 5;

    list->add(t1);
    list->add(t2);
    list->add(t3);
    list->add(t4);
    list->add(t5);

    auto iterator = list->getIterator();
    while(iterator->hasValue()) {
      if(iterator->getValue()->i == 3) {
        iterator->remove();
      }else {
        iterator->next();
      }
    }

    if(list->size() != 4) {
        TEST_FAIL("[ListIterator<T> Test {remove()} case0]");
        break;
    }

    if(list->get(0)->i != 1 ||list->get(1)->i != 2
      ||list->get(2)->i != 4||list->get(3)->i != 5) {
        TEST_FAIL("[ListIterator<T> Test {remove()} case2]");
        break;
    }

    TEST_OK("[ListIterator<T> Test {remove()} case3]");
    break;
  }

}
