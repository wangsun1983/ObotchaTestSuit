#include <stdio.h>
#include <unistd.h>

#include "AtomicUint16.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAddAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 16;testLoop++) {
            AtomicUint16 value = createAtomicUint16(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 16;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<16;j++) {
                        value->addAndGet(2);
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

            if(value->get() != 16*16*2) {
                TEST_FAIL("AtomicUint16 AddAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint16 Long = createAtomicUint16(3);
      long v = Long->addAndGet(2);
      if(v != 5) {
        TEST_FAIL("AtomicUint16 AddAndGet test2");
        break;
      }

      break;
    }
    TEST_OK("AtomicUint16 AddAndGet test100");
}
