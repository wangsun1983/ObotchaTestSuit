#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Reflect.hpp"
#include "Sqlite3Client.hpp"
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
    Sqlite3Client c = createSqlite3Client();
    c->connect(param);

    File f = createFile("./abc");
    if(!f->exists()) {
        TEST_FAIL("Sqlite3 testCreateDB case1");
    }

    //test create table
    c->exec("CREATE TABLE Company(id INT PRIMARY KEY,name TEXT,age INT);");
    c->exec("INSERT INTO Company(id,name,age) VALUES(1,\"Wang\",12)");
    ArrayList<Company> list = c->query<Company>(createSqlQuery("select * from Company"));

    if(list == nullptr || list->size() == 0) {
        TEST_FAIL("Sqlite3 testCreateDB case1");
    }

    Company comp = list->get(0);
    if(!comp->name->equals("Wang") || comp->age != 12) {
        TEST_FAIL("Sqlite3 testCreateDB case2");
    }

    int count = c->count(createSqlQuery("select * from Company"));
    if(count != 1) {
        TEST_FAIL("Sqlite3 testCreateDB case3");
    }

    SqlRecords records = c->query(createSqlQuery("select * from Company"));
    auto iterator = records->getIterator();
    int index = 0;
    while(iterator->hasValue()) {
        List<String> data = iterator->getRowData();
        if(!data[0]->equals("1") || !data[1]->equals("Wang") || !data[2]->equals("12")) {
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
