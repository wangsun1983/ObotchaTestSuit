#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndIncrement() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicUint64 value = createAtomicUint64(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 64;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<64*32;j++) {
                        value->getAndIncrement();
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

            if(value->get() != 64*64*32) {
                TEST_FAIL("AtomicUint64 GetAndIncrement test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint64 value = createAtomicUint64(3);
      long v = value->getAndIncrement();
      if(v != 3) {
        TEST_FAIL("AtomicUint64 GetAndIncrement test2");
        break;
      }

      if(value->get() != 4) {
        TEST_FAIL("AtomicUint64 GetAndIncrement test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint64 GetAndIncrement test100");
}
