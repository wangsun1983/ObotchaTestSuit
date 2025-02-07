#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "BlockingQueue.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Integer.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include <vector>
#include "TestLog.hpp"

using namespace obotcha;
DECLARE_CLASS(BaseImportData) {
public:
  int baseData1;

  void dump() {
    TEST_FAIL("[BaseImportData] baseData1 is %d ",baseData1);
  }
  DECLARE_REFLECT_FIELD(BaseImportData,baseData1)
};

DECLARE_CLASS(SubImportData) {
public:
  int subData1;
  long subData2;
  String subData3;
  ArrayList<BaseImportData> subData4;

  void dump() {
      TEST_FAIL("  [SubImportData] subData1 is %d ",subData1);
      TEST_FAIL("  [SubImportData] subData2 is %ld ",subData2);
      TEST_FAIL("  [SubImportData] subData3 is %s ",subData3->toChars());
      TEST_FAIL("  [SubImportData] start dump subData4 ");
      ArrayListIterator<BaseImportData> iterator = subData4->getIterator();
      while(iterator->hasValue()) {
        BaseImportData vv = iterator->getValue();
        vv->dump();
        TEST_FAIL("");
        iterator->next();
      }
      TEST_FAIL("  [SubImportData] finish dump subData4 ");
  }

  DECLARE_REFLECT_FIELD(SubImportData,subData1,subData2,subData3,subData4)
};

DECLARE_CLASS(ImportData){
public:
  int data1;
  long data2;
  SubImportData data3;
  ArrayList<SubImportData> data4;

  void dump() {
    TEST_FAIL("[ImportData] data1 is %d ",data1);
    TEST_FAIL("[ImportData] data2 is %ld ",data2);
    TEST_FAIL("[ImportData] start dump data3 ");
    data3->dump();
    TEST_FAIL("[ImportData] finish dump data3 ");

    TEST_FAIL("[ImportData] start dump data4 ");
    ArrayListIterator<SubImportData> iterator = data4->getIterator();
    while(iterator->hasValue()) {
        SubImportData vv = iterator->getValue();
        vv->dump();
        TEST_FAIL("");
        iterator->next();
    }
    TEST_FAIL("[ImportData] finish dump subData4 ");
  }
  DECLARE_REFLECT_FIELD(ImportData,data1,data2,data3,data4)
};

void testImport() {
  /*
    JsonValue value = JsonValue::New();
    ImportData importData = ImportData::New();
    importData->data1 = 1;
    importData->data2 = 123;

    importData->data3 = SubImportData::New();
    importData->data3->subData1 = 222;
    importData->data3->subData2 = 777;
    importData->data3->subData3 = String::New("hello world");

    importData->data4 = ArrayList<SubImportData>::New();
    SubImportData t1 = SubImportData::New();
    t1->subData1 = 1;
    t1->subData2 = 1111;
    t1->subData3 = String::New("this is one");
    t1->subData4 = ArrayList<BaseImportData>::New();
    BaseImportData tt1 = BaseImportData::New();
    tt1->baseData1 = 1122;
    t1->subData4->add(tt1);

    SubImportData t2 = SubImportData::New();
    t2->subData1 = 2;
    t2->subData2 = 2222;
    t2->subData3 = String::New("this is two");
    t2->subData4 = ArrayList<BaseImportData>::New();
    BaseImportData tt2 = BaseImportData::New();
    tt2->baseData1 = 3344;
    t2->subData4->add(tt2);

    importData->data4->add(t1);
    importData->data4->add(t2);

    value->importFrom(importData);
    JsonWriter writer = JsonWriter::New(String::New("wangslabc.json"));
    writer->write(value);
    writer->close();*/
    JsonReader reader = JsonReader::New()->loadFile(File::New("wangslabc.json"));
    JsonValue value = reader->get();

    ImportData info = ImportData::New();
    value->reflectTo(info);

    //TEST_FAIL("data1 is %d ",info->data1);
    //TEST_FAIL("data2 is %ld ",info->data2);
    //info->dump();
}
