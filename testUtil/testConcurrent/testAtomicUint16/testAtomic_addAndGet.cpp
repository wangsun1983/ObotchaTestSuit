#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testAddAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 16;testLoop++) {
            AtomicUint16 value = AtomicUint16::New(0);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 16;i++) {
                Thread t = Thread::New([&value] {
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
      AtomicUint16 Long = AtomicUint16::New(3);
      long v = Long->addAndGet(2);
      if(v != 5) {
        TEST_FAIL("AtomicUint16 AddAndGet test2");
        break;
      }

      break;
    }
    TEST_OK("AtomicUint16 AddAndGet test100");
}
