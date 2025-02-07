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

using namespace obotcha;

DECLARE_CLASS(Student) {
public:
    int age;
    int id;
    String name;

    void dump() {
        printf("name is %s ,age is %d,id is %d \n",name->toChars(),age,id);
    }

    DECLARE_REFLECT_FIELD(Student,age,id,name)
};


int main() {
    Sqlite3ConnectParam param = Sqlite3ConnectParam::New();
    param->setPath("abc");
    SqlConnection c = Sqlite3Connection::New();
    c->connect(param);
    int count = c->count(SqlQuery::New("select count(*) from student"));
    if(count != 4) {
        TEST_FAIL("Sqlite3 testOpenDB case1,count is %d",count);
    }

    ArrayList<Student> list = c->query<Student>("select * from student");
    if(list->size() != 4) {
        TEST_FAIL("Sqlite3 testOpenDB case2,count is %d",count);
    }

    //database
    ArrayList<Student> datalist = ArrayList<Student>::New();
    Student d1 = Student::New();
    d1->age = 123;
    d1->name = String::New("wangsl");
    d1->id = 1;

    Student d2 = Student::New();
    d2->age = 1;
    d2->name = String::New("wa");
    d2->id = 2;

    Student d3 = Student::New();
    d3->age = 2;
    d3->name = String::New("waaa1");
    d3->id = 3;

    Student d4 = Student::New();
    d4->age = 3;
    d4->name = String::New("a");
    d4->id = 4;

    datalist->add(d1);
    datalist->add(d2);
    datalist->add(d3);
    datalist->add(d4);
        
    auto iterator = list->getIterator();
    int index = 0;
    while(iterator->hasValue()) {
        auto s = iterator->getValue();
        auto v = datalist->get(index);
        if(s->age != v->age || s->id != v->id || !s->name->equals(v->name)) {
            TEST_FAIL("Sqlite3 testOpenDB case3,index is %d",index);
        }
        index++;
        iterator->next();
    }

    if(index != 4) {
        TEST_FAIL("Sqlite3 testOpenDB case4,index is %d",index);
    }


    SqlRecords records = c->query(SqlQuery::New("select * from student"));
    if(records->getRowNum() != 4) {
        TEST_FAIL("Sqlite3 testOpenDB case4_1,size is %d",records->getRowNum());
    }

    auto iterator2 = records->getIterator();
    index = 0;
    while(iterator2->hasValue()) {
        List<String> s = iterator2->getRowData();
        auto v = datalist->get(index);
        if(!s[0]->equals(String::New(v->age)) || !s[1]->equals(v->name) || !s[2]->equals(String::New(v->id))) {
            TEST_FAIL("Sqlite3 testOpenDB case5index is %d",index);
        }
        index++;
        iterator2->next();
    }

    if(index != 4) {
        TEST_FAIL("Sqlite3 testOpenDB case6,index is %d",index);
    }

    c->close();

    TEST_OK("Sqlite3 testOpenDB case100");
}
