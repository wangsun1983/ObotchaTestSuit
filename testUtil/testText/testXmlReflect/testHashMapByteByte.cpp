#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Byte.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Byte.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataByte) {
public:
  HashMap<Byte,Byte> maps;
  DECLARE_REFLECT_FIELD(HashmapDataByte,maps)
};

void testHashMapByteByte() {
    while(1) {
      HashMap<Byte,Byte> maps = createHashMap<Byte,Byte>();
      maps->put(createByte(1),createByte(10));
      maps->put(createByte(2),createByte(20));
      maps->put(createByte(3),createByte(30));

      XmlDocument doc = createXmlDocument();
      doc->importFrom(maps);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Byte_Byte_test1.xml");
      XmlReader reader = createXmlReader()->loadFile(createFile("./tmp/hashmap_Byte_Byte_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Byte,Byte> maps2 = createHashMap<Byte,Byte>();
      doc2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case1]");
        break;
      }

      auto v1 = maps2->get(createByte(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case2]");
        break;
      }

      auto v2 = maps2->get(createByte(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case3]");
        break;
      }

      auto v3 = maps2->get(createByte(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case4]");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataByte data = createHashmapDataByte();
      HashMap<Byte,Byte> maps = createHashMap<Byte,Byte>();
      maps->put(createByte(1),createByte(10));
      maps->put(createByte(2),createByte(20));
      maps->put(createByte(3),createByte(30));
      data->maps = maps;

      XmlDocument doc = createXmlDocument();
      doc->importFrom(data);
      XmlWriter writer = createXmlWriter(doc);
      writer->write("./tmp/hashmap_Byte_Byte_test2.xml");
      XmlReader reader = createXmlReader()->loadFile(createFile("./tmp/hashmap_Byte_Byte_test2.xml"));
      XmlDocument doc2 = reader->get();
      HashmapDataByte data2 = createHashmapDataByte();
      doc2->reflectTo(data2);

      HashMap<Byte,Byte> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case5]");
        break;
      }

      auto v1 = maps2->get(createByte(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case6]");
        break;
      }

      auto v2 = maps2->get(createByte(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case7]");
        break;
      }

      auto v3 = maps2->get(createByte(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Byte Byte Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap Byte Byte Test case100]");
}
