#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Double.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(DoubleList) {
public:
    ArrayList<Double>lists;
    DECLARE_REFLECT_FIELD(DoubleList,lists)
};

DECLARE_CLASS(DoubleList2) {
public:
    ArrayList<Double>list1;
    ArrayList<Double>list2;
    DECLARE_REFLECT_FIELD(DoubleList2,list1,list2)
};

void testArrayListDouble() {
    while(1) {
      ArrayList<Double> list = ArrayList<Double>::New();
      list->add(Double::New(1.1));
      list->add(Double::New(2.2));
      list->add(Double::New(3.3));
      list->add(Double::New(4.4));
      list->add(Double::New(5.5));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(list);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/list_Double_test1.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/list_Double_test1.xml"));
      XmlDocument doc2 = reader->get();

      ArrayList<Double> list2 = ArrayList<Double>::New();
      doc2->reflectTo(list2);

      if(list2->size() != 5) {
        TEST_FAIL("[XmlReflect ArrayList Double Test case1]");
        break;
      }

      if(st(Double)::Compare(list2->get(0)->toValue(),1.1) != 0
        ||st(Double)::Compare(list2->get(1)->toValue(),2.2) != 0
        ||st(Double)::Compare(list2->get(2)->toValue(),3.3) != 0
        ||st(Double)::Compare(list2->get(3)->toValue(),4.4) != 0
        ||st(Double)::Compare(list2->get(4)->toValue(),5.5) != 0) {
          TEST_FAIL("[XmlReflect ArrayList Double Test case2]");
          break;
      }
      break;
    }

    while(1) {
      DoubleList2 list = DoubleList2::New();
      list->list1 = ArrayList<Double>::New();
      list->list2 = ArrayList<Double>::New();

      list->list1->add(Double::New(1.1));
      list->list1->add(Double::New(2.2));
      list->list1->add(Double::New(3.3));
      list->list1->add(Double::New(4.4));
      list->list1->add(Double::New(5.5));

      list->list2->add(Double::New(6.6));
      list->list2->add(Double::New(7.7));
      list->list2->add(Double::New(8.8));
      list->list2->add(Double::New(9.9));
      list->list2->add(Double::New(10.1));

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(list);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/list_Double_test2.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/list_Double_test2.xml"));
      XmlDocument doc2 = reader->get();

      DoubleList2 list2 = DoubleList2::New();
      doc2->reflectTo(list2);

      if(st(Double)::Compare(list2->list1->get(0)->toValue(),1.1) != 0
        ||st(Double)::Compare(list2->list1->get(1)->toValue(),2.2) != 0
        ||st(Double)::Compare(list2->list1->get(2)->toValue(),3.3) != 0
        ||st(Double)::Compare(list2->list1->get(3)->toValue(),4.4) != 0
        ||st(Double)::Compare(list2->list1->get(4)->toValue(),5.5) != 0) {
          TEST_FAIL("[XmlReflect ArrayList Double Test case3]");
          break;
      }

      if(st(Double)::Compare(list2->list2->get(0)->toValue(),6.6) != 0
        ||st(Double)::Compare(list2->list2->get(1)->toValue(),7.7) != 0
        ||st(Double)::Compare(list2->list2->get(2)->toValue(),8.8) != 0
        ||st(Double)::Compare(list2->list2->get(3)->toValue(),9.9) != 0
        ||st(Double)::Compare(list2->list2->get(4)->toValue(),10.1) != 0) {
          TEST_FAIL("[XmlReflect ArrayList Double Test case4]");
          break;
      }
      break;
    }

    TEST_OK("[XmlReflect ArrayList Double Test case100]");
}
