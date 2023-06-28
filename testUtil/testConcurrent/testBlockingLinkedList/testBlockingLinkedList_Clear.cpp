#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListClear() {

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        Thread t = createThread([&list]{
          usleep(100*1000);
          list->clear();
        });
        t->start();
        long time1 = st(System)::currentTimeMillis();
        list->put(createString("d"));
        long time2 = st(System)::currentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingLinkedList clear test1");
          break;
        }

        if(list->size() != 1) {
          TEST_FAIL("BlockingLinkedList clear test2");
          break;
        }

        break;
    }
    
    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);

        Thread t = createThread([&list]{
          usleep(100*1000);
          list->clear();
        });
        t->start();
        long time1 = st(System)::currentTimeMillis();
        list->take();
        long time2 = st(System)::currentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingLinkedList clear test3");
          break;
        }

        if(list->size() != 1) {
          TEST_FAIL("BlockingLinkedList clear test4");
          break;
        }

        break;
    }

    TEST_OK("BlockingLinkedList clear test100");
}
