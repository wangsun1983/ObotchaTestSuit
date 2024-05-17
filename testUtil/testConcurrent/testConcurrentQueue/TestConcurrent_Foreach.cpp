#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testConcurrentQueue_Foreach() {
    while(1) {
        ConcurrentQueue<int> list = ConcurrentQueue<int>::New();
        list->putFirst(1);
        list->putFirst(2);
        list->putFirst(3);
        list->putFirst(4);
        list->putFirst(5);
        int sum = 0;
        /*
        list->foreach([&sum](int v) {
            sum += v;
            return Global::Continue;
        },[&list](){
          list->clear();
        });*/
        ForEveryOne(v,list) {
            sum += v;
        }
        list->clear();
        
        if(sum != 15) {
          TEST_FAIL("ConcurrentQueue<int> Foreach test1");
        }
        if(list->size() != 0) {
          TEST_FAIL("ConcurrentQueue<int> Foreach test2");
        }
        break;
    }
    TEST_OK("ConcurrentQueue Foreach test100");
}
