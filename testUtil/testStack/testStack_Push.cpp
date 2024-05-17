#include <stdio.h>
#include <unistd.h>

#include "Stack.hpp"
#include "TestLog.hpp"
#include "String.hpp"
using namespace obotcha;

DECLARE_CLASS(TestPushData) {
public:
  _TestPushData(int value) {
    v = value;
  }

  int v;
};

void testStackPush() {
  while(1) {
    Stack<Integer> ss = Stack<Integer>::New();

    for(int i = 0;i<1024*32;i++) {
      ss->push(Integer::New(i));
    }

    if(ss->size() != 1024*32) {
      TEST_FAIL("testStack push test1");
      break;
    }

    for(int i = 1024*32 - 1;i >= 0;i--) {
      if(ss->pop() != Integer::New(i)) {
        TEST_FAIL("testStack push test2");
        break;
      }
    }
    break;
  }

  while(1) {
    Stack<TestPushData> ss = Stack<TestPushData>::New();

    for(int i = 0;i<1024*32;i++) {
      ss->push(TestPushData::New(i));
    }

    if(ss->size() != 1024*32) {
      TEST_FAIL("testStack push test3");
      break;
    }

    for(int i = 1024*32 - 1;i >= 0;i--) {
      if(ss->pop()->v != i) {
        TEST_FAIL("testStack push test4");
        break;
      }
    }
    break;
  }
  TEST_OK("testStack push test100");
}
