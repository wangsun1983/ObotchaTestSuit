#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Integer.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashmapDataInteger) {
public:
  HashMap<Integer,Integer> maps;
  DECLARE_REFLECT_FIELD(HashmapDataInteger,maps)
};

void testHashMapIntegerInteger() {
    while(1) {
      HashMap<Integer,Integer> maps = HashMap<Integer,Integer>::New();
      maps->put(Integer::New(1),Integer::New(10));
      maps->put(Integer::New(2),Integer::New(20));
      maps->put(Integer::New(3),Integer::New(30));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(maps);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/hashmap_integer_integer_test1.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/hashmap_integer_integer_test1.xml"));
      XmlDocument doc2 = reader->get();

      HashMap<Integer,Integer> maps2 = HashMap<Integer,Integer>::New();
      doc2->reflectTo(maps2);
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case1]");
        break;
      }

      auto v1 = maps2->get(Integer::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case2]");
        break;
      }

      auto v2 = maps2->get(Integer::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case3]");
        break;
      }

      auto v3 = maps2->get(Integer::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case4]");
        break;
      }

      break;
    }

    while(1) {
      HashmapDataInteger data = HashmapDataInteger::New();
      HashMap<Integer,Integer> maps = HashMap<Integer,Integer>::New();
      maps->put(Integer::New(1),Integer::New(10));
      maps->put(Integer::New(2),Integer::New(20));
      maps->put(Integer::New(3),Integer::New(30));
      data->maps = maps;

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(data);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/hashmap_integer_integer_test2.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/hashmap_integer_integer_test2.xml"));
      XmlDocument doc2 = reader->get();

      HashmapDataInteger data2 = HashmapDataInteger::New();
      doc2->reflectTo(data2);
      HashMap<Integer,Integer> maps2 = data2->maps;
      if(maps2->size() != 3) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case5]");
        break;
      }

      auto v1 = maps2->get(Integer::New(1));
      if(v1 == nullptr || v1->toValue() != 10) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case6]");
        break;
      }

      auto v2 = maps2->get(Integer::New(2));
      if(v2 == nullptr || v2->toValue() != 20) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case7]");
        break;
      }

      auto v3 = maps2->get(Integer::New(3));
      if(v3 == nullptr || v3->toValue() != 30) {
        TEST_FAIL("[XmlReflect HashMap Integer Integer Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap Integer Integer Test case100]");
}
