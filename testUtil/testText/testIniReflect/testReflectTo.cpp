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

DECLARE_CLASS(SIMPLE1) {
public:
    int data1;
    int data2;
    DECLARE_REFLECT_FIELD(SIMPLE1,data1,data2)
};

DECLARE_CLASS(MEMBER1) {
public:
    int data1;
    int data2;
    DECLARE_REFLECT_FIELD(MEMBER1,data1,data2)
};

DECLARE_CLASS(SIMPLE2) {
public:
    int data1;
    int data2;
    MEMBER1 member;
    DECLARE_REFLECT_FIELD(SIMPLE2,member,data1,data2)
};


DECLARE_CLASS(MEMBER2) {
public:
    bool data1;
    String data2;
    bool data3;
    DECLARE_REFLECT_FIELD(MEMBER2,data1,data2,data3)
};

DECLARE_CLASS(SIMPLE3) {
public:
    int data1;
    int data2;
    MEMBER1 member1;
    MEMBER2 member2;
    DECLARE_REFLECT_FIELD(SIMPLE3,member1,member2,data1,data2)
};

void testReflectTo() {
    //test simple1
    {
        IniReader r = createIniReader(createFile("./simple1.ini"));
        IniValue v = r->parse();
        SIMPLE1 s = createSIMPLE1();
        v->reflectTo(s);

        if(s->data1 != 1 || s->data2 != 2) {
            TEST_FAIL("IniReflect ReflectTo case1,data1 is %d,data2 is %d",s->data1,s->data2);
        }
    }

    //test simple2
    {
        IniReader r = createIniReader(createFile("./simple2.ini"));
        IniValue v = r->parse();
        SIMPLE2 s = createSIMPLE2();
        v->reflectTo(s);

        if(s->data1 != 1 || s->data2 != 2) {
            TEST_FAIL("IniReflect ReflectTo case2,data1 is %d,data2 is %d",s->data1,s->data2);
        }

        if(s->member->data1 != 4 || s->member->data2 != 3) {
            TEST_FAIL("IniReflect ReflectTo case3,data1 is %d,data2 is %d",s->member->data1,s->member->data2);
        }
    }

    //test simple3
    {
        IniReader r = createIniReader(createFile("./simple3.ini"));
        IniValue v = r->parse();
        SIMPLE3 s = createSIMPLE3();
        v->reflectTo(s);

        if(s->data1 != 1 || s->data2 != 2) {
            TEST_FAIL("IniReflect ReflectTo case4,data1 is %d,data2 is %d",s->data1,s->data2);
        }

        if(s->member1->data1 != 4 || s->member1->data2 != 3) {
            TEST_FAIL("IniReflect ReflectTo case5,data1 is %d,data2 is %d",s->member1->data1,s->member1->data2);
        }

        if(!s->member2->data1 || s->member2->data3 || !s->member2->data2->sameAs("hello world")) {
            TEST_FAIL("IniReflect ReflectTo case6,data2 is %s",s->member2->data2->toChars());
        }
    }

    TEST_OK("IniReflect ReflectTo case100");
}
