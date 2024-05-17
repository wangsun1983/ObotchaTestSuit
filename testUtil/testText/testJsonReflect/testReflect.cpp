#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Integer.hpp"
#include "JsonReader.hpp"
#include <vector>
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(Address) {
public:
    String street;
    String city;
    String country;
    DECLARE_REFLECT_FIELD(Address,street,city,country)
};

DECLARE_CLASS(Link) {
public:
    String name;
    String url;
    DECLARE_REFLECT_FIELD(Link,name,url);
};

DECLARE_CLASS(PersonInfo) {
public:
    String name;
    String url;
    String page;
    Address address;
    bool isNonProfit;
    ArrayList<Link>links;
    DECLARE_REFLECT_FIELD(PersonInfo,name,url,page,address,isNonProfit,links)
};

void testReflect() {

    JsonReader reader = JsonReader::New()->loadFile(File::New("abc.json"));
    JsonValue value = reader->get();

    PersonInfo info = PersonInfo::New();
    value->reflectTo(info);

    TEST_FAIL("info name is %s ",info->name->toChars());
    TEST_FAIL("info url is %s ",info->url->toChars());
    TEST_FAIL("info page is %s ",info->page->toChars());
    TEST_FAIL("info street is %s ",info->address->street->toChars());
    TEST_FAIL("info city is %s ",info->address->city->toChars());
    TEST_FAIL("info country is %s ",info->address->country->toChars());
    if(info->isNonProfit) {
        TEST_FAIL("info isNonProfit is true ");
    } else {
        TEST_FAIL("info isNonProfit is false ");
    }

    if(info->links != nullptr) {
        TEST_FAIL("size is %d ",info->links->size());
        ArrayListIterator<Link> iterator = info->links->getIterator();
        while(iterator->hasValue()) {
            Link ll = iterator->getValue();
            TEST_FAIL("Link name is %s,url is %s ",ll->name->toChars(),ll->url->toChars());
            iterator->next();
        }
    }
}
