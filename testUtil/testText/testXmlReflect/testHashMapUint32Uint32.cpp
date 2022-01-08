#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint32.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint32.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint32) {
public:
  HashMap<Uint32,Uint32> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint32,maps)
};

void testHashMapUint32Uint32() {
    while(1) {
      HashMap<Uint32,Uint32> maps = createHashMap<Uint32,Uint32>();
      maps->put(createUint32(1),createUint32(10));
      maps->put(createUint32(2),createUint32(20));
      maps->put(createUint32(3),createUint32(30));

      XmlDocument doc = createXmlDocument();
      doc->importFrom(maps);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Uint32_Uint32_test1.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/hashmap_Uint32_Uint32_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Uint32,Uint32> maps2 = createHashMap<Uint32,Uint32>();
      doc2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case1]");
        break;
      }

      auto v1 = maps2->get(createUint32(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case2]");
        break;
      }

      auto v2 = maps2->get(createUint32(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case3]");
        break;
      }

      auto v3 = maps2->get(createUint32(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case4]");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint32 data = createHashmapDataUint32();
      HashMap<Uint32,Uint32> maps = createHashMap<Uint32,Uint32>();
      maps->put(createUint32(1),createUint32(10));
      maps->put(createUint32(2),createUint32(20));
      maps->put(createUint32(3),createUint32(30));
      data->maps = maps;

      XmlDocument doc = createXmlDocument();
      doc->importFrom(data);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Uint32_Uint32_test2.xml");
      XmlReader reader = createXmlReader(createFile("./tmp/hashmap_Uint32_Uint32_test2.xml"));
      XmlDocument doc2 = reader->get();

      HashmapDataUint32 data2 = createHashmapDataUint32();
      doc2->reflectTo(data2);
      HashMap<Uint32,Uint32> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case5]");
        break;
      }

      auto v1 = maps2->get(createUint32(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case6]");
        break;
      }

      auto v2 = maps2->get(createUint32(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case7]");
        break;
      }

      auto v3 = maps2->get(createUint32(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint32 Uint32 Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap Uint32 Uint32 Test case100]");
}
