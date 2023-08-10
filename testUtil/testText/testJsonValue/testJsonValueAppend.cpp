#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Integer.hpp"
#include "String.hpp"
#include "JsonValue.hpp"
#include "JsonReader.hpp"
#include "TestLog.hpp"
#include "JsonWriter.hpp"
#include "Reflect.hpp"

using namespace obotcha;

DECLARE_CLASS(User) {
public:
    int age;
    String name;
    DECLARE_REFLECT_FIELD(User,age,name);
};


void testJsonValueAppend() {
    //test as array
    JsonValue value = createJsonValue();
    value->append("string1");
    value->append(100);
    
    auto v1 = value->getListItemAt(0);
    if(!v1->getString()->sameAs("string1")) {
        TEST_FAIL("JsonValue testJsonValueAppend case1");
    }
    
    auto v2 = value->getListItemAt(1);
    if(v2->getInteger()->toValue() != 100) {
        TEST_FAIL("JsonValue testJsonValueAppend case2");
    }
    
    if(value->size() != 2) {
        TEST_FAIL("JsonValue testJsonValueAppend case3");
    }
    
    //append object
    JsonValue objval = createJsonValue();
    objval->put("age",12);
    objval->put("name","wang");
    
    User usr = createUser();
    objval->reflectTo(usr);
    
    if(usr->age != 12 || !usr->name->sameAs("wang")) {
        TEST_FAIL("JsonValue testJsonValueAppend case4");
    }
    
//    JsonWriter writer = createJsonWriter("./aaa.json");
//    writer->write(objval);
    TEST_OK("JsonValue testJsonValueAppend case100");
}
