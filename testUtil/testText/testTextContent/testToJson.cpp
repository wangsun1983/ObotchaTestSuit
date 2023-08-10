#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Boolean.hpp"
#include "StrongPointer.hpp"
#include "IllegalArgumentException.hpp"
#include "TextContent.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

using namespace obotcha;

DECLARE_CLASS(MyData) {
public:
    int id;
    String name;
    DECLARE_REFLECT_FIELD(MyData,name,id);
};


void testToJson() {
    MyData data = createMyData();
    data->id = 123;
    data->name = createString("wangsl");
    
    TextContent c = createTextContent(data);
    
    JsonReader v = createJsonReader(c->get());
    JsonValue value = v->get();
    auto id = value->getInteger("id");
    if(id == nullptr || id->toValue() != 123) {
        TEST_FAIL("TextContent toJson case1");
    }
    
    auto name = value->getString("name");
    if(name == nullptr || !name->sameAs("wangsl")) {
        TEST_FAIL("TextContent toJson case2");
    }

    TEST_OK("TextContent toJson case100");
}
