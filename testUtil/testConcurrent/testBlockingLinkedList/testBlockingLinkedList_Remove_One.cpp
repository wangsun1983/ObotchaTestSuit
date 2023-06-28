#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testBlockingLinkedListRemoveOne() {

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(1);
        list->put(createString("a"));
        
        Thread t1 = createThread([&]{
            usleep(100*1000);
            TimeWatcher watcher = createTimeWatcher();
            watcher->start();
            list->put(createString("b"));
            auto ret = watcher->stop();
            if(ret < 95 || ret > 105) {
                TEST_FAIL("BlockingLinkedList remove one test1,ret is %ld",ret);
            }
        });
        
        Thread t2 = createThread([&]{
            usleep(200*1000);
            list->remove(createString("a"));
        });
        
        t1->start();
        t2->start();
        
        t1->join();
        t2->join();
        break;
    }


    TEST_OK("BlockingLinkedList remove one test100");
}
