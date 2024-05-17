#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <type_traits>

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "Reflect.hpp"
#include "String.hpp"
#include "Math.hpp"
#include "Field.hpp"
#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ArrayListMember) {
public:
    int intMember;
    bool boolMember;
    uint64_t uint64Member;
    String stringMember;
    DECLARE_REFLECT_FIELD(ArrayListMember,intMember,boolMember,uint64Member,stringMember)
};

DECLARE_CLASS(ReflectArrayListData) {
public:
  ArrayList<ArrayListMember> lists;
  DECLARE_REFLECT_FIELD(ReflectArrayListData,lists)
};

void testReflectToArrayJson() {
  //test1
  while(1) {
    ReflectArrayListData data = ReflectArrayListData::New();
    data->lists = ArrayList<ArrayListMember>::New();

    ArrayListMember m1 = ArrayListMember::New();
    m1->intMember = 1;
    m1->boolMember = true;
    m1->uint64Member = 1;
    m1->stringMember = String::New("1");
    data->lists->add(m1);

    ArrayListMember m2 = ArrayListMember::New();
    m2->intMember = 21;
    m2->boolMember = true;
    m2->uint64Member = 21;
    m2->stringMember = String::New("2");
    data->lists->add(m2);

    ArrayListMember m3 = ArrayListMember::New();
    m3->intMember = 31;
    m3->boolMember = true;
    m3->uint64Member = 31;
    m3->stringMember = String::New("3");
    data->lists->add(m3);

    JsonValue jvalue = JsonValue::New();
    jvalue->importFrom(data);
    JsonWriter jwriter = JsonWriter::New("output2.json");
    jwriter->write(jvalue);

    JsonReader reader = JsonReader::New()->loadFile(File::New("output2.json"));
    JsonValue readValue = reader->get();

    ReflectArrayListData rdata3 = ReflectArrayListData::New();
    readValue->reflectTo(rdata3);

    if(rdata3 == nullptr || rdata3->lists == nullptr || rdata3->lists->size() != 3) {
      TEST_FAIL("Reflect ArrayList To File test1");
      break;
    }

    ArrayListMember r1 = rdata3->lists->get(0);
    if(m1->intMember != r1->intMember) {
      TEST_FAIL("Reflect ArrayList To File test2");
      break;
    }

    if(m1->boolMember != r1->boolMember) {
      TEST_FAIL("Reflect ArrayList To File test2_1");
      break;
    }

    if(m1->uint64Member != r1->uint64Member) {
      TEST_FAIL("Reflect ArrayList To File test3");
      break;
    }

    if(!m1->stringMember->equals(r1->stringMember)) {
      TEST_FAIL("Reflect ArrayList To File test4");
      break;
    }

    ArrayListMember r2 = rdata3->lists->get(1);
    if(m2->intMember != r2->intMember) {
      TEST_FAIL("Reflect ArrayList To File test5");
      break;
    }

    if(m2->boolMember != r2->boolMember) {
      TEST_FAIL("Reflect ArrayList To File test6");
      break;
    }

    if(m2->uint64Member != r2->uint64Member) {
      TEST_FAIL("Reflect ArrayList To File test7");
      break;
    }

    if(!m2->stringMember->equals(r2->stringMember)) {
      TEST_FAIL("Reflect ArrayList To File test8");
      break;
    }

    ArrayListMember r3 = rdata3->lists->get(2);
    if(m3->intMember != r3->intMember) {
      TEST_FAIL("Reflect ArrayList To File test9");
      break;
    }

    if(m3->boolMember != r3->boolMember) {
      TEST_FAIL("Reflect ArrayList To File test10");
      break;
    }

    if(m3->uint64Member != r3->uint64Member) {
      TEST_FAIL("Reflect ArrayList To File test11");
      break;
    }

    if(!m3->stringMember->equals(r3->stringMember)) {
      TEST_FAIL("Reflect ArrayList To File test10");
      break;
    }

    TEST_OK("Reflect ArrayList To File test11");
    break;
  }
}
