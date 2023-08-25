#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIncrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicInteger value = createAtomicInteger(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 128;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<64*32;j++) {
                        value->incrementAndGet();
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

            if(value->get() != 128*64*32) {
                TEST_FAIL("AtomicInteger IncrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicInteger integer = createAtomicInteger(3);
      int v = integer->incrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicInteger IncrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger IncrementAndGet test100");
}
