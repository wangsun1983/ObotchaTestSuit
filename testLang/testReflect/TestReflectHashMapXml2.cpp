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
#include "XmlDocument.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashMapXmlValue2) {
public:
  int data1;
  int data2;
  DECLARE_REFLECT_FIELD(HashMapXmlValue2,data1,data2)
};

DECLARE_CLASS(XmlReflectData2) {
public:
  HashMap<String,HashMap<String,HashMapXmlValue2>> map;
  DECLARE_REFLECT_FIELD(XmlReflectData2,map)
};

void testReflectHashMapXml2() {
  //test1
  while(1) {
    XmlReflectData2 data2 = XmlReflectData2::New();
    data2->map = HashMap<String,HashMap<String,HashMapXmlValue2>>::New();

    HashMap<String,HashMapXmlValue2> maps = HashMap<String,HashMapXmlValue2>::New();
    HashMapXmlValue2 value1 = HashMapXmlValue2::New();
    value1->data1 = 1;
    value1->data2 = 2;

    HashMapXmlValue2 value2 = HashMapXmlValue2::New();
    value2->data1 = 3;
    value2->data2 = 4;

    HashMapXmlValue2 value3 = HashMapXmlValue2::New();
    value3->data1 = 5;
    value3->data2 = 6;

    maps->put(String::New("tag1"),value1);
    maps->put(String::New("tag2"),value2);
    maps->put(String::New("tag3"),value3);

    HashMap<String,HashMapXmlValue2> maps2 = HashMap<String,HashMapXmlValue2>::New();
    maps2->put(String::New("tag2"),value2);
    maps2->put(String::New("tag3"),value3);

    data2->map->put(String::New("content1"),maps);
    data2->map->put(String::New("content2"),maps2);

    XmlDocument doc = XmlDocument::New();
    doc->importFrom(data2);
    XmlWriter writer = XmlWriter::New(doc);
    writer->write("output_xml_5.xml");

    XmlDocument doc1 = XmlDocument::New(File::New("output_xml_5.xml"));
    XmlReflectData2 data3 = XmlReflectData2::New();
    doc1->reflectTo(data3);
    if(data3->map == nullptr || data3->map->size() != 2) {
      TEST_FAIL("ReflectHashMapXml2 test2");
      break;
    }

    HashMap<String,HashMapXmlValue2> map3_1 = data3->map->get(String::New("content1"));
    if(map3_1 == nullptr || map3_1->size() != 3) {
      TEST_FAIL("ReflectHashMapXml2 test3");
      break;
    }

    HashMapXmlValue2 value3_1 = map3_1->get(String::New("tag1"));
    if(value3_1 == nullptr || value3_1->data1 != 1 || value3_1->data2 != 2) {
      TEST_FAIL("ReflectHashMapXml2 test3_1");
      break;
    }

    HashMapXmlValue2 value3_2 = map3_1->get(String::New("tag2"));
    if(value3_2 == nullptr || value3_2->data1 != 3 || value3_2->data2 != 4) {
      TEST_FAIL("ReflectHashMapXml2 test4");
      break;
    }

    HashMapXmlValue2 value3_3 = map3_1->get(String::New("tag3"));
    if(value3_3 == nullptr || value3_3->data1 != 5 || value3_3->data2 != 6) {
      TEST_FAIL("ReflectHashMapXml2 test5");
      break;
    }

    HashMap<String,HashMapXmlValue2> map3_2 = data3->map->get(String::New("content2"));
    if(map3_2 == nullptr || map3_2->size() != 2) {
      TEST_FAIL("ReflectHashMapXml2 test6");
      break;
    }

    HashMapXmlValue2 value4_1 = map3_2->get(String::New("tag2"));
    if(value4_1 == nullptr || value4_1->data1 != 3 || value4_1->data2 != 4) {
      TEST_FAIL("ReflectHashMapXml2 test7");
      break;
    }

    HashMapXmlValue2 value4_2 = map3_2->get(String::New("tag3"));
    if(value4_2 == nullptr || value4_2->data1 != 5 || value4_2->data2 != 6) {
      TEST_FAIL("ReflectHashMapXml2 test8");
      break;
    }

    TEST_OK("ReflectHashMapXml2 test100");
    break;
  }
}
