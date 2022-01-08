#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint8.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint8.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint8) {
public:
  HashMap<Uint8,Uint8> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint8,maps)
};

void testHashMapUint8Uint8() {
    while(1) {
      HashMap<Uint8,Uint8> maps = createHashMap<Uint8,Uint8>();
      maps->put(createUint8(1),createUint8(10));
      maps->put(createUint8(2),createUint8(20));
      maps->put(createUint8(3),createUint8(30));

      XmlDocument doc = createXmlDocument();
      doc->importFrom(maps);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Uint8_Uint8_test1.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/hashmap_Uint8_Uint8_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Uint8,Uint8> maps2 = createHashMap<Uint8,Uint8>();
      doc2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case1]");
        break;
      }

      auto v1 = maps2->get(createUint8(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case2]");
        break;
      }

      auto v2 = maps2->get(createUint8(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case3]");
        break;
      }

      auto v3 = maps2->get(createUint8(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case4]");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint8 data = createHashmapDataUint8();
      HashMap<Uint8,Uint8> maps = createHashMap<Uint8,Uint8>();
      maps->put(createUint8(1),createUint8(10));
      maps->put(createUint8(2),createUint8(20));
      maps->put(createUint8(3),createUint8(30));
      data->maps = maps;

      XmlDocument doc = createXmlDocument();
      doc->importFrom(data);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Uint8_Uint8_test2.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/hashmap_Uint8_Uint8_test2.xml"));
      XmlDocument doc2 = reader->get();

      HashmapDataUint8 data2 = createHashmapDataUint8();
      doc2->reflectTo(data2);
      HashMap<Uint8,Uint8> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case5]");
        break;
      }

      auto v1 = maps2->get(createUint8(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case6]");
        break;
      }

      auto v2 = maps2->get(createUint8(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case7]");
        break;
      }

      auto v3 = maps2->get(createUint8(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint8 Uint8 Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap Uint8 Uint8 Test case100]");
}
