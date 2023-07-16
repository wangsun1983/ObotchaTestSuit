#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueUnlimited() {

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>();
        for(int i = 0;i<1024;i++) {
          list->put(createString(i));
        }

        if(list->size() != 1024) {
          TEST_FAIL("BlockingQueue unlimited capacity test1");
        }

        list->clear();
        if(list->size() != 0) {
          TEST_FAIL("BlockingQueue unlimited capacity test2");
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        Thread t = createThread([&list]{
          usleep(100*1000);
          list->put(createString("a"));
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        String str = list->take();
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingQueue unlimited capacity");
          break;
        }

        if(str == nullptr || !str->equals("a")) {
          TEST_FAIL("BlockingQueue unlimited capacity test3");
          break;
        }
        break;
    }


    TEST_OK("BlockingQueue destroy test100");
}
