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
#include "ByteArrayTransformer.hpp"

using namespace obotcha;

struct MyData {
int data1;
long data2;
int data3;
};

void testByteArrayStruct() {
  while(1) {
    ByteArray array = st(ByteArrayTransformer)::Alloc<MyData>();
    auto p = st(ByteArrayTransformer)::Convert<MyData>(array);
	p->data1 = 1;
	p->data2 = 2;
	p->data3 = 100;
		
	MyData *p2 = st(ByteArrayTransformer)::Convert<MyData>(array);
	if(p2->data1 != 1 || p2->data2 != 2 || p2->data3 != 100) {
       TEST_FAIL("ByteArray test Struct test 1");
    }
    break;
  }

  while(1) {
    MyData p;
    p.data1 = 1;
    p.data2 = 2;
    p.data3 = 100;
    ByteArray array = st(ByteArrayTransformer)::Convert(&p);

    MyData *p2 = st(ByteArrayTransformer)::Convert<MyData>(array);
    if(p2->data1 != 1 || p2->data2 != 2 || p2->data3 != 100) {
      TEST_FAIL("ByteArray test Struct test 2");
    }
    break;
  }
  
  while(1) {
    MyData p;
    p.data1 = 1;
    p.data2 = 2;
    p.data3 = 100;
    ByteArray array = st(ByteArrayTransformer)::Duplicate(&p);
	p.data1 = 100;
	p.data2 = 200;
	p.data3 = 300;
	
    MyData *p2 = st(ByteArrayTransformer)::Convert<MyData>(array);
    if(p2->data1 != 1 || p2->data2 != 2 || p2->data3 != 100) {
      TEST_FAIL("ByteArray test Struct test 3");
    }
    break;
  }
  
  while(1) {
    MyData p;
    p.data1 = 1;
    p.data2 = 2;
    p.data3 = 100;
    ByteArray array = st(ByteArrayTransformer)::Convert(&p);
  	p.data1 = 100;
  	p.data2 = 200;
  	p.data3 = 300;
  	
    MyData *p2 = st(ByteArrayTransformer)::Convert<MyData>(array);
    if(p2->data1 != 100 || p2->data2 != 200 || p2->data3 != 300) {
      TEST_FAIL("ByteArray test Struct test 4");
    }
    break;
  }

  TEST_OK("ByteArray test Struct test");
}
