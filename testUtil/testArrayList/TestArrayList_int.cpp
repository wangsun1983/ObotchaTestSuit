#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testArrayList_dataType_int() {
  //--[_ArrayList<int> Test {add(int val)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);

    if(list->size() != 2) {
      TEST_FAIL("[ArrayList<int> Test {add(int val)} case0]");
      break;
    }

    if(list->get(0) != 1
    ||list->get(1) != 2) {
      TEST_FAIL("[ArrayList<int> Test {add(int val)} case1]");
      break;
    }

    int t;
    int size = list->size();
    list->add(t);
    if(size == list->size()) {
      TEST_FAIL("[ArrayList<int> Test {add(int val)} case2]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {add(int val)}]");
    break;
  }

  //--[_ArrayList<int> Test {add(int val)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);

    if(list->size() != 2) {
      TEST_FAIL("[ArrayList<int> Test {add(int val)} case0]");
      break;
    }

    if(list->get(0) != 1
    ||list->get(1) != 2) {
      TEST_FAIL("[ArrayList<int> Test {add(int val)} case1]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {add(int val)}]");
    break;
  }

  //--[_ArrayList<int> Test {add(ArrayList<int> list)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);

    ArrayList<int>list2 = createArrayList<int>();
    list2->add(3);
    list2->add(4);
    list->add(list2);

    if(list->size() != 4) {
      TEST_FAIL("[ArrayList<int> Test {add(ArrayList<int> list)} case0]");
      break;
    }

    if(list->get(0) != 1
    ||list->get(1) != 2
    ||list->get(2) != 3
    ||list->get(3) != 4) {
      TEST_FAIL("[ArrayList<int> Test {add(ArrayList<int> list)} case1]");
      break;
    }

/*
    ArrayList<int>list3;
    int size = list->size();
    list->add(list3);
    if(size != list->size()) {
      TEST_FAIL("[ArrayList<int> Test {add(ArrayList<int> list)} case2]");
      break;
    }
*/
    TEST_OK("[ArrayList<int> Test {add(ArrayList<int> val)}]");
    break;
  }
  //--[_ArrayList<int> Test {clear()} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    int size = list->size();
    list->clear();
    if(size == 0 || list->size() != 0) {
      TEST_FAIL("[ArrayList<int> Test {clear()} case0]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {clear()}]");
    break;
  }
  //--[_ArrayList<int> Test {remove(int index)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    int i = list->removeAt(2);
    if(i != 3) {
      TEST_FAIL("[ArrayList<int> Test {remove(int index)} case0]");
      break;
    }

    if(list->size() != 2) {
      TEST_FAIL("[ArrayList<int> Test {remove(int index)} case1]");
      break;
    }

    bool isException = false;
    try {
         int i2 = list->removeAt(100);
    } catch(ArrayIndexOutOfBoundsException e) {
         isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {remove(int index)} case2]");
      break;
    }

    isException = false;
    try {
        int i3 = list->removeAt(-1);
    } catch(ArrayIndexOutOfBoundsException e) {
         isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {remove(int index)} case3]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {remove(int index)}]");
    break;
  }

  //--[_ArrayList<int> Test {remove(int v)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    int result = list->remove(2);
    if(result == -1) {
      TEST_FAIL("[ArrayList<int> Test {remove(int v)} case0]");
      break;
    }

    if(list->size() != 2
      ||list->get(0) != 1
      ||list->get(1) != 3){
        TEST_FAIL("[ArrayList<int> Test {remove(int v)} case1]");
        break;
    }

    int t1 = 100;
    if(list->remove(t1) != -1) {
      TEST_FAIL("[ArrayList<int> Test {remove(int v)} case2]");
      break;
    }

/*
    int t2;
    int size = list->size();
    if(list->remove(t2) != -1) {
      TEST_FAIL("[ArrayList<int> Test {remove(int v)} case3]");
      break;
    }

    if(size != list->size()) {
      TEST_FAIL("[ArrayList<int> Test {remove(int v)} case4]");
      break;
    }*/

    TEST_OK("[ArrayList<int> Test {remove(int v)}]");
    break;
  }

  //--[_ArrayList<int> Test {indexOf(int v)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    if(list->indexOf(1) != 0
      ||list->indexOf(2) != 1
      ||list->indexOf(3) != 2) {
        TEST_FAIL("[ArrayList<int> Test {indexOf(int v)} case0]");
        break;
    }

    if(list->indexOf(100) != -1) {
      TEST_FAIL("[ArrayList<int> Test {indexOf(int v)} case1]");
      break;
    }
/*
    int p;
    if(list->indexOf(p) != -1) {
      TEST_FAIL("[ArrayList<int> Test {indexOf(int v)} case2]");
      break;
    }*/

    TEST_OK("[ArrayList<int> Test {indexOf(int v)}]");
    break;
  }

  //--[_ArrayList<int> Test {set(int index,int val)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->set(0,2);
    if(list->get(0) != 2
    ||list->get(1) != 2
    ||list->get(2) != 3) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case1]");
      break;
    }

    bool isException = false;
    try {
        list->set(100,1);
    } catch(ArrayIndexOutOfBoundsException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case3]");
      break;
    }

    if(list->get(0) != 2
    ||list->get(1) != 2
    ||list->get(2) != 3) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case4]");
      break;
    }

    if(list->size() != 3) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case5]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {set(int index,int val)}]");
    break;
  }

  //--[_ArrayList<int> Test {set(int index,int val)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->set(0,2);
    if(list->get(0) != 2
    ||list->get(1) != 2
    ||list->get(2) != 3) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case1]");
      break;
    }

    bool isException = false;
    try {
        list->set(100,1);
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case3]");
      break;
    }

    if(list->get(0) != 2
    ||list->get(1) != 2
    ||list->get(2) != 3) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case4]");
      break;
    }

    if(list->size() != 3) {
      TEST_FAIL("[ArrayList<int> Test {set(int index,int val)} case5]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {set(int index,int val)}]");
    break;
  }

  //--[_ArrayList<int> Test {get(int index)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    int v1 = list->get(1);
    if(v1 != 2) {
      TEST_FAIL("[ArrayList<int> Test {get(int index)} case0]");
      break;
    }

    bool isException = false;
    try {
        int v2 = list->get(1000);
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {get(int index)} case1]");
      break;
    }

    isException = false;
    try {
        int v3 = list->get(-1);
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {get(int index)} case2]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {get(int index)}]");
    break;
  }

  //--[_ArrayList<int> Test {insert(int index,int val)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->insert(1,4);
    if(list->get(0) != 1
    ||list->get(1) != 4
    ||list->get(2) != 2
    ||list->get(3) != 3) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case0]");
      break;
    }

    int size = list->size();
    bool isException = false;
    try {
        int result = list->insert(100,4);
    } catch(ArrayIndexOutOfBoundsException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case1]");
      break;
    }

    isException = false;
    try {
        list->insert(-1,4);
    } catch(ArrayIndexOutOfBoundsException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case2]");
      break;
    }

    int ii;
    isException = false;
    try {
        list->insert(-1,ii);
    } catch(ArrayIndexOutOfBoundsException e) {
          isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case2]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insert(int index,int val)}]");
    break;
  }

  //--[_ArrayList<int> Test {insert(int index,int val)} Start]
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->insert(1,4);
    if(list->get(0) != 1
    ||list->get(1) != 4
    ||list->get(2) != 2
    ||list->get(3) != 3) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case0]");
      break;
    }

    int size = list->size();
    bool isException = false;
    try {
        int result = list->insert(100,4);
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case1]");
      break;
    }

    isException = false;
    try {
        list->insert(-1,4);
    } catch(ArrayIndexOutOfBoundsException e) {
         isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case2]");
      break;
    }

    int currentSize = list->size();
    list->insert(0,100);
    if(list->get(0) != 100 && (list->size() != (currentSize + 1))) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,int val)} case3]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insert(int index,int val)}]");
    break;
  }

  //int insert(int index,ArrayList<int> list);
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    ArrayList<int> list2 = createArrayList<int>();
    list2->add(4);
    list2->add(5);
    list2->add(6);

    list->insert(1,list2);
    if(list->get(0) != 1
    ||list->get(1) != 4
    ||list->get(2) != 5
    ||list->get(3) != 6
    ||list->get(4) != 2
    ||list->get(5) != 3) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list)} case0]");
      break;
    }

    int size = list->size();
    bool isException = false;
    try {
        int result = list->insert(100,list2);
    } catch(ArrayIndexOutOfBoundsException e) {
         isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list)} case1]");
      break;
    }

    isException = false;
    size = list->size();
    try {
        list->insert(-1,list2);
    } catch(ArrayIndexOutOfBoundsException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list)} case2]");
      break;
    }

    ArrayList<int>list3 = createArrayList<int>();
    list3->add(10);
    list3->add(11);
    list3->add(12);

    ArrayList<int>list4 = createArrayList<int>();
    list4->add(13);
    list4->add(14);
    list4->add(15);

    list3->insert(0,list4);
    if(list3->get(0) != 13
    ||list3->get(1) != 14
    ||list3->get(2) != 15
    ||list3->get(3) != 10
    ||list3->get(4) != 11
    ||list3->get(5) != 12) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list)} case3]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insert(int index,ArrayList<int> list)}]");
    break;
  }

  //int insert(int index,ArrayList<int> list,int length);
  while(1) {
    ArrayList<int>list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    ArrayList<int> list2 = createArrayList<int>();
    list2->add(4);
    list2->add(5);
    list2->add(6);

    list->insert(1,list2,2);
    if(list->get(0) != 1
    ||list->get(1) != 4
    ||list->get(2) != 5
    ||list->get(3) != 2
    ||list->get(4) != 3) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case0]");
      break;
    }

    if(list->size() != 5) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case1]");
      break;
    }

    int size = list->size();
    bool isException = false;
    try {
        list->insert(100,list2,5);
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case1]");
      break;
    }

    //size != list->size();
    isException = false;
    try {
        list->insert(-1,list2,100);
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case2]");
      break;
    }

    ArrayList<int>list3 = createArrayList<int>();
    list3->add(10);
    list3->add(11);
    list3->add(12);

    ArrayList<int>list4 = createArrayList<int>();
    list4->add(13);
    list4->add(14);
    list4->add(15);

    list3->insert(0,list4,2);
    if(list3->get(0) != 13
    ||list3->get(1) != 14
    ||list3->get(2) != 10
    ||list3->get(3) != 11
    ||list3->get(4) != 12) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case3]");
      break;
    }

    if(list3->size() != 5) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case4]");
      break;
    }

    ArrayList<int>list5 = createArrayList<int>();
    list5->add(10);
    list5->add(11);
    list5->add(12);

    ArrayList<int>list6 = createArrayList<int>();
    list6->add(13);
    list6->add(14);
    list6->add(15);

    bool isException1 = false;
    try {
        int result = list5->insert(0,list6,100);
    }catch(ArrayIndexOutOfBoundsException e) {
        isException1 = true;
    }

    if(!isException1) {
        TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case4_1]");
    }



#if 0
    TEST_FAIL("list5[0] is %d \n",list5->get(0));
    TEST_FAIL("list5[1] is %d \n",list5->get(1));
    TEST_FAIL("list5[2] is %d \n",list5->get(2));
    TEST_FAIL("list5[3] is %d \n",list5->get(3));
    TEST_FAIL("list5[4] is %d \n",list5->get(4));
    TEST_FAIL("list5[5] is %d \n",list5->get(5));
#endif

    if(list5->get(0) != 10
      ||list5->get(1) != 11
      ||list5->get(2) != 12) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case5]");
      break;
    }

    if(list5->size() != 3) {
      TEST_FAIL("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)} case6]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insert(int index,ArrayList<int> list,int length)}]");
    break;
  }

  //void insertFirst(int val);
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->insertFirst(4);
    if(list->get(0) != 4
       ||list->get(1) != 1
       ||list->get(2) != 2
       ||list->get(3) != 3) {
         TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case1]");
         break;
    }

    if(list->size() != 4) {
        TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case2]");
        break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    list2->insertFirst(4);
    if(list2->get(0) != 4) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case3]");
      break;
    }

    if(list2->size() != 1) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case4]");
      break;
    }

    ArrayList<int> list3 = createArrayList<int>();
    int nt;
    list3->insertFirst(nt);
    if(list3->size() == 0) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case5]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insertFirst(int val)}]");
    break;
  }

  //void insertFirst(int val);
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->insertFirst(4);
    if(list->get(0) != 4
       ||list->get(1) != 1
       ||list->get(2) != 2
       ||list->get(3) != 3) {
         TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case1]");
         break;
    }

    if(list->size() != 4) {
        TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case2]");
        break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    list2->insertFirst(4);
    if(list2->get(0) != 4) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case3]");
      break;
    }

    if(list2->size() != 1) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(int val)} case4]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insertFirst(int val)}]");
    break;
  }

  //void insertFirst(ArrayList<int> list);
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    ArrayList<int> list2 = createArrayList<int>();
    list2->add(4);
    list2->add(5);
    list2->add(6);
    list->insertFirst(list2);

    if(list->get(0) != 4
      ||list->get(1) != 5
      ||list->get(2) != 6
      ||list->get(3) != 1
      ||list->get(4) != 2
      ||list->get(5) != 3) {
        TEST_FAIL("[ArrayList<int> Test {insertFirst(ArrayList<int> list)} case1]");
        break;
      }

    ArrayList<int> list3 = createArrayList<int>();
    list3->add(1);
    list3->add(2);

    ArrayList<int> list4 = createArrayList<int>();
    list4->insertFirst(list4);

    if(list3->get(0) != 1
      ||list3->get(1) != 2){
        TEST_FAIL("[ArrayList<int> Test {insertFirst(ArrayList<int> list)} case2]");
        break;
      }

    if(list3->size() != 2) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(ArrayList<int> list)} case3]");
      break;
    }

/*
    ArrayList<int> list5;
    list3->insertFirst(list5);
    if(list3->size() != 2) {
      TEST_FAIL("[ArrayList<int> Test {insertFirst(ArrayList<int> list)} case4]");
      break;
    }
*/
    TEST_OK("[ArrayList<int> Test {insertFirst(ArrayList<int> list)}]");
    break;
  }

  //void insertLast(int v);
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->insertLast(4);
    if(list->get(0) != 1
      ||list->get(1) != 2
      ||list->get(2) != 3
      ||list->get(3) != 4) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case1]");
        break;
    }

    if(list->size() != 4) {
      TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case2]");
      break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    list2->add(1);
    list2->add(2);
    list2->add(3);
    int t2;
    list2->insertLast(t2);

    if(list2->get(0) != 1
      ||list2->get(1) != 2
      ||list2->get(2) != 3) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case3]");
        break;
    }

    if(list2->size() != 4) {
      TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case4]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insertLast(int v)} case5]");
    break;
  }

  //void insertLast(int v);
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    list->insertLast(4);
    if(list->get(0) != 1
      ||list->get(1) != 2
      ||list->get(2) != 3
      ||list->get(3) != 4) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case1]");
        break;
    }

    if(list->size() != 4) {
      TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case2]");
      break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    list2->insertLast(1);

    if(list2->size() != 1) {
      TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case3]");
      break;
    }

    if(list2->get(0) != 1) {
      TEST_FAIL("[ArrayList<int> Test {insertLast(int v)} case4]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {insertLast(int v)} case5]");
    break;
  }

  //insertLast(ArrayList<int> list);
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);

    ArrayList<int> list2 = createArrayList<int>();
    list2->add(4);
    list2->add(5);
    list2->add(6);

    list->insertLast(list2);
    if(list->get(0) != 1
      ||list->get(1) != 2
      ||list->get(2) != 3
      ||list->get(3) != 4
      ||list->get(4) != 5
      ||list->get(5) != 6) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(ArrayList<int> v)} case1]");
        break;
    }

    if(list->size() != 6) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(ArrayList<int> v)} case2]");
        break;
    }

    ArrayList<int> list3 = createArrayList<int>();
    list3->add(1);
    list3->add(2);
    list3->add(3);
/*
    ArrayList<int> list4;
    list3->insertLast(list4);
*/
    if(list3->get(0) != 1
      ||list3->get(1) != 2
      ||list3->get(2) != 3) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(ArrayList<int> v)} case3]");
        break;
    }

    if(list3->size() != 3) {
        TEST_FAIL("[ArrayList<int> Test {insertLast(ArrayList<int> v)} case4]");
        break;
    }

    TEST_OK("[ArrayList<int> Test {insertLast(ArrayList<int> v)} case5]");
    break;
  }

  //int size();
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    if(list->size() != 3) {
      TEST_FAIL("[ArrayList<int> Test {size()} case1]");
      break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    if(list2->size() != 0) {
      TEST_FAIL("[ArrayList<int> Test {size()} case2]");
      break;
    }

    TEST_OK("[ArrayList<int> Test {size()} case3]");
    break;
  }

  //ListIterator<int> getValue;
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);

    ListIterator<int>iterator = list->getIterator();
    int index = 1;
    while(iterator->hasValue() && index != list->size()) {
      int v = iterator->getValue();
      if(v != index) {
        TEST_FAIL("[ListIterator<int> Test {getValue()} case1]");
        break;
      }

      iterator->next();
      index++;
    }

    ArrayList<int> list1 = createArrayList<int>();
    ListIterator<int>iterator1 = list1->getIterator();
    bool isException = false;
    try {
        int v = iterator1->getValue();
    } catch(ArrayIndexOutOfBoundsException e) {
       isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ListIterator<int> Test {getValue()} case2]");
      break;
    }

    TEST_OK("[ListIterator<int> Test {getValue()} case3]");
    break;
  }

  //ListIterator<int> hasValue();
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    ListIterator<int> iterator = list->getIterator();
    if(!iterator->hasValue()) {
      TEST_FAIL("[ListIterator<int> Test {hasValue()} case1]");
      break;
    }

    iterator->next();
    iterator->next();
    iterator->next();

    if(iterator->hasValue()) {
      TEST_FAIL("[ListIterator<int> Test {hasValue()} case2]");
      break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    ListIterator<int> iterator2 = list2->getIterator();
    if(iterator2->hasValue()) {
      TEST_FAIL("[ListIterator<int> Test {hasValue()} case3]");
      break;
    }

    TEST_OK("[ListIterator<int> Test {hasValue()} case4]");
    break;
  }

  // ListIterator<int> next();
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    ListIterator<int> iterator = list->getIterator();

    iterator->next();
    iterator->next();
    if(iterator->next()) {
      TEST_FAIL("[ListIterator<int> Test {next()} case1]");
      break;
    }

    ArrayList<int> list2 = createArrayList<int>();
    ListIterator<int> iterator2 = list2->getIterator();

    if(iterator2->next()) {
      TEST_FAIL("[ListIterator<int> Test {next()} case2]");
      break;
    }

    TEST_OK("[ListIterator<int> Test {next()} case3]");
    break;
  }

  //--[_ListIterator<int> Test {remove()} Start]
  while(1) {
    ArrayList<int> list = createArrayList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    ListIterator<int> iterator = list->getIterator();
    while(iterator->hasValue()) {
      if(iterator->getValue() == 3) {
        iterator->remove();
      }else {
        iterator->next();
      }
    }

    if(list->size() != 4) {
        TEST_FAIL("[ListIterator<int> Test {remove()} case0]");
        break;
    }

    if(list->get(0) != 1 ||list->get(1) != 2
      ||list->get(2) != 4||list->get(3) != 5) {
        TEST_FAIL("[ListIterator<int> Test {remove()} case2]");
        break;
    }

    TEST_OK("[_ListIterator<int> Test {remove()} case3]");
    break;
  }
}
