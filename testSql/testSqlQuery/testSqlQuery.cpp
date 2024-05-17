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

using namespace obotcha;


void testSimpleSql() {
    //case1
    SqlQuery query = SqlQuery::New("parma1 is _$1,param2 is _$2,param3 is _$3,param4 is _$4,param5 is _$5,param6 is _$6,param7 is _$7");
    query->bindParam(1,
                     2,
                     "aaaa",
                     String::New("bbbb"),
                     Integer::New(100),
                     Boolean::New("false"),
                     Uint32::New(1234556));
    if(query->toString()->sameAs("parma1 is 1,param2 is 2,param3 is aaaa,param4 is bbbb,param5 is 100,param6 is false,param7 is 12456")) {
        TEST_FAIL("testSqlQuery case1");
    }
    
    //case2
    query = SqlQuery::New("param is \"_$1\"");
    query->bindParam(1);
    if(!query->toString()->sameAs("param is \"1\"")) {
        TEST_FAIL("testSqlQuery case2");
    }
    
    //case3
    query = SqlQuery::New("param is \"_$1\",param2 is _$2");
    query->bindParam(2,"bb");
    if(!query->toString()->sameAs("param is \"2\",param2 is bb")) {
        TEST_FAIL("testSqlQuery case2");
    }
    
    auto templateStr = query->getTemplate();
    if(!templateStr->sameAs("param is \"_$1\",param2 is _$2")) {
        TEST_FAIL("testSqlQuery case3");
    }
    
    TEST_OK("testSqlQuery case100");
}