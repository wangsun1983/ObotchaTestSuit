#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testDecrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicInteger value = AtomicInteger::New(32*32*256);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 32;i++) {
                Thread t = Thread::New([&value] {
                    for(int j = 0;j<32*256;j++) {
                        value->decrementAndGet();
                    }
                });
                list->add(t);
                t->start();
            }

            auto iterator = list->getIterator();
            while(iterator->hasValue()) {
               auto t = iterator->getValue();
               t->join();
               iterator->next();
            }

            if(value->get() != 0) {
                TEST_FAIL("AtomicInteger DecrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicInteger integer = AtomicInteger::New(5);
      int v = integer->decrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicInteger DecrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger DecrementAndGet test100");
}
