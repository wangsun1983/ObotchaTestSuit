#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testBlockingLinkedListForeach() {

    while(1) {
        BlockingLinkedList<int> list = createBlockingLinkedList<int>(5);
        list->putFirst(1);
        list->putFirst(2);
        list->putFirst(3);
        list->putFirst(4);
        list->putFirst(5);
        int sum = 0;
        ForEveryOne(v,list) {
          sum += v;
        }
        //list->foreach([&sum](int v) {
        //    sum += v;
        //    return Global::Continue;
        //});

        if(sum != 15) {
          TEST_FAIL("BlockingLinkedList<int> Foreach test1");
        }

        break;
    }

    TEST_OK("BlockingLinkedList<int> Foreach test100");

}
