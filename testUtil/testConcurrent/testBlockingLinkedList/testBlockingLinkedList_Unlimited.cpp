#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListUnlimited() {

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>();
        for(int i = 0;i<1024;i++) {
          list->put(createString(i));
        }

        if(list->size() != 1024) {
          TEST_FAIL("BlockingLinkedList unlimited capacity test1 \n");
        }

        list->clear();
        if(list->size() != 0) {
          TEST_FAIL("BlockingLinkedList unlimited capacity test2 \n");
        }

        break;
    }

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        Thread t = createThread([&list]{
          usleep(100*1000);
          list->put(createString("a"));
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        String str = list->take();
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingLinkedList unlimited capacity,value is %ld \n",time2 - time1);
          break;
        }

        if(str == nullptr || !str->sameAs("a")) {
          TEST_FAIL("BlockingLinkedList unlimited capacity test3 \n");
          break;
        }
        break;
    }


    TEST_OK("BlockingLinkedList unlimited test100");
}
