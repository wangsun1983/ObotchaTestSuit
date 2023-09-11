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
#include "XmlWriter.hpp"
#include "XmlReader.hpp"
#include "XmlDocument.hpp"
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

DECLARE_CLASS(XmlReflectArrayListData) {
public:
  ArrayList<ArrayListMember> lists;
  DECLARE_REFLECT_FIELD(XmlReflectArrayListData,lists)
};

void testReflectToArrayXml() {
  //test1
  while(1) {
    XmlReflectArrayListData data = createXmlReflectArrayListData();
    data->lists = createArrayList<ArrayListMember>();

    ArrayListMember m1 = createArrayListMember();
    m1->intMember = 1;
    m1->boolMember = true;
    m1->uint64Member = 1;
    m1->stringMember = createString("1");
    data->lists->add(m1);

    ArrayListMember m2 = createArrayListMember();
    m2->intMember = 21;
    m2->boolMember = true;
    m2->uint64Member = 21;
    m2->stringMember = createString("2");
    data->lists->add(m2);

    ArrayListMember m3 = createArrayListMember();
    m3->intMember = 31;
    m3->boolMember = true;
    m3->uint64Member = 31;
    m3->stringMember = createString("3");
    data->lists->add(m3);

    XmlDocument doc = createXmlDocument();
    doc->importFrom(data);
    XmlWriter writer = createXmlWriter(doc);
    writer->write("output2.xml");

    XmlReader reader = createXmlReader()->loadFile(createFile("output2.xml"));
    XmlDocument doc2 = reader->get();
    XmlReflectArrayListData rdata3 = createXmlReflectArrayListData();
    doc2->reflectTo(rdata3);

    if(rdata3 == nullptr || rdata3->lists == nullptr || rdata3->lists->size() != 3) {
      TEST_FAIL("XmlReflect ArrayList To File test1");
      break;
    }

    ArrayListMember r1 = rdata3->lists->get(0);
    if(m1->intMember != r1->intMember) {
      TEST_FAIL("XmlReflect ArrayList To File test2,m1->intMember is %d,r1->intMember is %d \n",m1->intMember,r1->intMember);

      break;
    }

    if(m1->boolMember != r1->boolMember) {
      TEST_FAIL("XmlReflect ArrayList To File test2_1,m1->boolMember is %d,r1->boolMember is %d \n",m1->boolMember,r1->boolMember);

      break;
    }

    if(m1->uint64Member != r1->uint64Member) {
      TEST_FAIL("XmlReflect ArrayList To File test3");
      break;
    }

    if(!m1->stringMember->equals(r1->stringMember)) {
      TEST_FAIL("XmlReflect ArrayList To File test4");
      break;
    }

    ArrayListMember r2 = rdata3->lists->get(1);
    if(m2->intMember != r2->intMember) {
      TEST_FAIL("XmlReflect ArrayList To File test5");
      break;
    }

    if(m2->boolMember != r2->boolMember) {
      TEST_FAIL("XmlReflect ArrayList To File test6");
      break;
    }

    if(m2->uint64Member != r2->uint64Member) {
      TEST_FAIL("XmlReflect ArrayList To File test7");
      break;
    }

    if(!m2->stringMember->equals(r2->stringMember)) {
      TEST_FAIL("XmlReflect ArrayList To File test8");
      break;
    }

    ArrayListMember r3 = rdata3->lists->get(2);
    if(m3->intMember != r3->intMember) {
      TEST_FAIL("XmlReflect ArrayList To File test9");
      break;
    }

    if(m3->boolMember != r3->boolMember) {
      TEST_FAIL("XmlReflect ArrayList To File test10");
      break;
    }

    if(m3->uint64Member != r3->uint64Member) {
      TEST_FAIL("XmlReflect ArrayList To File test11");
      break;
    }

    if(!m3->stringMember->equals(r3->stringMember)) {
      TEST_FAIL("XmlReflect ArrayList To File test10");
      break;
    }

    TEST_OK("XmlReflect ArrayList To File test11");
    break;
  }
}
