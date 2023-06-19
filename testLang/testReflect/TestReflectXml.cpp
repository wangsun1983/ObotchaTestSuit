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

DECLARE_CLASS(HashMapXmlValue) {
public:
  int data1;
  int data2;
  DECLARE_REFLECT_FIELD(HashMapXmlValue,data1,data2)
};

DECLARE_CLASS(XmlReflectData) {
public:
  HashMap<String,HashMapXmlValue> map;
  DECLARE_REFLECT_FIELD(XmlReflectData,map)
};

void testReflectToXml() {
  //test1
  while(1) {
    XmlReflectData data = createXmlReflectData();
    data->map = createHashMap<String,HashMapXmlValue>();
    HashMapXmlValue value = createHashMapXmlValue();
    value->data1 = 111;
    value->data2 = 222;

    HashMapXmlValue value2 = createHashMapXmlValue();
    value2->data1 = 333;
    value2->data2 = 444;

    data->map->put(createString("hello"),value);
    data->map->put(createString("hello1"),value2);

    XmlDocument doc = createXmlDocument();
    doc->importFrom(data);
    XmlWriter writer = createXmlWriter(doc);
    writer->write("output_xml_1.xml");

    XmlDocument doc1 = createXmlDocument(createFile("output_xml_1.xml"));
    XmlReflectData data3 = createXmlReflectData();
    doc1->reflectTo(data3);

    HashMapXmlValue v1 = data3->map->get("hello");
    if(v1->data1 != value->data1 || v1->data2 != value->data2) {
      TEST_FAIL("testReflectToXml test1");
    }

    HashMapXmlValue v2 = data3->map->get("hello1");
    if(v2->data1 != value2->data1 || v2->data2 != value2->data2) {
      TEST_FAIL("testReflectToXml test2");
    }
    
    break;
  }
}
