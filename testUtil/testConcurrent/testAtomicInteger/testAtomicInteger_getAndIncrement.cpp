#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndIncrement() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicInteger value = AtomicInteger::New(0);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 64;i++) {
                Thread t = Thread::New([&value] {
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
                TEST_FAIL("AtomicInteger GetAndIncrement test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicInteger integer = AtomicInteger::New(3);
      int v = integer->getAndIncrement();
      if(v != 3) {
        TEST_FAIL("AtomicInteger GetAndIncrement test2");
        break;
      }

      if(integer->get() != 4) {
        TEST_FAIL("AtomicInteger GetAndIncrement test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicInteger GetAndIncrement test100");
}
