#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndDecrement() {
    while(1) {
        for(int testLoop = 0;testLoop < 16;testLoop++) {
            AtomicUint16 value = AtomicUint16::New(128*16*32);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 128;i++) {
                Thread t = Thread::New([&value] {
                    for(int j = 0;j<16*32;j++) {
                        value->getAndDecrement();
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
                TEST_FAIL("AtomicUint16 GetAndDecrement test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint16 value = AtomicUint16::New(5);
      long v = value->getAndDecrement();
      if(v != 5) {
        TEST_FAIL("AtomicUint16 GetAndDecrement test2");
        break;
      }

      if(value->get() != 4) {
        TEST_FAIL("AtomicUint16 GetAndDecrement test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint16 GetAndDecrement test100");
}
