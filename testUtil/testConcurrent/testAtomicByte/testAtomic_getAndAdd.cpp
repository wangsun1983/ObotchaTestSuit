#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAdd() {
    while(1) {
        for(int testLoop = 0;testLoop < 16;testLoop++) {
            AtomicByte value = createAtomicByte(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 8;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<4*2;j++) {
                        value->getAndAdd(2);
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

            if(value->get() != 8*4*2*2) {
                TEST_FAIL("AtomicByte GetAndAdd test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicByte value = createAtomicByte(3);
      long v = value->getAndAdd(2);
      if(v != 3) {
        TEST_FAIL("AtomicByte GetAndAdd test2");
        break;
      }

      if(value->get() != 5) {
        TEST_FAIL("AtomicByte GetAndAdd test3");
        break;
      }

      break;
    }
    TEST_OK("AtomicByte AddAndGet test100");
}
