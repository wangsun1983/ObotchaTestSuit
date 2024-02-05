#include <stdio.h>
#include <unistd.h>
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Reflect.hpp"
#include "Sqlite3Connection.hpp"
#include "SqlConnection.hpp"
#include "Sqlite3ConnectParam.hpp"
#include "TestLog.hpp"
#include "File.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

/*
id|name|age
9|wang9|9
10|wang10|10
11|wang11|11
12|wang12|12
13|wang13|13
14|wang14|14
15|wang15|15
16|wang16|16
17|wang17|17
18|wang18|18
19|wang19|19
20|wang20|20
21|wang21|21
22|wang22|22
23|wang23|23
24|wang24|24
25|wang25|25
26|wang26|26
27|wang27|27
28|wang28|28
*/

DECLARE_CLASS(Company) {
public:
    int id;
    String name;
    int age;
    DECLARE_REFLECT_FIELD(Company,id,name,age)
};

int main() {
    Sqlite3ConnectParam param = createSqlite3ConnectParam();
    param->setPath("./testdata.db");
    SqlConnection c = createSqlite3Connection();
    c->connect(param);

    ArrayList<Company> list = c->query<Company>(createSqlQuery("select * from Company"));
    if(list->size() != 20) {
        TEST_FAIL("Sqlite3 selectDb case1,size is %ld",list->size());
    }
    
    ForEveryOne(item,list) {
        int id = item->id;
        String name = item->name;
        int age = item->age;
        
        if(id != age) {
            TEST_FAIL("Sqlite3 selectDb case2,id is %d,age is %d",id,age);
        }
        
        String comp = createString("wang")->append(createString(id));
        if(!comp->sameAs(name)) {
            TEST_FAIL("Sqlite3 selectDb case3");
        }
    }
    
    auto count = c->count(createSqlQuery("select count(*) from Company"));
    if(count != 20) {
        TEST_FAIL("Sqlite3 selectDb case4,count is %d",count);
    }
    
    list = c->query<Company>(createSqlQuery("select * from Company where name like '%2'"));
    if(list->size() != 2) {
        TEST_FAIL("Sqlite3 selectDb case5,size is %ld",list->size());
    }
    
    auto item1 = list->get(0);
    if(item1->id != 12) {
        TEST_FAIL("Sqlite3 selectDb case6");
    }
    
    auto item2 = list->get(1);
    if(item2->id != 22) {
        TEST_FAIL("Sqlite3 selectDb case7");
    }
    
    TEST_OK("Sqlite3 selectDb case100");
}
