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
#include "MySqlConnection.hpp"
#include "SqlConnection.hpp"
#include "MySqlConnectParam.hpp"
#include <vector>
#include "TestLog.hpp"

using namespace obotcha;


int testSimpleSql() {
    SqlConnection connection = createMySqlConnection();

    MySqlConnectParam param = createMySqlConnectParam();
    param->setHost("127.0.0.1");
    param->setUser("wangsun");
    param->setPassword("01122982");
    param->setDbName("student");
    param->setPort(3306);
    
    connection->connect(param);
    /*
    ArrayList<Student> list = client->query<Student>(createSqlQuery("select * from information"));
    printf("list size is %d \n",list->size());
    ListIterator<Student> iterator = list->getIterator();
    while(iterator->hasValue()) {
        Student t = iterator->getValue();
        t->dump();
        iterator->next();
    }*/

    SqlRecords records = connection->query(createSqlQuery("select * from information"));
    SqlRecordsIterator iterator = records->getIterator();
    printf("wangsl,trace1 \n");
    while(iterator->hasValue()) {
        List<String> list = iterator->getRowData();
        for(int index = 0;index<list->size();index++) {
            printf("list[%d] is %s \n",index,list[index]->toChars());
        }
        iterator->next();
    }

    if(records->getRowNum() == 0) {
        TEST_FAIL("TestSqlConnection query case1");
    }

    TEST_OK("TestSqlConnection query case100");
    return 0;
}