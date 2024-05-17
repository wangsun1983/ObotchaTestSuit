#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListClear() {    
    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);
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
          TEST_FAIL("BlockingLinkedList clear test1");
          break;
        }
        if(list->size() != 1) {
          TEST_FAIL("BlockingLinkedList clear test2");
          break;
        }
        break;
    }
    
    while(1) {
        BlockingLinkedList<String> list = BlockingLinkedList<String>::New(3);

        Thread t = Thread::New([&list]{
          usleep(100*1000);
          list->clear();
        });
        t->start();
        long time1 = st(System)::CurrentTimeMillis();
        list->take(200);
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 200 || (time2 - time1) > 205) {
          TEST_FAIL("BlockingLinkedList clear test3,cost is %d",time2 - time1);
          break;
        }

        if(list->size() != 0) {
          TEST_FAIL("BlockingLinkedList clear test4,size is %d",list->size());
          break;
        }
        break;
    }

    TEST_OK("BlockingLinkedList clear test100");
}
