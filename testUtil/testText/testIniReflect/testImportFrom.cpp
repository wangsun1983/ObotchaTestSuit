#include <stdio.h>
#include <unistd.h>


#include "Log.hpp"
#include "TestLog.hpp"
#include "IniValue.hpp"
#include "IniWriter.hpp"
#include "IniReader.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"

using namespace obotcha;

DECLARE_CLASS(ImportDataMember) {
public:
    int data1;
    String data2;
    DECLARE_REFLECT_FIELD(ImportDataMember,data1,data2)
};

DECLARE_CLASS(ImportData) {
public:
    int member1;
    bool member2;
    bool member2_1;
    String member3;
    ImportDataMember member4;
    DECLARE_REFLECT_FIELD(ImportData,member1,member2,member2_1,member3,member4)
};


void testImportFrom() {
    
    ImportData d = ImportData::New();
    d->member1 = 12;
    d->member2 = true;
    d->member2_1 = false;
    
    d->member3 = String::New("hello hello");

    d->member4 = ImportDataMember::New();
    d->member4->data1 =22;
    d->member4->data2 = String::New("world world");

    IniValue v = IniValue::New();
    v->importFrom(d);

    ImportData d2 = ImportData::New();
    v->reflectTo(d2);

    if(d->member1 != d2->member1) {
        TEST_FAIL("IniReflect importFrom case1");
    }

    if(d->member2 != d2->member2) {
        TEST_FAIL("IniReflect importFrom case2");
    }

    if(d->member2_1 != d2->member2_1) {
        TEST_FAIL("IniReflect importFrom case3");
    }

    if(!d->member3->equals(d2->member3)) {
        TEST_FAIL("IniReflect importFrom case4");
    }

    if(d->member4->data1 != d2->member4->data1) {
        TEST_FAIL("IniReflect importFrom case5");
    }

    if(!d->member4->data2->equals(d2->member4->data2)) {
        TEST_FAIL("IniReflect importFrom case6");
    }

    TEST_OK("IniReflect importFrom case100");
}
