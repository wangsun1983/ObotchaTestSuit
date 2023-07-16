#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListDestroy() {
    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        Thread t = createThread([&list]{
          usleep(100*1000);
          list->destroy();
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        list->put(createString("d"));
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingLinkedList destroy test1,value is %ld \n",time2 - time1);
          break;
        }

        break;
    }

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        Thread t = createThread([&list]{
          usleep(100*1000);
          list->destroy();
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        String str = list->take();
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingLinkedList destroy test2,value is %ld \n",time2 - time1);
          break;
        }

        if(str != nullptr) {
          TEST_FAIL("BlockingLinkedList destroy test3 \n");
          break;
        }
        break;
    }

    TEST_OK("BlockingLinkedList destroy test100");
}
