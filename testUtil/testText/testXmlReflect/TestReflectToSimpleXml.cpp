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

DECLARE_CLASS(XmlReflectWriteMember) {
public:
  int intData;
  byte byteData;
  double doubleData;
  float floatData;
  long longData;
  String stringData;
  uint8_t uint8Data;
  uint16_t uint16Data;
  uint32_t uint32Data;
  uint64_t uint64Data;
  bool boolData;
  DECLARE_REFLECT_FIELD(XmlReflectWriteMember,intData,byteData,doubleData,
                        floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                        uint64Data,boolData)
};

DECLARE_CLASS(XmlReflectData) {
public:
  XmlReflectWriteMember member1;
  XmlReflectWriteMember member2;
  DECLARE_REFLECT_FIELD(XmlReflectData,member1,member2)
};

void testReflectToSimpleXml() {
  //test1
  while(1) {
    XmlReflectData data = createXmlReflectData();
    data->member1 = createXmlReflectWriteMember();
    data->member2 = createXmlReflectWriteMember();
    data->member1->intData = 1;
    data->member1->byteData = 2;
    data->member1->doubleData = 1.1;
    data->member1->floatData = 2.2;
    data->member1->longData = 3;
    data->member1->stringData = createString("a");
    data->member1->uint8Data = 4;
    data->member1->uint16Data = 5;
    data->member1->uint32Data = 6;
    data->member1->uint64Data = 7;
    data->member1->boolData = false;

    data->member2->intData = 11;
    data->member2->byteData = 12;
    data->member2->doubleData = 11.1;
    data->member2->floatData = 12.2;
    data->member2->longData = 13;
    data->member2->stringData = createString("b");
    data->member2->uint8Data = 14;
    data->member2->uint16Data = 15;
    data->member2->uint32Data = 16;
    data->member2->uint64Data = 17;
    data->member2->boolData = false;

    XmlDocument doc = createXmlDocument();
    doc->importFrom(data);
    XmlWriter writer = createXmlWriter(doc);
    writer->write("output4.xml");

    XmlReader reader = createXmlReader(createFile("output4.xml"));
    XmlDocument doc2 = reader->get();
    XmlReflectData rdata3 = createXmlReflectData();
    doc2->reflectTo(rdata3);

    if(data->member1->intData != rdata3->member1->intData) {
      TEST_FAIL("XmlReflect to xml test1");
      break;
    }

    if(data->member1->byteData != rdata3->member1->byteData) {
      TEST_FAIL("XmlReflect to xml test2,data1 is %d,data2 is %d \n",data->member1->byteData,rdata3->member1->byteData);
      
      break;
    }

    if(data->member1->doubleData != rdata3->member1->doubleData) {
      TEST_FAIL("XmlReflect to xml test3");
      break;
    }

    if(data->member1->floatData != rdata3->member1->floatData) {
      TEST_FAIL("XmlReflect to xml test4");
      break;
    }

    if(data->member1->longData != rdata3->member1->longData) {
      TEST_FAIL("XmlReflect to xml test5");
      break;
    }

    if(!data->member1->stringData->equals(rdata3->member1->stringData)) {
      TEST_FAIL("XmlReflect to xml test6,member string is %s,member2 string is %s \n",data->member1->stringData->toChars(),rdata3->member1->stringData->toChars());
      
      break;
    }

    if(data->member1->uint8Data != rdata3->member1->uint8Data) {
      TEST_FAIL("XmlReflect to xml test7");
      break;
    }

    if(data->member1->uint16Data != rdata3->member1->uint16Data) {
      TEST_FAIL("XmlReflect to xml test8");
      break;
    }

    if(data->member1->uint32Data != rdata3->member1->uint32Data) {
      TEST_FAIL("XmlReflect to xml test9");
      break;
    }

    if(data->member1->uint64Data != rdata3->member1->uint64Data) {
      TEST_FAIL("XmlReflect to xml test10,data1 is %lu,data2 is %lu \n",data->member1->uint64Data,rdata3->member1->uint64Data);
      
      break;
    }

    if(data->member1->boolData != rdata3->member1->boolData) {
      TEST_FAIL("XmlReflect to xml test11");
      break;
    }

    TEST_OK("XmlReflect to xml test12");
    break;
  }
}
