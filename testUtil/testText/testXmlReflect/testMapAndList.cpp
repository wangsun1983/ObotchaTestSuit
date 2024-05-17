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

DECLARE_CLASS(MapListTestData) {
public:
  int data1;
  long data2;
  DECLARE_REFLECT_FIELD(MapListTestData,data1,data2)
};

DECLARE_CLASS(MapListUserData) {
public:
  ArrayList<MapListTestData> lists;
  HashMap<String,MapListTestData> maps;
  DECLARE_REFLECT_FIELD(MapListUserData,lists,maps)
};

void testMapList() {
    while(1) {
      MapListUserData data = MapListUserData::New();
      data->lists = ArrayList<MapListTestData>::New();
      MapListTestData t1 = MapListTestData::New();
      t1->data1 = 1;
      t1->data2 = 2;

      MapListTestData t2 = MapListTestData::New();
      t2->data1 = 3;
      t2->data2 = 4;

      MapListTestData t3 = MapListTestData::New();
      t3->data1 = 5;
      t3->data2 = 6;
      data->lists->add(t1);
      data->lists->add(t2);
      data->lists->add(t3);

      auto maps = HashMap<String,MapListTestData>::New();
      maps->put(String::New("a"),t1);
      maps->put(String::New("b"),t2);
      maps->put(String::New("c"),t3);
      data->maps = maps;

      XmlDocument doc = XmlDocument::New();
      doc->importFrom(data);
      XmlWriter writer = XmlWriter::New(doc);
      writer->write("./tmp/userdata_list_map_test2.xml");
      XmlReader reader = XmlReader::New()->loadFile(File::New("./tmp/userdata_list_map_test2.xml"));
      XmlDocument doc2 = reader->get();

      MapListUserData data2 = MapListUserData::New();
      doc2->reflectTo(data2);

      auto ll = data2->lists;
      if(ll == nullptr || ll->size() != 3) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case1]");
        break;
      }

      if(ll->get(0)->data1 != 1 || ll->get(0)->data2 != 2) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case2]");
        break;
      }

      if(ll->get(1)->data1 != 3 || ll->get(1)->data2 != 4) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case3]");
        break;
      }

      if(ll->get(2)->data1 != 5 || ll->get(2)->data2 != 6) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case4]");
        break;
      }

      auto mm = data2->maps;

      if(mm->size() != 3) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case5]");
        break;
      }

      if(mm->get("a") == nullptr ||mm->get("a")->data1 != 1 ||mm->get("a")->data2 != 2) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case6]");
        break;
      }

      if(mm->get("b") == nullptr ||mm->get("b")->data1 != 3 ||mm->get("b")->data2 != 4) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case7]");
        break;
      }

      if(mm->get("c") == nullptr ||mm->get("c")->data1 != 5 ||mm->get("c")->data2 != 6) {
        TEST_FAIL("[XmlReflect Map And List UserData Test case8]");
        break;
      }

      break;
    }

    TEST_OK("[XmlReflect HashMap UserData Test case100]");
}
