#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Reflect.hpp"
#include "MySqlConnection.hpp"
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
    
    SqlConnection c = createMySqlConnection();
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

    if(list == nullptr || list->size() == 0) {
        TEST_FAIL("Sqlite3 testCreateDB case1");
    }

    Company comp = list->get(0);
    if(!comp->name->equals("Wang") || comp->age != 12) {
        TEST_FAIL("MySql testCreateDB case2");
    }

    int count = c->count(createSqlQuery("select * from Company"));
    if(count != 1) {
        TEST_FAIL("MySql testCreateDB case3");
    }

    SqlRecords records = c->query(createSqlQuery("select * from Company"));
    auto iterator = records->getIterator();
    int index = 0;
    while(iterator->hasValue()) {
        List<String> data = iterator->getRowData();
        if(!data[0]->equals("1") || !data[1]->equals("Wang") || !data[2]->equals("12")) {
            TEST_FAIL("MySql testCreateDB case4,data[0] is %s,data[1] is %s,data[2] is %s",
                data[0]->toChars(),data[1]->toChars(),data[2]->toChars());
        }
        index++;
        break;
    }

    if(index != 1) {
        TEST_FAIL("MySql testCreateDB case5");
    }

    c->close();
    TEST_OK("MySql testCreateDB case100");
}
