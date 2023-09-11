#include <stdio.h>
#include <unistd.h>

#include "Stack.hpp"
#include "TestLog.hpp"
#include "String.hpp"
using namespace obotcha;

DECLARE_CLASS(TestSizeData) {
public:
  _TestSizeData(int value) {
    v = value;
  }

  int v;
};

void testStackSize() {
  while(1) {
    Stack<Integer> stack = createStack<Integer>();
    stack->push(createInteger(1));
    stack->push(createInteger(2));

    if(stack->size() != 2) {
      TEST_FAIL("testStack size test1");
      break;
    }

    int v1 = stack->pop()->toValue();
    int v2 = stack->pop()->toValue();

    if(v1 != 2 || v2 != 1) {
      TEST_FAIL("testStack size test2");
      break;
    }
	
    auto v3 = stack->pop();
    if(v3 != nullptr) {
      TEST_FAIL("testStack size test3");
      break;
    }
    break;
  }

  while(1) {
    Stack<TestSizeData> stack = createStack<TestSizeData>();
    stack->push(createTestSizeData(1));
    stack->push(createTestSizeData(2));

    if(stack->size() != 2) {
      TEST_FAIL("testStack size test4");
      break;
    }

    auto v1 = stack->pop();
    auto v2 = stack->pop();

    if(v1->v != 2 || v2->v != 1) {
      TEST_FAIL("testStack size test5");
      break;
    }
    auto v3 = stack->pop();

    if(v3 != nullptr) {
      TEST_FAIL("testStack size test6");
      break;
    }
    break;
  }
  TEST_OK("testStack size test100");
}
