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

    ArrayList<String> list = ArrayList<String>::New();
    int count = 0;
    ForEveryOne(s,list) {
      count++;
    }
    
    if(count != 0) {
        TEST_FAIL("[testForeachWithNoData case1]");
    }

    TEST_OK("[testForeachWithNoData case100]");
}
