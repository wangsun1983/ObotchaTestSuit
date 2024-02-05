#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "AtomicNumber.hpp"

using namespace obotcha;

DECLARE_CLASS(MultiThreadData) {
public:
  _MultiThreadData(int value) {
    i = value;
  }

  int i;
};

void testMultiThreadQueue() {
    BlockingLinkedList<MultiThreadData> queue = createBlockingLinkedList<MultiThreadData>();
    ArrayList<Thread> threads = createArrayList<Thread>();
    AtomicInteger count = createAtomicInteger(0);
    int i = 0;
    for(;i < 32;i++) {
      Thread t1 = createThread([&](){
        while(1){
          //printf("thread[%d] take trace1 \n",i);
          auto value = queue->takeFirst();
          //printf("thread[%d] take trace2 \n",i);
          if(value != nullptr) {
            if(value->i == -1) {
              return;
            }
            count->incrementAndGet();
          }
        }
      });
      t1->start();
      threads->add(t1);
    }

    ArrayList<Thread> mSubmits = createArrayList<Thread>();
    int k = 0;
    for(;k < 32;k++) {
      Thread t1 = createThread([&](){
        for(int j = 0;j < 1024*16;j++) {
          //printf("thread[%d] put trace1 \n",k);
          queue->putFirst(createMultiThreadData(j));
          //printf("thread[%d] put trace2 \n",k);
        }
      });
      t1->start();
      mSubmits->add(t1);
    }

    for(int i = 0;i<mSubmits->size();i++) {
      mSubmits->get(i)->join();
    }

    for(int i = 0;i < 32;i++) {
      queue->putLast(createMultiThreadData(-1));
    }

    for(int i = 0;i<threads->size();i++) {
      threads->get(i)->join();
    }

    if(count->get() != 32*1024*16) {
      TEST_FAIL("BlockingLinkedList testMultiThreadQueue test1,value is %d",count->get());
    } else {
      TEST_OK("BlockingLinkedList testMultiThreadQueue test1");
    }

}
