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
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(IntegerList) {
public:
    ArrayList<Integer>lists;
    DECLARE_REFLECT_FIELD(IntegerList,lists)
};

DECLARE_CLASS(IntegerList2) {
public:
    ArrayList<Integer>list1;
    ArrayList<Integer>list2;
    DECLARE_REFLECT_FIELD(IntegerList2,list1,list2)
};

void testArrayListInteger() {
    while(1) {
      ArrayList<Integer> list = ArrayList<Integer>::New();
      list->add(Integer::New(1));
      list->add(Integer::New(2));
      list->add(Integer::New(3));
      list->add(Integer::New(4));
      list->add(Integer::New(5));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(list);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/list_Integer_test1.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/list_Integer_test1.xml"));
      XmlDocument doc2 = reader->get();

      ArrayList<Integer> list2 = ArrayList<Integer>::New();
      doc2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[XmlReflect ArrayList Integer Test case1]");
        break;
      }

      if(list2->get(0)->toValue() != 1
        ||list2->get(1)->toValue() != 2
        ||list2->get(2)->toValue() != 3
        ||list2->get(3)->toValue() != 4
        ||list2->get(4)->toValue() != 5) {
          TEST_FAIL("[XmlReflect ArrayList Integer Test case2]");
          break;
      }
      break;
    }

    while(1) {
      IntegerList2 list = IntegerList2::New();
      list->list1 = ArrayList<Integer>::New();
      list->list2 = ArrayList<Integer>::New();

      list->list1->add(Integer::New(1));
      list->list1->add(Integer::New(2));
      list->list1->add(Integer::New(3));
      list->list1->add(Integer::New(4));
      list->list1->add(Integer::New(5));

      list->list2->add(Integer::New(6));
      list->list2->add(Integer::New(7));
      list->list2->add(Integer::New(8));
      list->list2->add(Integer::New(9));
      list->list2->add(Integer::New(10));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(list);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/list_Integer_test2.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/list_Integer_test2.xml"));
      XmlDocument doc2 = reader->get();

      IntegerList2 list2 = IntegerList2::New();
      doc2->reflectTo(list2);

      if(list2->list1->get(0)->toValue() != 1
        ||list2->list1->get(1)->toValue() != 2
        ||list2->list1->get(2)->toValue() != 3
        ||list2->list1->get(3)->toValue() != 4
        ||list2->list1->get(4)->toValue() != 5) {
          TEST_FAIL("[XmlReflect ArrayList Integer Test case3]");
          break;
      }

      if(list2->list2->get(0)->toValue() != 6
        ||list2->list2->get(1)->toValue() != 7
        ||list2->list2->get(2)->toValue() != 8
        ||list2->list2->get(3)->toValue() != 9
        ||list2->list2->get(4)->toValue() != 10) {
          TEST_FAIL("[XmlReflect ArrayList Integer Test case4]");
          break;
      }
      break;
    }

    TEST_OK("[XmlReflect ArrayList Integer Test case100]");
}
