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

DECLARE_CLASS(SaveDataMember) {
public:
    int data1;
    String data2;
    DECLARE_REFLECT_FIELD(SaveDataMember,data1,data2)
};

DECLARE_CLASS(SaveData) {
public:
    int member1;
    bool member2;
    bool member2_1;
    String member3;
    SaveDataMember member4;
    DECLARE_REFLECT_FIELD(SaveData,member1,member2,member2_1,member3,member4)
};


void testSaveFile() {
    
    SaveData d = SaveData::New();
    d->member1 = 12;
    d->member2 = true;
    d->member2_1 = false;
    
    d->member3 = String::New("hello hello");

    d->member4 = SaveDataMember::New();
    d->member4->data1 =22;
    d->member4->data2 = String::New("world world");

    IniValue v = IniValue::New();
    v->importFrom(d);

    IniWriter w = IniWriter::New(File::New("./tmp/save.ini"));
    w->write(v);

    IniReader reader = IniReader::New()->loadFile(File::New("./tmp/save.ini"));
    auto v2 = reader->get();

    SaveData d2 = SaveData::New();
    v2->reflectTo(d2);

    if(d->member1 != d2->member1) {
        TEST_FAIL("IniReflect savefile case1");
    }

    if(d->member2 != d2->member2) {
        TEST_FAIL("IniReflect savefile case2");
    }

    if(d->member2_1 != d2->member2_1) {
        TEST_FAIL("IniReflect savefile case3");
    }

    if(!d->member3->equals(d2->member3)) {
        TEST_FAIL("IniReflect savefile case4");
    }

    if(d->member4->data1 != d2->member4->data1) {
        TEST_FAIL("IniReflect savefile case5");
    }

    if(!d->member4->data2->equals(d2->member4->data2)) {
        TEST_FAIL("IniReflect savefile case6");
    }

    TEST_OK("IniReflect savefile case100");
}
