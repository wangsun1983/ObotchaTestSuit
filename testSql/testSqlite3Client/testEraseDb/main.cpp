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
    
    File file = File::New("./tmp/testdata");
    file->removeAll();

    Sqlite3ConnectParam param = Sqlite3ConnectParam::New();
    param->setPath("./tmp/testdata");
    SqlConnection c = Sqlite3Connection::New();
    c->connect(param);

    File f = File::New("./tmp/testdata");
    if(!f->exists()) {
        TEST_FAIL("Sqlite3 testEraseDb case1");
    }

    //test create table
    c->exec("CREATE TABLE Company(id INT PRIMARY KEY,name TEXT,age INT);");
    //c->exec("INSERT INTO Company(id,name,age) VALUES(1,\"Wang\",12)");
    Company com = Company::New();
    com->id = 1;
    com->age = Integer::New(12);
    com->name = String::New("Wang");
    SqlContentValues values = SqlContentValues::New();
    values->put(com);
    c->insert(String::New("Company"),values);
    
    Company com2 = Company::New();
    com2->id = 2;
    com2->age = Integer::New(22);
    com2->name = String::New("Sun");
    SqlContentValues values2 = SqlContentValues::New();
    values2->put(com2);
    c->insert(String::New("Company"),values2);
    
    //check table first
    ArrayList<Company> list = c->query<Company>(SqlQuery::New("select * from Company"));
    
    if(list == nullptr || list->size() != 2) {
        TEST_FAIL("Sqlite3 testEraseDb case1");
    }
    
    auto comp = list->get(0);
    if(!comp->name->sameAs("Wang") || comp->age->toValue() != 12 || comp->id != 1) {
        TEST_FAIL("Sqlite3 testEraseDb case2");
        return 0;
    }
    
    comp = list->get(1);
    if(!comp->name->sameAs("Sun") || comp->age->toValue() != 22 || comp->id != 2) {
        TEST_FAIL("Sqlite3 testEraseDb case3");
    }
    
    SqlQuery condition = SqlQuery::New("id = 1");
    c->erase(String::New("Company"),condition);
    
    list = c->query<Company>(SqlQuery::New("select * from Company"));
    
    if(list == nullptr || list->size() != 1) {
        TEST_FAIL("Sqlite3 testEraseDb case4");
    }
    
    comp = list->get(0);
    if(!comp->name->sameAs("Sun") || comp->age->toValue() != 22 || comp->id != 2) {
        TEST_FAIL("Sqlite3 testEraseDb case5");
    }
    
    c->close();
    TEST_OK("Sqlite3 testEraseDb case100");
}
