#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Reflect.hpp"
#include "MySqlClient.hpp"
#include "SqlConnection.hpp"
#include "MySqlConnectParam.hpp"
#include "TestLog.hpp"
#include "File.hpp"

using namespace obotcha;

DECLARE_CLASS(Company) {
public:
    int id;
    String name;
    int age;
    DECLARE_REFLECT_FIELD(Company,name,age)
};


int main() {
    MySqlClient c = createMySqlClient();
    MySqlConnectParam param = createMySqlConnectParam();
    param->setHost("127.0.0.1");
    param->setUser("wangsun");
    param->setPassword("01122982");
    param->setDbName("student");
    param->setPort(3306);
    
    c->connect(param);

    c->exec("DROP TABLE Company;");

    //test create table
    c->exec("CREATE TABLE Company(id INT PRIMARY KEY,name TEXT,age INT);");
    c->exec("INSERT INTO Company(id,name,age) VALUES(1,\"Wang\",12)");
    ArrayList<Company> list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 1) {
        TEST_FAIL("MySql testTransaction case2");
    }

    c->startTransaction();
    c->exec("INSERT INTO Company(id,name,age) VALUES(2,\"Wang2\",22)");
    c->rollabckTransaction();
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 1) {
        TEST_FAIL("MySql testTransaction case2");
    }

    c->exec("INSERT INTO Company(id,name,age) VALUES(3,\"Wang3\",32)");
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 2) {
        TEST_FAIL("MySql testTransaction case3");
    }

    c->startTransaction();
    c->exec("INSERT INTO Company(id,name,age) VALUES(4,\"Wang4\",24)");
    c->exec("INSERT INTO Company(id,name,age) VALUES(5,\"Wang5\",54)");
    c->commitTransaction();
    
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 4) {
        TEST_FAIL("MySql testTransaction case6");
    }


    c->startTransaction();
    c->exec("INSERT INTO Company(id,name,age) VALUES(6,\"Wang4\",24)");
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 5) {
        TEST_FAIL("MySql testTransaction case7");
    }

    c->exec("INSERT INTO Company(id,name,age) VALUES(7,\"Wang5\",54)");
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 6) {
        TEST_FAIL("MySql testTransaction case8");
    }
    c->close();

    c = createMySqlClient();
    c->connect(param);
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 4) {
        TEST_FAIL("MySql testTransaction case9");
    }
    c->close();

    
    TEST_OK("MySql testTransaction case100");
}
