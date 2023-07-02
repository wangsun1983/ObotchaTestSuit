#include <stdio.h>
#include <unistd.h>

#include "Stack.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testStackPop() {
  while(1) {
    Stack<String> ss = createStack<String>();
    ss->push(createString("a"));
    ss->push(createString("b"));
    ss->push(createString("c"));
    
    auto v_c = ss->pop();
    auto v_b = ss->pop();
    auto v_a = ss->pop();
    
    if(ss->size() != 0) {
        TEST_FAIL("testStack pop case1");
    }
    
    if(!v_a->equals("a") || !v_b->equals("b") || !v_c->equals("c")) {
        TEST_FAIL("testStack pop case2");
    }
    break;
  }
  
  while(1) {
    Stack<String> ss = createStack<String>();
    for(int i = 0;i < 32*1024;i++) {
        ss->push(createString(i));
    }
    
    for(int j = 32*1024-1;j >= 0;j--) {
        auto v = ss->pop();
        if(!v->equals(createString(j))) {
            TEST_FAIL("testStack pop case3,v is %s,j is %d",v->toChars(),j);
            break;
        }
    }
    break;
  }
  TEST_OK("testStack pop test100");
}
