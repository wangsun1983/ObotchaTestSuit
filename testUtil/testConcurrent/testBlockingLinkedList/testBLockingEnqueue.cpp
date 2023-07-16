#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(EnqueueData) {
public:
    _EnqueueData(int v) {
        i = v;
    }

    int getValue() {
        return i;
    }

private:
    int i;
};

DECLARE_CLASS(EnqueueThread1) IMPLEMENTS(Thread) {
public:
    _EnqueueThread1(BlockingLinkedList<EnqueueData> queue) {
        mQueue = queue;
    }

    void run() {
        st(Thread)::sleep(1000*5);
        mQueue->takeFirst();
    }

private:
    BlockingLinkedList<EnqueueData> mQueue;
};

DECLARE_CLASS(EnqueueThread2) IMPLEMENTS(Thread) {
public:
    _EnqueueThread2(BlockingLinkedList<EnqueueData> queue) {
        mQueue = queue;
        fvalue = 0;
    }

    void run() {
        int i = 0;
        while(1) {
            //TEST_FAIL("setvalue is %d \n",i);
            EnqueueData d = createEnqueueData(i);
            mQueue->putFirst(d);
            mQueue->putFirst(d);
            if(i == 50) {
                EnqueueData nt = nullptr;
                mQueue->putLast(nt);
                //TEST_FAIL("fvalue is %d \n",fvalue);
                return;
            }
            i++;
            fvalue += i;
        }
    }

private:
    BlockingLinkedList<EnqueueData> mQueue;
    int fvalue;
};

DECLARE_CLASS(DequeueThread2) IMPLEMENTS(Thread) {
public:
    _DequeueThread2(BlockingLinkedList<EnqueueData> queue) {
        mQueue = queue;
        value = 0;
    }

    void run() {
        int i = 0;
        while(1) {
            EnqueueData d = mQueue->takeFirst();
            if(d == nullptr) {
                //printf("result value is %d \n",value);
                return;
            }
            //TEST_FAIL("d->getValue is %d \n",d->getValue());
            //printf("d->getValue is %d \n",d->getValue());
            value += d->getValue();
        }
    }

    int getResult() {
        return value;
    }

private:
    BlockingLinkedList<EnqueueData> mQueue;
    int value;
};


void testEnqueueDequeue() {
#if 0
    while(1) {
        BlockingLinkedList<EnqueueData> list = createBlockingLinkedList<EnqueueData>(5);
        list->putFirst(createEnqueueData(1));
        list->putFirst(createEnqueueData(2));
        list->putFirst(createEnqueueData(3));
        list->putFirst(createEnqueueData(4));
        list->putFirst(createEnqueueData(5));
        EnqueueThread1 t1 = createEnqueueThread1(list);
        t1->start();
        long time1 = st(System)::CurrentTimeMillis();
        list->putFirst(createEnqueueData(5));
        long time2 = st(System)::CurrentTimeMillis();
        if((time2 - time1) < 5000 || (time2 - time1) > 5005) {
            TEST_FAIL("BlockingEnqueue putFirst test1");
            break;
        }

        TEST_OK("BlockingEnqueue putFirst test2");
        break;
    }

    while(1) {
        BlockingLinkedList<EnqueueData> list = createBlockingLinkedList<EnqueueData>(5);
        list->putFirst(createEnqueueData(1));
        list->putFirst(createEnqueueData(2));
        list->putFirst(createEnqueueData(3));
        list->putFirst(createEnqueueData(4));
        list->putFirst(createEnqueueData(5));

        EnqueueData data1 = list->takeFirst();
        if(data1->getValue() != 5) {
            TEST_FAIL("BlockingEnqueue putFirst test3");
            break;
        }

        data1 = list->takeFirst();
        if(data1->getValue() != 4) {
            TEST_FAIL("BlockingEnqueue putFirst test4");
            break;
        }

        data1 = list->takeFirst();
        if(data1->getValue() != 3) {
            TEST_FAIL("BlockingEnqueue putFirst test5");
            break;
        }

        data1 = list->takeFirst();
        if(data1->getValue() != 2) {
            TEST_FAIL("BlockingEnqueue putFirst test6");
            break;
        }

        data1 = list->takeFirst();
        if(data1->getValue() != 1) {
            TEST_FAIL("BlockingEnqueue putFirst test7");
            break;
        }

        TEST_OK("BlockingEnqueue putFirst test8");
        break;
    }

    while(1) {
        BlockingLinkedList<EnqueueData> list = createBlockingLinkedList<EnqueueData>(5);
        list->putFirst(nullptr);
        if(list->size() == 0) {
            TEST_FAIL("BlockingEnqueue putFirst test9");
            break;
        }

        TEST_OK("BlockingEnqueue putFirst test10");
        break;
    }
#endif

    while(1) {
        BlockingLinkedList<EnqueueData> list = createBlockingLinkedList<EnqueueData>(5);
        EnqueueThread2 t1 = createEnqueueThread2(list);
        DequeueThread2 t2 = createDequeueThread2(list);

        t1->start();
        t2->start();

        t1->join();
        t2->join();

        int result = t2->getResult();
        if(result != 2550) {
            TEST_FAIL("BlockingEnqueue putFirst test11,result is %d",result);
            break;
        }

        TEST_OK("BlockingEnqueue putFirst test12");
        break;
    }
}
