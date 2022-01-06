#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingQueuePutLast() {

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->putLast(createString("a"));
        list->putLast(createString("b"));
        list->putLast(createString("c"));

        Thread t = createThread([&list]{
          usleep(100*1000);
          list->takeLast();
        });
        t->start();

        long time1 = st(System)::currentTimeMillis();
        list->putLast("d");
        long time2 = st(System)::currentTimeMillis();

        if((time2 - time1) < 100 || (time2 - time1) > 105) {
          TEST_FAIL("BlockingQueue PutLast test1");
          break;
        }

        ArrayList<String> result = createArrayList<String>();
        result->add(createString("a"));
        result->add(createString("b"));
        result->add(createString("d"));
        auto iterator = result->getIterator();
        while(iterator->hasValue()) {
          auto v = iterator->getValue();
          auto v2 = list->takeFirst();
          if(!v->equals(v2)) {
            TEST_FAIL("BlockingQueue PutLast test2");
            break;
          }
          iterator->next();
        }

        break;
    }


    TEST_OK("BlockingQueue PutLast test100");
}
