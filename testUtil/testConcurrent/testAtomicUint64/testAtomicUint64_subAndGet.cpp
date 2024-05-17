#include <stdio.h>
#include <unistd.h>

#include "AtomicNumber.hpp"
#include "Thread.hpp"
#include "TestLog.hpp"
using namespace obotcha;

void testSubAndGet() {
    while(1) {
        for(int testLoop = 0;testLoop < 128;testLoop++) {
            AtomicUint64 value =AtomicUint64::New(64*64*256);
            ArrayList<Thread> list = ArrayList<Thread>::New();

            for(int i = 0;i < 32;i++) {
                Thread t = Thread::New([&value] {
                    for(int j = 0;j<64*256;j++) {
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
                TEST_FAIL("AtomicUint64 SubAndGet test1");
                break;
            }
        }

        break;
    }

    while(1) {
      AtomicUint64 value =AtomicUint64::New(5);
      long v = value->subAndGet(2);
      if(v != 3) {
        TEST_FAIL("AtomicUint64 SubAndGet test2");
        break;
      }
      break;
    }

    TEST_OK("AtomicUint64 SubAndGet test100");
}
