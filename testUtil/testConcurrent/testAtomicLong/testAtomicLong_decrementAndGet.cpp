#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testDecrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 128;testLoop++) {
            AtomicLong value = createAtomicLong(128*64*32);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 128;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<64*32;j++) {
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
                TEST_FAIL("AtomicLong DecrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicLong Long = createAtomicLong(5);
      long v = Long->decrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicLong DecrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicLong DecrementAndGet test100");
}
