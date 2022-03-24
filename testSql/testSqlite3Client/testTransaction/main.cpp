#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Reflect.hpp"
#include "Sqlite3Connection.hpp"
#include "SqlConnection.hpp"
#include "Sqlite3ConnectParam.hpp"
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
    File file = createFile("./abc");
    file->removeAll();

    Sqlite3ConnectParam param = createSqlite3ConnectParam();
    param->setPath("abc");
    SqlConnection c = createSqlite3Connection();
    c->connect(param);

    File f = createFile("./abc");
    if(!f->exists()) {
        TEST_FAIL("Sqlite3 testTransaction case1");
    }

    //test create table
    c->exec("CREATE TABLE Company(id INT PRIMARY KEY,name TEXT,age INT);");
    c->exec("INSERT INTO Company(id,name,age) VALUES(1,\"Wang\",12)");
    ArrayList<Company> list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 1) {
        TEST_FAIL("Sqlite3 testTransaction case2");
    }

    c->startTransaction();
    c->exec("INSERT INTO Company(id,name,age) VALUES(2,\"Wang2\",22)");
    c->rollabckTransaction();
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 1) {
        TEST_FAIL("Sqlite3 testTransaction case2");
    }

    c->exec("INSERT INTO Company(id,name,age) VALUES(3,\"Wang3\",32)");
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 2) {
        TEST_FAIL("Sqlite3 testTransaction case3");
    }

    c->startTransaction();
    c->exec("INSERT INTO Company(id,name,age) VALUES(4,\"Wang4\",24)");
    c->exec("INSERT INTO Company(id,name,age) VALUES(5,\"Wang5\",54)");
    c->commitTransaction();
    
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 4) {
        TEST_FAIL("Sqlite3 testTransaction case6");
    }


    c->startTransaction();
    c->exec("INSERT INTO Company(id,name,age) VALUES(6,\"Wang4\",24)");
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 5) {
        TEST_FAIL("Sqlite3 testTransaction case7");
    }

    c->exec("INSERT INTO Company(id,name,age) VALUES(7,\"Wang5\",54)");
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 6) {
        TEST_FAIL("Sqlite3 testTransaction case8");
    }
    c->close();

    c = createSqlite3Connection();
    c->connect(param);
    list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 4) {
        TEST_FAIL("Sqlite3 testTransaction case9");
    }
    c->close();

    
    TEST_OK("Sqlite3 testTransaction case100");
}
