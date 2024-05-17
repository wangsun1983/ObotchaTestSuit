#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "Boolean.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testArrayList_Boolean() {
  //ArrayList<Boolean> add
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));
    if(list->get(0)->toValue() != true
      ||list->get(1)->toValue() != false
      ||list->get(2)->toValue() != true) {
        TEST_FAIL("[ArrayList<Boolean> Test {add()} case1]");
        break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    Boolean t2;
    list2->add(t2);
    if(list2->size() == 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {add()} case2]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {add()} case3]");
    break;
  }

  //ArrayList<Boolean> add(bool val);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));
    if(list->get(0)->toValue() != true
      ||list->get(1)->toValue() != false
      ||list->get(2)->toValue() != true) {
        TEST_FAIL("[ArrayList<Boolean> Test {add(bool val)} case1]");
        break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    Boolean t2;
    list2->add(t2);
    if(list2->size() == 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {add(bool val)} case2]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {add(bool val)} case3]");
    break;
  }

  //void add(ArrayList<Boolean> list);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(true));

    list->add(list2);
    if(list->get(0)->toValue() != true
      ||list->get(1)->toValue() != false
      ||list->get(2)->toValue() != true
      ||list->get(3)->toValue() != false
      ||list->get(4)->toValue() != true) {
        TEST_FAIL("[ArrayList<Boolean> Test {add(ArrayList<Boolean> list)} case1]");
        break;
    }

    if(list->size() != 5) {
      TEST_FAIL("[ArrayList<Boolean> Test {add(ArrayList<Boolean> list)} case2]");
      break;
    }

    ArrayList<Boolean> list3 = ArrayList<Boolean>::New();
    list3->add(Boolean::New(true));
    list3->add(Boolean::New(false));
    list3->add(Boolean::New(true));

    ArrayList<Boolean> list4 = ArrayList<Boolean>::New();
    list3->add(list4);

    if(list3->get(0)->toValue() != true
      ||list3->get(1)->toValue() != false
      ||list3->get(2)->toValue() != true){
        TEST_FAIL("[ArrayList<Boolean> Test {add(ArrayList<Boolean> list)} case3]");
        break;
    }

    if(list3->size() != 3) {
      TEST_FAIL("[ArrayList<Boolean> Test {add(ArrayList<Boolean> list)} case4]");
      break;
    }
/*
    ArrayList<Boolean> list5;
    list3->add(list5);
*/
    if(list3->size() != 3) {
      TEST_FAIL("[ArrayList<Boolean> Test {add(ArrayList<Boolean> list)} case5]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {add(ArrayList<Boolean> list)} case6]");
    break;
  }

  //void clear();
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));
    int size = list->size();
    list->clear();
    if(size != 3 || list->size() != 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {clear()} case1]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->clear();
    if(list2->size() != 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {clear()} case2]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {clear()} case3]");
    break;
  }

  //Boolean remove(int index);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));

    Boolean v1 = list->removeAt(0);
    if(!v1->sameAs(true)) {
      TEST_FAIL("[ArrayList<Boolean> Test {remove(int index)} case1]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(true));
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(true));

    bool isException = false;
    try {
      Boolean v2 = list2->removeAt(100);
    } catch(ArrayIndexOutOfBoundsException e) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {remove(int index)} case2]");
      break;
    }

    isException = false;

    ArrayList<Boolean> list3 = ArrayList<Boolean>::New();
    try {
        Boolean v3 = list3->removeAt(2);
    } catch(ArrayIndexOutOfBoundsException e) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {remove(int index)} case3]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {remove(int index)} case4]");
    break;
  }

  //int remove(Boolean v);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));

    int index = list->remove(Boolean::New(false));
    if(index != 1) {
      TEST_FAIL("[ArrayList<Boolean> Test {remove(Boolean v)} case1]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(true));

    int index2 = list2->remove(Boolean::New(false));
    if(index2 != -1) {
      TEST_FAIL("[ArrayList<Boolean> Test {remove(Boolean v)} case2]");
      break;
    }

    int size = list2->size();
    Boolean v3;
    list2->remove(v3);
    if(list2->size() != size) {
      TEST_FAIL("[ArrayList<Boolean> Test {remove(Boolean v)} case3]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {remove(Boolean v)} case4]");
    break;
  }

  //int indexOf(Boolean v);
  while(1) {
    ArrayList<Boolean>list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));

    if(list->indexOf(Boolean::New(true)) != 0
      ||list->indexOf(Boolean::New(false)) != 2) {
        TEST_FAIL("[ArrayList<Boolean> Test {indexOf(Boolean v)} case0]");
        break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(true));
    list2->add(Boolean::New(true));

    if(list2->indexOf(Boolean::New(false)) != -1) {
      TEST_FAIL("[ArrayList<Boolean> Test {indexOf(Boolean v)} case1]");
      break;
    }

    Boolean p;
    if(list2->indexOf(p) != -1) {
      TEST_FAIL("[ArrayList<Boolean> Test {indexOf(Boolean v)} case2]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {indexOf(Boolean v)}]");
    break;
  }

  //int set(int index,Boolean val);
  while(1) {
    ArrayList<Boolean>list = ArrayList<Boolean>::New();
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));

    list->set(0,Boolean::New(true));
    if(list->get(0)->toValue() != true
    ||list->get(1)->toValue() != false
    ||list->get(2)->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,Boolean val)} case1]");
      break;
    }

    Boolean t1;
    int result = list->set(1,t1);
    if(result != 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,Boolean val)} case2]");
      break;
    }

    bool isException = false;
    try {
      result = list->set(100,Boolean::New(true));
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,Boolean val)} case3]");
      break;
    }

    if(list->get(0)->toValue() != true
    ||list->get(1) != nullptr
    ||list->get(2)->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,Boolean val)} case4]");
      break;
    }

    if(list->size() != 3) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,Boolean val)} case5]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {set(int index,Boolean val)}]");
    break;
  }

  //int set(int index,bool val);
  while(1) {
    ArrayList<Boolean>list = ArrayList<Boolean>::New();
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));

    list->set(0,Boolean::New((true)));
    if(list->get(0)->toValue() != true
    ||list->get(1)->toValue() != false
    ||list->get(2)->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,bool val)} case1]");
      break;
    }

    Boolean t1;
    int result = list->set(1,t1);
    if(result != 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,bool val)} case2]");
      break;
    }

    bool isException = false;
    try {
      result = list->set(100,Boolean::New(true));
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,bool val)} case3]");
      break;
    }

    if(list->get(0)->toValue() != true
    ||list->get(1) != nullptr
    ||list->get(2)->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,bool val)} case4]");
      break;
    }

    if(list->size() != 3) {
      TEST_FAIL("[ArrayList<Boolean> Test {set(int index,bool val)} case5]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {set(int index,bool val)}]");
    break;
  }

  //Boolean get(int index);
  while(1) {
    ArrayList<Boolean>list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));

    Boolean v1 = list->get(1);
    if(v1->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {get(int index)} case0]");
      break;
    }

    bool isException = false;
    try {
      Boolean v2 = list->get(1000);
      if(v2 != nullptr) {
      }
    } catch(...) {
      isException = true;
    }
    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {get(int index)} case1]");
      break;
    }

    isException = false;
    try {
      Boolean v3 = list->get(-1);
      if(v3 != nullptr) {
      }
    }catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {get(int index)} case2]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {get(int index)}]");
    break;
  }

  //int insert(int index,Boolean val);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    list->insert(1,Boolean::New(false));
    if(!list->get(0)->sameAs(true)
    ||!list->get(1)->sameAs(false)
    ||!list->get(2)->sameAs(true)
    ||!list->get(3)->sameAs(true)) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,Boolean val)} case1]");
      break;
    }

    bool isException = false;
    try {
    int result = list->insert(50,Boolean::New(false));
      if(result != -1) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,Boolean val)} case2]");
      break;
    }

    isException = false;
    try {
      auto result = list->insert(-1,Boolean::New(false));
      if(result != -1) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,Boolean val)} case3]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insert(int index,Boolean val)}]");
    break;
  }

  //int insert(int index,bool val);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    list->insert(1,Boolean::New(false));
    if(!list->get(0)->sameAs(true)
    ||!list->get(1)->sameAs(false)
    ||!list->get(2)->sameAs(true)
    ||!list->get(3)->sameAs(true)) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,bool val)} case1]");
      break;
    }

    bool isException = false;
    try {
      int result = list->insert(50,Boolean::New(false));
      if(result != -1) {

      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,bool val)} case2]");
      break;
    }

    isException = false;
    try {
      auto result = list->insert(-1,Boolean::New(false));
      if(result != -1) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,bool val)} case3]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insert(int index,bool val)}]");
    break;
  }

  //int insert(int index,ArrayList<Boolean> list);
  while(1) {
    ArrayList<Boolean>list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(false));

    list->insert(1,list2);

    if(list->get(0)->toValue() != true
    ||list->get(1)->toValue() != false
    ||list->get(2)->toValue() != false
    ||list->get(3)->toValue() != false
    ||list->get(4)->toValue() != true
    ||list->get(5)->toValue() != true) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list)} case0]");
      break;
    }

    int size = list->size();
    bool isException = false;
    try {
      int result = list->insert(100,list2);
      if(result != -1 || size != list->size()) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list)} case1]");
      break;
    }

    size = list->size();
    isException = false;
    try {
      auto result = list->insert(-1,list2);
      if(result != -1 || size != list->size()) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list)} case2]");
      break;
    }

    ArrayList<Boolean>list3 = ArrayList<Boolean>::New();
    list3->add(Boolean::New(true));
    list3->add(Boolean::New(true));
    list3->add(Boolean::New(true));

    ArrayList<Boolean>list4 = ArrayList<Boolean>::New();
    list4->add(Boolean::New(false));
    list4->add(Boolean::New(false));
    list4->add(Boolean::New(false));

    list3->insert(0,list4);
    if(list3->get(0)->toValue() != false
    ||list3->get(1)->toValue() != false
    ||list3->get(2)->toValue() != false
    ||list3->get(3)->toValue() != true
    ||list3->get(4)->toValue() != true
    ||list3->get(5)->toValue() != true) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list)} case3]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list)}]");
    break;
  }

  //int insert(int index,ArrayList<Boolean> list,int length);
  while(1) {
    ArrayList<Boolean>list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(false));

    list->insert(1,list2,2);
    if(list->get(0)->toValue() != true
    ||list->get(1)->toValue() != false
    ||list->get(2)->toValue() != false
    ||list->get(3)->toValue() != true
    ||list->get(4)->toValue() != true) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case0]");
      break;
    }

    if(list->size() != 5) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case1]");
      break;
    }

    int size = list->size();
    bool isException = false;
    try {
      int result = list->insert(100,list2,5);
      if(result != -1 || size != list->size()) {
      }
    }catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case1]");
      break;
    }

    try {
      auto result = list->insert(-1,list2,100);
      if(result != -1 || size != list->size()) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case2]");
      break;
    }

    ArrayList<Boolean>list3 = ArrayList<Boolean>::New();
    list3->add(Boolean::New(true));
    list3->add(Boolean::New(true));
    list3->add(Boolean::New(true));

    ArrayList<Boolean>list4 = ArrayList<Boolean>::New();
    list4->add(Boolean::New(false));
    list4->add(Boolean::New(false));
    list4->add(Boolean::New(false));

    list3->insert(0,list4,2);
    if(list3->get(0)->toValue() != false
    ||list3->get(1)->toValue() != false
    ||list3->get(2)->toValue() != true
    ||list3->get(3)->toValue() != true
    ||list3->get(4)->toValue() != true) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case3]");
      break;
    }

    if(list3->size() != 5) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case4]");
      break;
    }

    ArrayList<Boolean>list5 = ArrayList<Boolean>::New();
    list5->add(Boolean::New(true));
    list5->add(Boolean::New(true));
    list5->add(Boolean::New(true));

    ArrayList<Boolean>list6 = ArrayList<Boolean>::New();
    list6->add(Boolean::New(false));
    list6->add(Boolean::New(false));
    list6->add(Boolean::New(false));

#if 0
    auto result = list5->insert(0,list6,100);

    if(list5->get(0)->toValue() != false
      ||list5->get(1)->toValue() != false
      ||list5->get(2)->toValue() != false
      ||list5->get(3)->toValue() != true
      ||list5->get(4)->toValue() != true
      ||list5->get(5)->toValue() != true) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case5]");
      break;
    }

    if(list5->size() != 6) {
      TEST_FAIL("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)} case6]");
      break;
    }
#endif

    TEST_OK("[ArrayList<Boolean> Test {insert(int index,ArrayList<Boolean> list,int length)}]");
    break;
  }

  //void insertFirst(Integer val);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    list->insertFirst(Boolean::New(false));
    if(list->get(0)->toValue() != false
       ||list->get(1)->toValue() != true
       ||list->get(2)->toValue() != true
       ||list->get(3)->toValue() != true) {
         TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(Boolean val)} case1]");
         break;
    }

    if(list->size() != 4) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(Boolean val)} case2]");
        break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->insertFirst(Boolean::New(false));
    if(list2->get(0)->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(Boolean val)} case3]");
      break;
    }

    if(list2->size() != 1) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(Boolean val)} case4]");
      break;
    }

    ArrayList<Boolean> list3 = ArrayList<Boolean>::New();
    Boolean nt;
    list3->insertFirst(nt);
    if(list3->size() == 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(Boolean val)} case5]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insertFirst(Boolean val)}]");
    break;
  }

  //void insertFirst(bool val);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    list->insertFirst(Boolean::New(false));
    if(list->get(0)->toValue() != false
       ||list->get(1)->toValue() != true
       ||list->get(2)->toValue() != true
       ||list->get(3)->toValue() != true) {
         TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(bool val)} case1]");
         break;
    }

    if(list->size() != 4) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(bool val)} case2]");
        break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->insertFirst(Boolean::New(true));
    if(list2->get(0)->toValue() != true) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(bool val)} case3]");
      break;
    }

    if(list2->size() != 1) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(bool val)} case4]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insertFirst(bool val)}]");
    break;
  }

  //void insertFirst(ArrayList<Boolean> list);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(false));
    list2->add(Boolean::New(false));
    list->insertFirst(list2);

    if(list->get(0)->toValue() != false
      ||list->get(1)->toValue() != false
      ||list->get(2)->toValue() != false
      ||list->get(3)->toValue() != true
      ||list->get(4)->toValue() != true
      ||list->get(5)->toValue() != true) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(ArrayList<Boolean> list)} case1]");
        break;
      }

    ArrayList<Boolean> list3 = ArrayList<Boolean>::New();
    list3->add(Boolean::New(false));
    list3->add(Boolean::New(false));

    ArrayList<Boolean> list4 = ArrayList<Boolean>::New();
    list4->insertFirst(list4);

    if(list3->get(0)->toValue() != false
      ||list3->get(1)->toValue() != false){
        TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(ArrayList<Boolean> list)} case2]");
        break;
      }

    if(list3->size() != 2) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(ArrayList<Boolean> list)} case3]");
      break;
    }

/*
    ArrayList<Boolean> list5;
    list3->insertFirst(list5);
    if(list3->size() != 2) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertFirst(ArrayList<Boolean> list)} case4]");
      break;
    }
*/
    TEST_OK("[ArrayList<Boolean> Test {insertFirst(ArrayList<Boolean> list)}]");
    break;
  }

  //void insertLast(Boolean v);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    list->insertLast(Boolean::New(false));
    if(list->get(0)->toValue() != true
      ||list->get(1)->toValue() != true
      ||list->get(2)->toValue() != true
      ||list->get(3)->toValue() != false) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(Boolean v)} case1]");
        break;
    }

    if(list->size() != 4) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertLast(Boolean v)} case2]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(true));
    list2->add(Boolean::New(true));
    list2->add(Boolean::New(true));
    Boolean t2;
    list2->insertLast(t2);

    if(list2->get(0)->toValue() != true
      ||list2->get(1)->toValue() != true
      ||list2->get(2)->toValue() != true) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(Boolean v)} case3]");
        break;
    }

    if(list2->size() != 4) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertLast(Boolean v)} case4]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insertLast(Boolean v)} case5]");
    break;
  }

  //void insertLast(int v);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    list->insertLast(Boolean::New(false));
    if(list->get(0)->toValue() != true
      ||list->get(1)->toValue() != true
      ||list->get(2)->toValue() != true
      ||list->get(3)->toValue() != false) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(bool v)} case1]");
        break;
    }

    if(list->size() != 4) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertLast(bool v)} case2]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->insertLast(Boolean::New(false));

    if(list2->size() != 1) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertLast(bool v)} case3]");
      break;
    }

    if(list2->get(0)->toValue() != false) {
      TEST_FAIL("[ArrayList<Boolean> Test {insertLast(bool v)} case4]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {insertLast(bool v)} case5]");
    break;
  }

  //insertLast(ArrayList<Boolean> list);
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    list2->add(Boolean::New(true));
    list2->add(Boolean::New(true));
    list2->add(Boolean::New(true));

    list->insertLast(list2);
    if(list->get(0)->toValue() != false
      ||list->get(1)->toValue() != false
      ||list->get(2)->toValue() != false
      ||list->get(3)->toValue() != true
      ||list->get(4)->toValue() != true
      ||list->get(5)->toValue() != true) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(ArrayList<Boolean> v)} case1]");
        break;
    }

    if(list->size() != 6) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(ArrayList<Boolean> v)} case2]");
        break;
    }

    ArrayList<Boolean> list3 = ArrayList<Boolean>::New();
    list3->add(Boolean::New(false));
    list3->add(Boolean::New(false));
    list3->add(Boolean::New(false));

/*
    ArrayList<Boolean> list4;
    list3->insertLast(list4);
    if(list3->get(0)->toValue() != false
      ||list3->get(1)->toValue() != false
      ||list3->get(2)->toValue() != false) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(ArrayList<Boolean> v)} case3]");
        break;
    }

    if(list3->size() != 3) {
        TEST_FAIL("[ArrayList<Boolean> Test {insertLast(ArrayList<Boolean> v)} case4]");
        break;
    }
*/
    TEST_OK("[ArrayList<Boolean> Test {insertLast(ArrayList<Boolean> v)} case5]");
    break;
  }

  //int size();
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    if(list->size() != 3) {
      TEST_FAIL("[ArrayList<Boolean> Test {size()} case1]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    if(list2->size() != 0) {
      TEST_FAIL("[ArrayList<Boolean> Test {size()} case2]");
      break;
    }

    TEST_OK("[ArrayList<Boolean> Test {size()} case3]");
    break;
  }

  //ListIterator<Boolean> getValue;
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));
    list->add(Boolean::New(true));

    auto iterator = list->getIterator();
    int index = 1;
    while(iterator->hasValue() && index != list->size()) {
      Boolean v = iterator->getValue();
      if(v->toValue() != true) {
        TEST_FAIL("[ListIterator<Boolean> Test {getValue()} case1]");
        break;
      }

      iterator->next();
      index++;
    }

    ArrayList<Boolean> list1 = ArrayList<Boolean>::New();
    auto iterator1 = list1->getIterator();
    bool isException = false;
    try {
      Boolean v = iterator1->getValue();
      if(v != nullptr) {
      }
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("[ListIterator<Boolean> Test {getValue()} case2]");
      break;
    }

    TEST_OK("[ListIterator<Boolean> Test {getValue()} case3]");
    break;
  }

  //ListIterator<Integer> hasValue();
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    auto iterator = list->getIterator();
    if(!iterator->hasValue()) {
      TEST_FAIL("[ListIterator<Boolean> Test {hasValue()} case1]");
      break;
    }

    iterator->next();
    iterator->next();
    iterator->next();

    if(iterator->hasValue()) {
      TEST_FAIL("[ListIterator<Boolean> Test {hasValue()} case2]");
      break;
    }

    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    auto iterator2 = list2->getIterator();
    if(iterator2->hasValue()) {
      TEST_FAIL("[ListIterator<Boolean> Test {hasValue()} case3]");
      break;
    }

    TEST_OK("[ListIterator<Boolean> Test {hasValue()} case4]");
    break;
  }

  // ListIterator<Integer> next();
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    list->add(Boolean::New(false));
    auto iterator = list->getIterator();

    iterator->next();
    iterator->next();
    if(iterator->next()) {
      TEST_FAIL("[ListIterator<Boolean> Test {next()} case1]");
      break;
    }

/*
    ArrayList<Boolean> list2 = ArrayList<Boolean>::New();
    auto iterator2 = list2->getIterator();
    if(iterator2->next()) {
      TEST_FAIL("[ListIterator<Boolean> Test {next()} case2]");
      break;
    }
*/
    TEST_OK("[ListIterator<Boolean> Test {next()} case3]");
    break;
  }

  //--[_ListIterator<Boolean> Test {remove()} Start]
  while(1) {
    ArrayList<Boolean> list = ArrayList<Boolean>::New();
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));
    list->add(Boolean::New(false));
    list->add(Boolean::New(true));

    auto iterator = list->getIterator();
    while(iterator->hasValue()) {
      if(iterator->getValue()->toValue()) {
        iterator->remove();
      }else {
        iterator->next();
      }
    }

    if(list->size() != 2) {
        TEST_FAIL("[ListIterator<Boolean> Test {remove()} case0]");
        break;
    }

    if(list->get(0)->toValue()
      ||list->get(1)->toValue()) {
        TEST_FAIL("[ListIterator<Boolean> Test {remove()} case2]");
        break;
    }

    TEST_OK("[ListIterator<Boolean> Test {remove()} case3]");
    break;
  }
}
