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
    Integer age;
    DECLARE_REFLECT_FIELD(Company,id,name,age)
};

int main() {
    
    File file = createFile("./tmp/testdata");
    file->removeAll();

    Sqlite3ConnectParam param = createSqlite3ConnectParam();
    param->setPath("./tmp/testdata");
    SqlConnection c = createSqlite3Connection();
    c->connect(param);

    File f = createFile("./tmp/testdata");
    if(!f->exists()) {
        TEST_FAIL("Sqlite3 testEraseDb case1");
    }

    //test create table
    c->exec("CREATE TABLE Company(id INT PRIMARY KEY,name TEXT,age INT);");
    //c->exec("INSERT INTO Company(id,name,age) VALUES(1,\"Wang\",12)");
    Company com = createCompany();
    com->id = 1;
    com->age = createInteger(12);
    com->name = createString("Wang");
    SqlContentValues values = createSqlContentValues();
    values->put(com);
    c->insert(createString("Company"),values);
    
    Company com2 = createCompany();
    com2->id = 2;
    com2->age = createInteger(22);
    com2->name = createString("Sun");
    SqlContentValues values2 = createSqlContentValues();
    values2->put(com2);
    c->insert(createString("Company"),values2);
    
    //check table first
    ArrayList<Company> list = c->query<Company>(createSqlQuery("select * from Company"));
    
    if(list == nullptr || list->size() != 2) {
        TEST_FAIL("Sqlite3 testEraseDb case1");
    }
    
    auto comp = list->get(0);
    if(!comp->name->equals("Wang") || comp->age->toValue() != 12 || comp->id != 1) {
        TEST_FAIL("Sqlite3 testEraseDb case2");
        return 0;
    }
    
    comp = list->get(1);
    if(!comp->name->equals("Sun") || comp->age->toValue() != 22 || comp->id != 2) {
        TEST_FAIL("Sqlite3 testEraseDb case3");
    }
    
    SqlQuery condition = createSqlQuery("id = 1");
    c->erase(createString("Company"),condition);
    
    list = c->query<Company>(createSqlQuery("select * from Company"));
    
    if(list == nullptr || list->size() != 1) {
        TEST_FAIL("Sqlite3 testEraseDb case4");
    }
    
    comp = list->get(0);
    if(!comp->name->equals("Sun") || comp->age->toValue() != 22 || comp->id != 2) {
        TEST_FAIL("Sqlite3 testEraseDb case5");
    }
    
    c->close();
    TEST_OK("Sqlite3 testEraseDb case100");
}
