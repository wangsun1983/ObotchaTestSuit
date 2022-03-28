#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ThreadPoolExecutor.hpp"
#include "Integer.hpp"
#include "ExecutorBuilder.hpp"
#include "Future.hpp"
#include "System.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testThreadLambda() {
    ThreadPoolExecutor t = createExecutorBuilder()->newThreadPool();

    while(1) {
        int value = 100;
        t->submit([&value]() {
            if(value == 100) {
                value = 123;
            }
        });

        sleep(1);
        if(value != 123) {
            TEST_FAIL("[testThreadLambda value case1]");
            break;
        }
        break;
    }

    while(1) {
        int value = 100;
        t->submit([&value](int v) {
            if(v == 100) {
                value = 123;
            }
        },value);

        sleep(1);
        if(value != 123) {
            TEST_FAIL("[testThreadLambda value case2]");
        }
        break;
    }

    while(1) {
        int value = 100;
        Future f = t->submit([&value](int v) {
            if(v == 100) {
                value = 123;
            }
        },value);

        f->wait();
        if(value != 123) {
            TEST_FAIL("[testThreadLambda value case3]");
        }
        break;
    }

    t->shutdown();
    sleep(1);
    TEST_OK("[testThreadLambda value case5]");
}
