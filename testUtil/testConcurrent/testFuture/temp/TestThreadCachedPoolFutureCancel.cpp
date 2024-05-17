#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "ExecutorService.hpp"
#include "Integer.hpp"
#include "Executors.hpp"
#include "Future.hpp"
#include "System.hpp"

using namespace obotcha;


DECLARE_CLASS(TestCachedCancelRun1) IMPLEMENTS(Runnable) {
public:
    _TestCachedCancelRun1() {
        interrupt = 0;
        value = 0;
    }

    void run() {
        sleep(2);
        value = 1;
    }

    void onInterrupt() {
        interrupt = 1;
    }

    int getValue() {
        return value;
    }

    int getInterrupt() {
        return interrupt;
    }

private:
    int value;
    int interrupt; 
};

DECLARE_CLASS(TestCachedCancelRun2) IMPLEMENTS(Runnable) {
public:
    _TestCachedCancelRun2() {
        interrupt = 0;
        value = 0;
    }

    void run() {
        sleep(2);
        value++;
        printf("run thread:%d finished \n",count);
    }

    void onInterrupt() {
        interrupt = 1;
    }

    int getValue() {
        return value;
    }

    int getInterrupt() {
        return interrupt;
    }

    void setCount(int v) {
        count = v;
    }

    int getCount() {
        return count;
    }

private:
    int value;
    int interrupt;
    int count;
};

int testThreadCachedPoolFutureCancel() {
    //threadExecutorPool
    while(1) {
        ExecutorService pool = st(Executors)::newCachedThreadPool();
        TestCachedCancelRun1 run1 = TestCachedCancelRun1::New();
        Future f = pool->submit(run1);
        sleep(1);
        f->cancel();
        sleep(5);
        if(run1->getValue() == 1 || run1->getInterrupt() != 1) {
            printf("---[TestFuture CachedThreadPool Test {cancel()} case1] [FAIL],val is %d,interrupt is %d--- \n",run1->getValue(),run1->getInterrupt());
            break;
        }
        pool->shutdown();
        printf("---[TestFuture CachedThreadPool Test {cancel()} case2] [Success]--- \n");
        break;
    }

  
    while(1) {
        ExecutorService pool = st(Executors)::newCachedThreadPool();
        ArrayList<Future> futurelist = ArrayList<Future>::New();
        for(int i = 0;i<50;i++) {
            Future f = pool->submit(TestCachedCancelRun1::New());
            futurelist->add(f);
        }

        //for(int j = 0;j<50;j++) {
        ListIterator<Future> iterator = futurelist->getIterator();
        while(iterator->hasValue()) {
            Future f = iterator->getValue();
            f->cancel();
            iterator->next();
        }
        //}
        

        sleep(1);
        pool->shutdown();
        printf("---[TestFuture CachedThreadPool Test {cancel()} case3] [Success]--- \n");
        break;
    }

    while(1) {
        ExecutorService pool = st(Executors)::newCachedThreadPool();
        ArrayList<Future> futurelist = ArrayList<Future>::New();
        for(int i = 0;i<50;i++) {
            Future f = pool->submit(TestCachedCancelRun1::New());
            futurelist->add(f);
        }

        pool->shutdown();

        for(int j = 0;j<50;j++) {
            ListIterator<Future> iterator = futurelist->getIterator();
            while(iterator->hasValue()) {
                Future f = iterator->getValue();
                f->cancel();
                iterator->next();
            }
        }
        
        sleep(1);
        pool->shutdown();
        printf("---[TestFuture CachedThreadPool Test {cancel()} case4] [Success]--- \n");
        break;
    }


    while(1) {
        ExecutorService pool = st(Executors)::newCachedThreadPool();
        ArrayList<Future> futurelist = ArrayList<Future>::New();
        for(int i = 0;i<55;i++) {
            Future f = pool->submit(TestCachedCancelRun1::New());
            futurelist->add(f);
        }

        for(int j = 0;j<50;j++) {
            ListIterator<Future> iterator = futurelist->getIterator();
            while(iterator->hasValue()) {
                Future f = iterator->getValue();
                f->cancel();
                iterator->next();
            }
        }

        long start = st(System)::CurrentTimeMillis();
        //for(int i = 0;i<50;i++) {
        printf("submit testcancel run1 \n");
        Future f1 = pool->submit(TestCachedCancelRun1::New());
        Future f2 = pool->submit(TestCachedCancelRun1::New());
        long end = st(System)::CurrentTimeMillis();
        if((end - start) > 10) {
            printf("---[TestFuture CachedThreadPool Test {cancel()} case5] [Fail],%d --- \n",end-start);
            break;
        }

        printf("---[TestFuture CachedThreadPool Test {cancel()} case6] [Success]--- \n");
        pool->shutdown();
        break;
    }


    while(1) {
        ExecutorService pool = st(Executors)::newCachedThreadPool();
        ArrayList<Future> futurelist = ArrayList<Future>::New();
        ArrayList<TestCachedCancelRun2> runlist = ArrayList<TestCachedCancelRun2>::New();
        for(int i = 0;i<55;i++) {
            TestCachedCancelRun2 run2 = TestCachedCancelRun2::New();
            run2->setCount(i);
            runlist->add(run2);
            Future f = pool->submit(run2);
            futurelist->add(f);
        }
        sleep(1);
        printf("start stop future \n");
        //for(int j = 0;j<55;j++) {
            ListIterator<Future> iterator = futurelist->getIterator();
            while(iterator->hasValue()) {
                Future f = iterator->getValue();
                f->cancel();
                iterator->next();
            }
        //}

        sleep(100);

        
        ListIterator<TestCachedCancelRun2> iterator2 = runlist->getIterator();
        while(iterator2->hasValue()) {
            TestCachedCancelRun2 run_2 = iterator2->getValue();
            if(run_2->getValue() != 0) {
                printf("---[TestFuture CachedThreadPool Test {cancel()} case7] [Fail],count is %d,value is %d --- \n",run_2->getCount(),run_2->getValue());
                //break;
            }
            iterator2->next();
        }

        printf("---[TestFuture CachedThreadPool Test {cancel()} case8] [Success] --- \n");
        pool->shutdown();
        break;
       
    }

}
