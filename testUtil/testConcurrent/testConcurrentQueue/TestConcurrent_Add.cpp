#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testConcurrentQueue_Add() {
    while(1) {
      ConcurrentQueue<String> list = createConcurrentQueue<String>();
      for(int i = 0;i<1024;i++) {
        list->add(createString(i));
      }

      for(int j = 0;j<1024;j++) {
        String v = list->get(j);
        if(v->toBasicInt() != j) {
          TEST_FAIL("ConcurrentQueue add test1");
        }
      }
      break;
    }

    while(1) {
      ConcurrentQueue<int> list = createConcurrentQueue<int>();
      for(int i = 0;i<1024;i++) {
        list->add(i);
      }

      for(int j = 0;j<1024;j++) {
        int v = list->get(j);
        if(v != j) {
          TEST_FAIL("ConcurrentQueue add test2");
        }
      }
      break;
    }

    TEST_OK("ConcurrentQueue add test100");
}
