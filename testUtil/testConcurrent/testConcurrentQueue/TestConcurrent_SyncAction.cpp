#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentQueue.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

void testConcurrentQueue_SyncAction() {

    while(1) {
        ConcurrentQueue<int> list = createConcurrentQueue<int>();
        list->putFirst(1);
        list->putFirst(2);
        list->putFirst(3);
        list->putFirst(4);
        list->putFirst(5);
        Thread t = createThread([&list]{
            list->syncReadAction([&list] {
                if(list->size() != 5) {
                    TEST_FAIL("ConcurrentQueue SyncAction case1");
                }
                sleep(2);
            });
        });

        Thread t2 = createThread([&list]{
            long start = st(System)::currentTimeMillis();

            list->syncWriteAction([&list,&start] {
                if(list->size() != 5) {
                    TEST_FAIL("ConcurrentQueue SyncAction case2");
                }

                long interval = st(System)::currentTimeMillis() - start;
                //printf("interval is %ld \n",interval);
                if(interval >2000 || interval < 1900) {
                    TEST_FAIL("ConcurrentQueue SyncAction case3");
                }
            });

            TEST_OK("ConcurrentQueue SyncAction case4");
        });

        t->start();
        usleep(1000);
        t2->start();

        t->join();
        t2->join();
        break;
    }


    while(1) {
        ConcurrentQueue<int> list = createConcurrentQueue<int>();
        list->putFirst(1);
        list->putFirst(2);
        list->putFirst(3);
        list->putFirst(4);
        list->putFirst(5);
        
        Thread t = createThread([&list]{
            list->syncWriteAction([&list] {
                if(list->size() != 5) {
                    TEST_FAIL("ConcurrentQueue SyncAction case5");
                }
                sleep(2);
            });
        });

        Thread t2 = createThread([&list]{
            long start = st(System)::currentTimeMillis();
            list->syncReadAction([&list,&start] {
                if(list->size() != 5) {
                    TEST_FAIL("ConcurrentQueue SyncAction case6");
                }

                long interval = st(System)::currentTimeMillis() - start;
                if(interval >2000 || interval < 1900) {
                    TEST_FAIL("ConcurrentQueue SyncAction case7");
                }
            });

            TEST_OK("ConcurrentQueue SyncAction case8");
        });

        t->start();
        usleep(1000*50);
        t2->start();

        t->join();
        t2->join();
        break;
    }

    while(1) {
        ConcurrentQueue<int> list = createConcurrentQueue<int>();
        list->putFirst(1);
        list->putFirst(2);
        list->putFirst(3);
        list->putFirst(4);
        list->putFirst(5);

        int sum = 0;
        list->syncWriteAction([&list,&sum] {
            list->foreach([&list,&sum](int v) {
                int sum2 = 0;

                list->foreach([&list,&sum2](int v2) {
                    sum2 += v2;
                    return Global::Continue;
                },[&list]{
                    list->clear();
                });
                if(sum2 != 15) {
                    TEST_FAIL("ConcurrentQueue SyncAction test9");
                }
                sum += v;
                return Global::Continue;
            });
        });
        if(sum != 5) {
            TEST_FAIL("ConcurrentQueue SyncAction test10,sum is %d",sum);
        }
        break;
    }

    while(1) {
        ConcurrentQueue<int> list = createConcurrentQueue<int>();
        list->putFirst(1);
        list->putFirst(2);
        list->putFirst(3);
        list->putFirst(4);
        list->putFirst(5);

        int sum = 0;
        list->syncReadAction([&list,&sum] {
            list->foreach([&list,&sum](int v) {
                int sum2 = 0;

                list->foreach([&list,&sum2](int v2) {
                    sum2 += v2;
                    return Global::Continue;
                },[&list]{
                    list->clear();
                });
                if(sum2 != 15) {
                    TEST_FAIL("ConcurrentQueue SyncAction test11");
                }
                sum += v;
                return Global::Continue;
            });
        });
        if(sum != 5) {
            TEST_FAIL("ConcurrentQueue SyncAction test12,sum is %d",sum);
        }
        break;
    }

    TEST_OK("ConcurrentQueue SyncAction test100");
}