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
#include "XmlReader.hpp"
#include "Text.hpp"

using namespace obotcha;

DECLARE_CLASS(MyXmlData) {
public:
    int id;
    String name;
    DECLARE_REFLECT_FIELD(MyXmlData,name,id);
};


void testToXml() {
    MyXmlData data = MyXmlData::New();
    data->id = 123;
    data->name = String::New("wangsl");
    
    TextContent c = TextContent::New(data,st(Text)::Format::Xml);
    //printf("c is %s \n",c->get()->toChars());
    
    XmlReader reader = XmlReader::New()->loadContent(c->get());
    XmlValue value = reader->get()->getRootNode();
    
    auto id = value->getIntegerValue("id");
    if(id == nullptr || id->toValue() != 123) {
        TEST_FAIL("TextContent toXml case1");
    }
    
    auto name = value->getStringValue("name");
    if(name == nullptr || !name->sameAs("wangsl")) {
        TEST_FAIL("TextContent toXml case2");
    }

    TEST_OK("TextContent toXml case100");
}
