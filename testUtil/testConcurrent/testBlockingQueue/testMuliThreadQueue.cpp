#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
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
    BlockingQueue<MultiThreadData> queue = BlockingQueue<MultiThreadData>::New();
    ArrayList<Thread> threads = ArrayList<Thread>::New();
    AtomicInteger count = AtomicInteger::New(0);
    for(int i = 0;i < 32;i++) {
      Thread t1 = Thread::New([queue,count](){
        while(1){
          auto value = queue->takeFirst();
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

    ArrayList<Thread> mSubmits = ArrayList<Thread>::New();
    for(int i = 0;i < 32;i++) {
      Thread t1 = Thread::New([queue](){
        for(int j = 0;j < 1024*16;j++) {
          queue->putFirst(MultiThreadData::New(j));
        }
      });
      t1->start();
      mSubmits->add(t1);
    }

    for(int i = 0;i<mSubmits->size();i++) {
      mSubmits->get(i)->join();
    }

    for(int i = 0;i < 32;i++) {
      queue->putFirst(MultiThreadData::New(-1));
    }

    for(int i = 0;i<threads->size();i++) {
      threads->get(i)->join();
    }

    if(count->get() != 32*1024*16) {
      TEST_FAIL("BlockingQueue testMultiThreadQueue test1");
    } else {
      TEST_OK("BlockingQueue testMultiThreadQueue test1");
    }

}
