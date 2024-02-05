#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIncrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 32;testLoop++) {
            AtomicUint16 value = createAtomicUint16(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 32;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<16*32;j++) {
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

            if(value->get() != 32*16*32) {
                TEST_FAIL("AtomicUint16 IncrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint16 value = createAtomicUint16(3);
      long v = value->incrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicUint16 IncrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint16 IncrementAndGet test100");
}
