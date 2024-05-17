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
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(Uint16List) {
public:
    ArrayList<Uint16>lists;
    DECLARE_REFLECT_FIELD(Uint16List,lists)
};

DECLARE_CLASS(Uint16List2) {
public:
    ArrayList<Uint16>list1;
    ArrayList<Uint16>list2;
    DECLARE_REFLECT_FIELD(Uint16List2,list1,list2)
};

void testArrayListUint16() {
    while(1) {
      ArrayList<Uint16> list = ArrayList<Uint16>::New();
      list->add(Uint16::New(1));
      list->add(Uint16::New(2));
      list->add(Uint16::New(3));
      list->add(Uint16::New(4));
      list->add(Uint16::New(5));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(list);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/list_Uint16_test1.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/list_Uint16_test1.xml"));
      XmlDocument doc2 = reader->get();
      ArrayList<Uint16> list2 = ArrayList<Uint16>::New();
      doc2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[XmlReflect ArrayList Uint16 Test case1]");
        break;
      }

      if(list2->get(0)->toValue() != 1
        ||list2->get(1)->toValue() != 2
        ||list2->get(2)->toValue() != 3
        ||list2->get(3)->toValue() != 4
        ||list2->get(4)->toValue() != 5) {
          TEST_FAIL("[XmlReflect ArrayList Uint16 Test case2]");
          break;
      }
      break;
    }

    while(1) {
      Uint16List2 list = Uint16List2::New();
      list->list1 = ArrayList<Uint16>::New();
      list->list2 = ArrayList<Uint16>::New();

      list->list1->add(Uint16::New(1));
      list->list1->add(Uint16::New(2));
      list->list1->add(Uint16::New(3));
      list->list1->add(Uint16::New(4));
      list->list1->add(Uint16::New(5));

      list->list2->add(Uint16::New(6));
      list->list2->add(Uint16::New(7));
      list->list2->add(Uint16::New(8));
      list->list2->add(Uint16::New(9));
      list->list2->add(Uint16::New(10));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(list);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/list_Uint16_test2.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/list_Uint16_test2.xml"));
      XmlDocument doc2 = reader->get();

      Uint16List2 list2 = Uint16List2::New();
      doc2->reflectTo(list2);

      if(list2->list1->get(0)->toValue() != 1
        ||list2->list1->get(1)->toValue() != 2
        ||list2->list1->get(2)->toValue() != 3
        ||list2->list1->get(3)->toValue() != 4
        ||list2->list1->get(4)->toValue() != 5) {
          TEST_FAIL("[XmlReflect ArrayList Uint16 Test case3]");
          break;
      }

      if(list2->list2->get(0)->toValue() != 6
        ||list2->list2->get(1)->toValue() != 7
        ||list2->list2->get(2)->toValue() != 8
        ||list2->list2->get(3)->toValue() != 9
        ||list2->list2->get(4)->toValue() != 10) {
          TEST_FAIL("[XmlReflect ArrayList Uint16 Test case4]");
          break;
      }
      break;
    }

    TEST_OK("[XmlReflect ArrayList Uint16 Test case100]");
}
