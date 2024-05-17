#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueueDestroy() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        Thread t = Thread::New([&list]{
          usleep(100*1000);
          list->destroy();
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        list->put(String::New("d"));
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingQueue destroy test1");
          break;
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        Thread t = Thread::New([&list]{
          usleep(100*1000);
          list->destroy();
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        String str = list->take();
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingQueue destroy test2");
          break;
        }

        if(str != nullptr) {
          TEST_FAIL("BlockingQueue destroy test3");
          break;
        }
        break;
    }


    TEST_OK("BlockingQueue destroy test100");
}
