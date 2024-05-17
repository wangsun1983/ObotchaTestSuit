#include <stdio.h>
#include <unistd.h>

#include "Stack.hpp"
#include "TestLog.hpp"
#include "String.hpp"
using namespace obotcha;

void testTop() {
  while(1) {
    Stack<String> s = Stack<String>::New();
    s->push(String::New("a"));
    s->push(String::New("b"));
    s->push(String::New("c"));

    auto a1 = s->top();
    if(!a1->equals(String::New("c"))) {
      TEST_FAIL("testStack top test1,a1 is %s",a1->toChars());
      break;
    }

    s->pop();
    auto a2 = s->top();
    if(!a2->equals(String::New("b"))) {
      TEST_FAIL("testStack top test2,a2 is %s",a2->toChars());
      break;
    }

    s->pop();
    auto a3 = s->top();
    if(!a3->equals(String::New("a"))) {
      TEST_FAIL("testStack top test3,a3 is %s",a3->toChars());
      break;
    }
    break;
  }

  TEST_OK("testStack top test100");
}
