#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testSubAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicInteger value = createAtomicInteger(64*64*32);
            ArrayList<Thread> list = createArrayList<Thread>();

            for(int i = 0;i < 32;i++) {
                Thread t = createThread([&value] {
                    for(int j = 0;j<64*32;j++) {
                        value->subAndGet(2);
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
                TEST_FAIL("AtomicInteger SubAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicInteger integer = createAtomicInteger(5);
      int v = integer->subAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicInteger SubAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger SubAndGet test100");
}
