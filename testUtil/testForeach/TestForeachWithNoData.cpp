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
#include "ConcurrentQueue.hpp"

using namespace obotcha;

void testForeachWithNoData() {

    ArrayList<String> list = createArrayList<String>();
    ForEveryOne(s,list) {
      printf("s is %s \n",s->toChars());
    }

    TEST_OK("[testForeachWithNoData case100]");
}
