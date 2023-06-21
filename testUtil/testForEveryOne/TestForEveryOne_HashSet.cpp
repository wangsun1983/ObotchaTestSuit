#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "LinkedList.hpp"
#include "HashSet.hpp"
#include "Boolean.hpp"

using namespace obotcha;

void testHashSet() {
    while(1) {
      HashSet<int> sets = createHashSet<int>();
      HashMap<int,Boolean> valuemap = createHashMap<int,Boolean>();

      for(int i = 0;i<32;i++) {
        sets->add(i*32);
        valuemap->put(i*32,createBoolean(true));
      }

      ForEveryOne(v,sets) {
        if(valuemap->get(v) == nullptr) {
          TEST_FAIL("ForEveryOne HashSet case1");
        }
      }
      break;
    }



    TEST_OK("ForEveryOne HashSet case100");
}
