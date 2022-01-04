#include <stdio.h>
#include <unistd.h>
#include <vector>
//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint8.hpp"
#include "StrongPointer.hpp"
#include "Uint8.hpp"
#include "List.hpp"
#include "TestLog.hpp"

using namespace std;
using namespace obotcha;

DECLARE_CLASS(MyData) {
public:
  int i;
  int j;
};

void listobjecttest() {
  //construct1
  while(1) {
    List<MyData> mylist1 = createList<MyData>(4);
    if(mylist1->size() != 4) {
      TEST_FAIL("List Object construct test1");
      break;
    }

    MyData v1 = mylist1[0];
    if(v1 != nullptr) {
      TEST_FAIL("List Object construct test2");
      break;
    }

    TEST_OK("List Object construct test3");
    break;
  }

  //construct2
  while(1) {
    MyData vlist[5];
    for(int i = 0;i < 5;i++) {
      MyData v = createMyData();
      v->i = i;
      v->j = i;
      vlist[i] = v;
    }

    List<MyData> list1 = createList<MyData>(vlist,5);
    if(list1->size() != 5) {
      TEST_FAIL("List Object construct test4");
      break;
    }

    for(int i = 0;i<5;i++) {
      MyData v = vlist[i];
      if(v->i != i ||v->j != i) {
        TEST_FAIL("List Object construct test5");
        break;
      }
    }

    for(int i = 0;i<5;i++) {
      MyData v = vlist[i];
      v->i = i*100;
      v->j = i*100;
    }

    for(int i = 0;i<5;i++) {
      MyData v = vlist[i];
      if(v->i != i*100 ||v->j != i*100) {
        TEST_FAIL("List Object construct test6");
        break;
      }
    }

    TEST_OK("List Object construct test7");
    break;
  }

  //nullptr set
  while(1) {
    List<MyData> list1 = createList<MyData>(2);
    MyData data1 = createMyData();
    data1->i = 1;
    data1->j = 1;
    list1[0] = data1;
    list1[1] = data1;

    list1[0] = nullptr;
    MyData data1_1 = list1[0];
    if(data1_1 != nullptr) {
      TEST_FAIL("List Object set null test1");
      break;
    }

    TEST_OK("List Object set null test2");
    break;
  }
}
