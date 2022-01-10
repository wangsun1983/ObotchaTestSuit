#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingLinkedList.hpp"
#include "Integer.hpp"
#include "System.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBlockingLinkedListTryPutFirst() {

    while(1) {
        BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
        list->put(createString("a"));
        list->put(createString("b"));
        list->put(createString("c"));

        bool result = list->tryPutFirst(createString("d"));
        if(result) {
          TEST_FAIL("BlockingLinkedList TryPutFirst test1 \n");
          break;
        }

        if(list->size() != 3) {
          TEST_FAIL("BlockingLinkedList TryPutFirst test1_1 \n");
          break;
        }
        break;
    }

    while(1) {
      BlockingLinkedList<String> list = createBlockingLinkedList<String>(3);
      list->tryPutFirst(createString("a"));
      list->tryPutFirst(createString("b"));
      list->tryPutFirst(createString("c"));

      ArrayList<String> result = createArrayList<String>();
      result->add(createString("c"));
      result->add(createString("b"));
      result->add(createString("a"));
      auto iterator = result->getIterator();
      while(iterator->hasValue()) {
        auto v = iterator->getValue();
        auto v2 = list->takeFirst();
        if(!v->equals(v2)) {
          TEST_FAIL("BlockingLinkedList TryPutFirst test2,v is %s,v2 is %s \n",v->toChars(),v2->toChars());
          break;
        }
        iterator->next();
      }
      break;
    }

    TEST_OK("BlockingLinkedList TryPutFirst test100");
}
