#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIncrementAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 32;testLoop++) {
            AtomicUint8 value = AtomicUint8::New(0);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 8;i++) {
                Thread t = Thread::New([&value] {
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
                TEST_FAIL("AtomicUint8 IncrementAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint8 value = AtomicUint8::New(3);
      long v = value->incrementAndGet();
      if(v != 4) {
        TEST_FAIL("AtomicUint8 IncrementAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint8 IncrementAndGet test100");
}
