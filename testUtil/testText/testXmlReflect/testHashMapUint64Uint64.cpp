#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint64.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint64.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint64) {
public:
  HashMap<Uint64,Uint64> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint64,maps)
};

void testHashMapUint64Uint64() {
    while(1) {
      HashMap<Uint64,Uint64> maps = createHashMap<Uint64,Uint64>();
      maps->put(createUint64(1),createUint64(10));
      maps->put(createUint64(2),createUint64(20));
      maps->put(createUint64(3),createUint64(30));

      XmlDocument doc = createXmlDocument();
      doc->importFrom(maps);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Uint64_Uint64_test1.xml");
      XmlReader reader = createXmlReader()->loadFile(createFile("./tmp/hashmap_Uint64_Uint64_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Uint64,Uint64> maps2 = createHashMap<Uint64,Uint64>();
      doc2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case1]");
        break;
      }

      auto v1 = maps2->get(createUint64(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case2]");
        break;
      }

      auto v2 = maps2->get(createUint64(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case3]");
        break;
      }

      auto v3 = maps2->get(createUint64(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case4]");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint64 data = createHashmapDataUint64();
      HashMap<Uint64,Uint64> maps = createHashMap<Uint64,Uint64>();
      maps->put(createUint64(1),createUint64(10));
      maps->put(createUint64(2),createUint64(20));
      maps->put(createUint64(3),createUint64(30));
      data->maps = maps;

      XmlDocument doc = createXmlDocument();
      doc->importFrom(data);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Uint64_Uint64_test2.xml");
      XmlReader reader = createXmlReader()->loadFile(createFile("./tmp/hashmap_Uint64_Uint64_test2.xml"));
      XmlDocument doc2 = reader->get();

      HashmapDataUint64 data2 = createHashmapDataUint64();
      doc2->reflectTo(data2);
      HashMap<Uint64,Uint64> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case5]");
        break;
      }

      auto v1 = maps2->get(createUint64(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case6]");
        break;
      }

      auto v2 = maps2->get(createUint64(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case7]");
        break;
      }

      auto v3 = maps2->get(createUint64(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint64 Uint64 Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap Uint64 Uint64 Test case100]");
}
