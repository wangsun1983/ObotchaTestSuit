#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testBlockingLinkedListRemoveAtOne() {
    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(1);
        Thread t1 = createThread([&]{
            list->put(createString("a"));
            usleep(1000*200);
            list->removeAt(0);
        });
        
        Thread t2 = createThread([&]{
            usleep(1000*100);
            TimeWatcher w = createTimeWatcher();
            w->start();
            list->put(createString("b"));
            auto cost = w->stop();
            if(cost < 95 || cost > 105) {
                TEST_FAIL("BlockingLinkedList removeAt One test1,cost is %d",cost);
            }
            
        });
        t1->start();
        t2->start();
        
        t1->join();
        t2->join();
        break;
    }

    TEST_OK("BlockingLinkedList RemoveAt One test100");
}
