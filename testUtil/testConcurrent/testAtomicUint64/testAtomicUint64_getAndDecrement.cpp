#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetAndDecrement() {
    while(1) {
        for(int testLoop = 0;testLoop < 64;testLoop++) {
            AtomicUint64 value =AtomicUint64::New(128*64*32);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 128;i++) {
                Thread t = Thread::New([&value] {
                    for(int j = 0;j<64*32;j++) {
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
                TEST_FAIL("AtomicUint64 GetAndDecrement test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint64 value =AtomicUint64::New(5);
      long v = value->getAndDecrement();
      if(v != 5) {
        TEST_FAIL("AtomicUint64 GetAndDecrement test2");
        break;
      }

      if(value->get() != 4) {
        TEST_FAIL("AtomicUint64 GetAndDecrement test3");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint64 GetAndDecrement test100");
}
