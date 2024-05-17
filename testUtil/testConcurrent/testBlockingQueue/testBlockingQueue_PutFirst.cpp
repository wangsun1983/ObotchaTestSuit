#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueuePutFirst() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        Thread t = Thread::New([&list]{
          usleep(100*1000);
          list->takeLast();
        });
        t->start();

        long time1 = st(System)::CurrentTimeMillis();
        list->putFirst("d");
        long time2 = st(System)::CurrentTimeMillis();

        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingQueue PutFirst test1");
          break;
        }

        ArrayList<String> result = ArrayList<String>::New();
        result->add(String::New("d"));
        result->add(String::New("a"));
        result->add(String::New("b"));
        auto iterator = result->getIterator();
        while(iterator->hasValue()) {
          auto v = iterator->getValue();
          auto v2 = list->takeFirst();
          if(!v->equals(v2)) {
            TEST_FAIL("BlockingQueue PutFirst test2");
            break;
          }
          iterator->next();
        }

        break;
    }


    TEST_OK("BlockingQueue PutFirst test100");
}
