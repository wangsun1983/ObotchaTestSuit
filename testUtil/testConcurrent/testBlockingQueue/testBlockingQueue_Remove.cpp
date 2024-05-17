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
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        list->remove(String::New("b"));
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
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        if(list->remove(String::New("a"))!= -1) {
          TEST_FAIL("BlockingQueue remove test4");
          break;
        }

        break;
    }
    
    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(1);
        list->putFirst(String::New("a"));
        Thread t1 = Thread::New([&]{
            usleep(100*1000);
            TimeWatcher watcher = TimeWatcher::New();
            watcher->start();
            list->putFirst(String::New("b"));
            auto ret = watcher->stop();
            if(ret < 95 || ret > 105) {
                TEST_FAIL("BlockingQueue remove test5,ret is %d",ret);
            }
        });
        
        Thread t2 = Thread::New([&]{
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
