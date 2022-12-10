#include <stdio.h>
#include <unistd.h>

#include "AtomicUint64.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndAdd() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicUint64 value = createAtomicUint64(0);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 64;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<64*32;j++) {
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

            if(value->get() != 64*64*32*2) {
                TEST_FAIL("AtomicUint64 GetAndAdd test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint64 value = createAtomicUint64(3);
      long v = value->getAndAdd(2);
      if(v != 3) {
        TEST_FAIL("AtomicUint64 GetAndAdd test2");
        break;
      }

      if(value->get() != 5) {
        TEST_FAIL("AtomicUint64 GetAndAdd test3");
        break;
      }

      break;
    }
    TEST_OK("AtomicUint64 AddAndGet test100");
}
