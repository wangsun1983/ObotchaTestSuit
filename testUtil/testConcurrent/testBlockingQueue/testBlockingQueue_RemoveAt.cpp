#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testBlockingQueueRemoveAt() {

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        list->put(String::New("b"));
        list->put(String::New("c"));

        String v = list->removeAt(1);
        if(v == nullptr || !v->sameAs("b")) {
          TEST_FAIL("BlockingQueue removeAt test1");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("BlockingQueue removeAt test2");
          break;
        }
        break;
    }

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        bool isException = false;
        try {
          String v = list->removeAt(1);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingQueue removeAt test3");
          break;
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        bool isException = false;
        try {
          String v = list->removeAt(0);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingQueue removeAt test4");
          break;
        }

        break;
    }

    while(1) {
        BlockingQueue<String> list = BlockingQueue<String>::New(3);
        list->put(String::New("a"));
        bool isException = false;
        try {
          String v = list->removeAt(2);
        } catch(...) {
          isException = true;
        }

        if(!isException) {
          TEST_FAIL("BlockingQueue removeAt test5");
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
                TEST_FAIL("BlockingQueue removeAt test6,ret is %d",ret);
            }
        });
        
        Thread t2 = Thread::New([&]{
            usleep(200*1000);
            list->removeAt(0);
        });
        
        t1->start();
        t2->start();
        
        t1->join();
        t2->join();
        break;
    }

    TEST_OK("BlockingQueue removeAt test100");
}
