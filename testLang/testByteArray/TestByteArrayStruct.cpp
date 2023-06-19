#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

struct MyData {
int data1;
long data2;
int data3;
};

void testByteArrayStruct() {
  while(1) {
    ByteArray array = createByteArray(sizeof(MyData));
    MyData *p = array->get<MyData>();
    p->data1 = 1;
    p->data2 = 2;
    p->data3 = 100;

    MyData *p2 = array->get<MyData>();
    if(p2->data1 != 1 || p2->data2 != 2 || p2->data3 != 100) {
      TEST_FAIL("ByteArray test Struct test 1");
    }
    break;
  }

  while(1) {
    ByteArray array = createByteArray(1024);
    MyData p;
    p.data1 = 1;
    p.data2 = 2;
    p.data3 = 100;
    array->apply(&p);

    MyData *p2 = array->get<MyData>();
    if(p2->data1 != 1 || p2->data2 != 2 || p2->data3 != 100) {
      TEST_FAIL("ByteArray test Struct test 2");
    }
    break;
  }

  while(1) {
    ByteArray array = st(ByteArray)::Alloc<MyData>();
    MyData *p = array->get<MyData>();
    p->data1 = 1;
    p->data2 = 2;
    p->data3 = 100;

    MyData *p2 = array->get<MyData>();
    if(p2->data1 != 1 || p2->data2 != 2 || p2->data3 != 100) {
      TEST_FAIL("ByteArray test Struct test 3");
    }
    break;
  }

  TEST_OK("ByteArray test Struct test");
}
