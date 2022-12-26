#include <stdio.h>
#include <unistd.h>

#include "AtomicUint8.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testDecrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 128;testLoop++) {
            AtomicUint8 value = createAtomicUint8(8*8*2);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 8;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<8*2;j++) {
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
                TEST_FAIL("AtomicUint8 DecrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint8 Long = createAtomicUint8(5);
      long v = Long->decrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicUint8 DecrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint8 DecrementAndGet test100");
}
