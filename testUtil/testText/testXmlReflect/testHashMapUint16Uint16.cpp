#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint16.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint16.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataUint16) {
public:
  HashMap<Uint16,Uint16> maps;
  DECLARE_REFLECT_FIELD(HashmapDataUint16,maps)
};

void testHashMapUint16Uint16() {
    while(1) {
      HashMap<Uint16,Uint16> maps = HashMap<Uint16,Uint16>::New();
      maps->put(Uint16::New(1),Uint16::New(10));
      maps->put(Uint16::New(2),Uint16::New(20));
      maps->put(Uint16::New(3),Uint16::New(30));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(maps);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/hashmap_Uint16_Uint16_test1.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/hashmap_Uint16_Uint16_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Uint16,Uint16> maps2 = HashMap<Uint16,Uint16>::New();
      doc2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case1]");
        break;
      }

      auto v1 = maps2->get(Uint16::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case2]");
        break;
      }

      auto v2 = maps2->get(Uint16::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case3]");
        break;
      }

      auto v3 = maps2->get(Uint16::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case4]");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataUint16 data = HashmapDataUint16::New();
      HashMap<Uint16,Uint16> maps = HashMap<Uint16,Uint16>::New();
      maps->put(Uint16::New(1),Uint16::New(10));
      maps->put(Uint16::New(2),Uint16::New(20));
      maps->put(Uint16::New(3),Uint16::New(30));
      data->maps = maps;

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(data);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/hashmap_Uint16_Uint16_test2.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/hashmap_Uint16_Uint16_test2.xml"));
      XmlDocument doc2 = reader->get();

      HashmapDataUint16 data2 = HashmapDataUint16::New();
      doc2->reflectTo(data2);
      HashMap<Uint16,Uint16> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case5]");
        break;
      }

      auto v1 = maps2->get(Uint16::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case6]");
        break;
      }

      auto v2 = maps2->get(Uint16::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case7]");
        break;
      }

      auto v3 = maps2->get(Uint16::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Uint16 Uint16 Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap Uint16 Uint16 Test case100]");
}
