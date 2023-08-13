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
#include "ForEveryOne.hpp"

using namespace obotcha;

DECLARE_CLASS(TestData) {
public:
    String strData;
    int intData;
    bool boolData;
    DECLARE_REFLECT_FIELD(TestData,strData,intData,boolData);
};

void testSqlObjectValues() {
    TestData data = createTestData();
    data->strData = createString("this is string");
    data->intData = 888;
    data->boolData = false;
    
    SqlContentValues values = createSqlContentValues();
    values->put(data);
    if(!values->getTags()->sameAs("(strData,intData,boolData)")) {
        TEST_FAIL("testSqlObjectValues cases1");
    }
    
    if(!values->getValues()->sameAs("(\"this is string\",888,false)")) {
        TEST_FAIL("testSqlObjectValues cases2");
    }
    
    TEST_OK("testSqlObjectValues case100");
}