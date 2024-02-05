#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndSub() {
    while(1) {
        for(int testLoop = 0;testLoop < 128;testLoop++) {
            AtomicLong value = createAtomicLong(64*64*128);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 32;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<64*128;j++) {
                        value->getAndSub(2);
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
                TEST_FAIL("AtomicLong GetAndSub test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicLong value = createAtomicLong(5);
      long v = value->getAndSub(2);
      if(v != 5) {
        TEST_FAIL("AtomicLong GetAndSub test2");
        break;
      }

      if(value->get() != 3) {
        TEST_FAIL("AtomicLong GetAndSub test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicLong GetAndSub test100");
}
