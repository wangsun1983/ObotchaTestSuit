#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIncrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 32;testLoop++) {
            AtomicByte value = createAtomicByte(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 8;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<8*2;j++) {
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

            if(value->get() != 8*8*2) {
                TEST_FAIL("AtomicByte IncrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicByte value = createAtomicByte(3);
      long v = value->incrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicByte IncrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicByte IncrementAndGet test100");
}
