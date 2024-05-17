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
#include "SqlTableEntryValues.hpp"

using namespace obotcha;

DECLARE_CLASS(Company) {
public:
    int id;
    String name;
    int age;
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
        TEST_FAIL("Sqlite3 testCreateDB case1");
    }

    //test create table
    //c->exec("CREATE TABLE Company(id INT PRIMARY KEY,name TEXT,age INT);");
    SqlTableEntryValues entries = SqlTableEntryValues::New();
    entries->addEntry(String::New("id"),String::New("INT"),0,String::New("PRIMARY KEY"));
    entries->addEntry(String::New("name"),String::New("TEXT"));
    entries->addEntry(String::New("age"),String::New("INT"));
    c->create(String::New("Company"),entries);
    
    c->exec("INSERT INTO Company(id,name,age) VALUES(1,\"Wang\",12)");
    ArrayList<Company> list = c->query<Company>(SqlQuery::New("select * from Company"));

    if(list == nullptr || list->size() == 0) {
        TEST_FAIL("Sqlite3 testCreateDB case1");
    }


    Company comp = list->get(0);
    if(!comp->name->sameAs("Wang") || comp->age != 12) {
        printf("comp name is %s \n",comp->name->toChars());
        TEST_FAIL("Sqlite3 testCreateDB case2");
    }

    int count = c->count(SqlQuery::New("select count(*) from Company"));
    if(count != 1) {
        TEST_FAIL("Sqlite3 testCreateDB case3");
    }

    SqlRecords records = c->query(SqlQuery::New("select * from Company"));
    auto iterator = records->getIterator();
    int index = 0;
    while(iterator->hasValue()) {
        List<String> data = iterator->getRowData();
        if(!data[0]->sameAs("1") || !data[1]->sameAs("Wang") || !data[2]->sameAs("12")) {
            TEST_FAIL("Sqlite3 testCreateDB case4,data[0] is %s,data[1] is %s,data[2] is %s",
                data[0]->toChars(),data[1]->toChars(),data[2]->toChars());
        }
        index++;
        break;
    }

    if(index != 1) {
        TEST_FAIL("Sqlite3 testCreateDB case5");
    }

    c->close();
    TEST_OK("Sqlite3 testCreateDB case100");
}
