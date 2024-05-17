#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueClear() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        Thread t = Thread::New([&list]{
          usleep(100*1000);
          list->clear();
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        list->put(String::New("d"));
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingQueue clear test1");
          break;
        }

        if(list->size() != 1) {
          TEST_FAIL("BlockingQueue clear test2");
          break;
        }

        break;
    }

    TEST_OK("BlockingQueue destroy test100");
}
