#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Integer.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "SqlQuery.hpp"
#include "TestLog.hpp"
#include <vector>
#include "SqlContentValues.hpp"

using namespace obotcha;


void testSimpleSql() {
    SqlContentValues values = createSqlContentValues();
    values->put(createString("a1"),123);
    values->put(createString("a2"),"456");
    values->put(createString("a3"),false);
    values->putString(createString("a4"),789);
    
    if(!values->getTags()->equals("(a4,a3,a2,a1)")) {
        TEST_FAIL("testSqlContentValues case1,tags is %s",values->getTags()->toChars());
    }
    
    if(!values->getValues()->equals("(\"789\",false,456,123)")) {
        TEST_FAIL("testSqlContentValues case2,values is %s",values->getValues()->toChars());
    }
            
    TEST_OK("testSqlContentValues case100");
}