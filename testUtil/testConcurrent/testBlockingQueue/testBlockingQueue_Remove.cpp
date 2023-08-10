#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testBlockingQueueRemove() {

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        list->remove(createString("b"));
        if(list->size() != 2) {
          TEST_FAIL("BlockingQueue remove test1");
          break;
        }

        ArrayList<String> ll = list->toArray();
        if(ll->size() != 2) {
          TEST_FAIL("BlockingQueue remove test2");
          break;
        }

        if(!ll->get(0)->sameAs("a") || !ll->get(1)->sameAs("c")) {
          TEST_FAIL("BlockingQueue remove test3");
          break;
        }

        if(list->remove("f") != -1) {
          TEST_FAIL("BlockingQueue remove test3_1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingQueue remove test3_2");
          break;
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(3);
        if(list->remove(createString("a"))!= -1) {
          TEST_FAIL("BlockingQueue remove test4");
          break;
        }

        break;
    }
    
    while(1) {
        BlockingQueue<String> list = createBlockingQueue<String>(1);
        list->putFirst(createString("a"));
        Thread t1 = createThread([&]{
            usleep(100*1000);
            TimeWatcher watcher = createTimeWatcher();
            watcher->start();
            list->putFirst(createString("b"));
            auto ret = watcher->stop();
            if(ret < 95 || ret > 105) {
                TEST_FAIL("BlockingQueue remove test5,ret is %d",ret);
            }
        });
        
        Thread t2 = createThread([&]{
            usleep(200*1000);
            list->destroy();
        });
        
        t1->start();
        t2->start();
        
        t1->join();
        t2->join();
        break;
    }


    TEST_OK("BlockingQueue remove test100");
}
