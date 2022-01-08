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

DECLARE_CLASS(NumberXmlReflectData) {
public:
  Integer intData;
  Byte byteData;
  Double doubleData;
  Float floatData;
  Long longData;
  String stringData;
  Uint8 uint8Data;
  Uint16 uint16Data;
  Uint32 uint32Data;
  Uint64 uint64Data;
  Boolean boolData;
  DECLARE_REFLECT_FIELD(NumberXmlReflectData,intData,byteData,doubleData,
                        floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                        uint64Data,boolData)
};

void testReflectNumber() {
  //test1
  while(1) {
      NumberXmlReflectData data = createNumberXmlReflectData();
      data->intData = createInteger(1);
      data->byteData = createByte(1);
      data->doubleData = createDouble(1.1);
      data->floatData = createFloat(2.2);
      data->longData = createLong(3);
      data->stringData = createString("abc");
      data->uint8Data = createUint8(4);
      data->uint16Data = createUint16(5);
      data->uint32Data = createUint32(6);
      data->uint64Data = createUint64(7);
      data->boolData = createBoolean(false);

      XmlDocument doc = createXmlDocument();
      doc->importFrom(data);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/output1.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/output1.xml"));
      XmlDocument doc2 = reader->get();
      NumberXmlReflectData rdata3 = createNumberXmlReflectData();
      doc2->reflectTo(rdata3);

      if(rdata3->intData == nullptr ||data->intData->toValue() != rdata3->intData->toValue()) {
        TEST_FAIL("XmlReflect Number To File test1");
        break;
      }

      if(rdata3->byteData == nullptr ||data->byteData->toValue() != rdata3->byteData->toValue()) {
        TEST_FAIL("XmlReflect Number To File test2");
        break;
      }

      if(rdata3->doubleData == nullptr ||data->doubleData->toValue() != rdata3->doubleData->toValue()) {
        TEST_FAIL("XmlReflect Number To File test3");
        break;
      }

      if(rdata3->floatData == nullptr
        ||st(Math)::compareFloat(data->floatData->toValue(),rdata3->floatData->toValue()) != st(Math)::AlmostEqual) {
        TEST_FAIL("data->floatData is %lf,rdata3->floatData is %lf \n",data->floatData->toValue(),rdata3->floatData->toValue());
        TEST_FAIL("XmlReflect Number To File test4");
        break;
      }

      if(rdata3->longData == nullptr ||data->longData->toValue() != rdata3->longData->toValue()) {
        TEST_FAIL("XmlReflect Number To File test5");
        break;
      }

      if(rdata3->uint8Data == nullptr ||data->uint8Data->toValue() != rdata3->uint8Data->toValue()) {
        TEST_FAIL("data->uint8Data is %d,rdata3->uint8Data is %d \n",data->uint8Data->toValue(),rdata3->uint8Data->toValue());
        TEST_FAIL("XmlReflect Number To File test6");
        break;
      }

      if(rdata3->uint16Data == nullptr ||data->uint16Data->toValue() != rdata3->uint16Data->toValue()) {
        TEST_FAIL("XmlReflect Number To File test7");
        break;
      }

      if(rdata3->uint32Data == nullptr ||data->uint32Data->toValue() != rdata3->uint32Data->toValue()) {
        TEST_FAIL("XmlReflect Number To File test8");
        break;
      }

      if(rdata3->uint64Data == nullptr ||data->uint64Data->toValue() != rdata3->uint64Data->toValue()) {
        TEST_FAIL("XmlReflect Number To File test9");
        break;
      }

      if(rdata3->boolData == nullptr ||data->boolData->toValue() != rdata3->boolData->toValue()) {
        TEST_FAIL("XmlReflect Number To File test10");
        break;
      }

      if(rdata3->stringData == nullptr ||!data->stringData->equals(rdata3->stringData)) {
        TEST_FAIL("XmlReflect Number To File test11");
        break;
      }

      TEST_OK("XmlReflect Number To File test12");
      break;
  }
}
