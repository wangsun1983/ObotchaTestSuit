#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <type_traits>

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "Reflect.hpp"
#include "String.hpp"
#include "Math.hpp"
#include "Field.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ArrayDataLLL2) {
public:
  int intData;
  byte byteData;
  double doubleData;
  float floatData;
  long longData;
  String stringData;
  uint8_t uint8Data;
  uint16_t uint16Data;
  uint32_t uint32Data;
  uint64_t uint64Data;
  bool boolData;
  DECLARE_REFLECT_FIELD(ArrayDataLLL2,intData,byteData,doubleData,
                        floatData,longData,stringData,uint8Data,uint16Data,uint32Data,
                        uint64Data,boolData)
};

DECLARE_CLASS(ListCollection2) {
public:
  ArrayList<ArrayDataLLL2> mylist;
  DECLARE_REFLECT_FIELD(ListCollection2,mylist);
};

void testReflectArrayListFieldWrite() {
    //test1
    while(1) {
      ListCollection2 collection = createListCollection2();
      Field arrayField = collection->getField("mylist");
      arrayField->createObject();
      Object data1 = collection->getField("mylist")->createListItemObject();

      Field f = data1->getField("intData");
      f->setValue(1);
      f = data1->getField("byteData");
      f->setValue(2);

      f = data1->getField("doubleData");
      f->setValue(1.1);

      f = data1->getField("floatData");
      f->setValue(2.2f);

      f = data1->getField("longData");
      f->setValue(3);

      f = data1->getField("stringData");
      f->setValue(createString("a"));

      f = data1->getField("uint8Data");
      f->setValue(4);

      f = data1->getField("uint16Data");
      f->setValue(5);

      f = data1->getField("uint32Data");
      f->setValue(6);

      f = data1->getField("uint64Data");
      f->setValue(7);

      f = data1->getField("boolData");
      f->setValue(false);
      collection->getField("mylist")->addListItemObject(data1);
      //data2
      Object data2 = collection->getField("mylist")->createListItemObject();
      f = data2->getField("intData");
      f->setValue(11);

      f = data2->getField("byteData");
      f->setValue(12);

      f = data2->getField("doubleData");
      f->setValue(11.1);

      f = data2->getField("floatData");
      f->setValue(12.2f);

      f = data2->getField("longData");
      f->setValue(13);

      f = data2->getField("stringData");
      f->setValue(createString("b"));

      f = data2->getField("uint8Data");
      f->setValue(14);

      f = data2->getField("uint16Data");
      f->setValue(15);

      f = data2->getField("uint32Data");
      f->setValue(16);

      f = data2->getField("uint64Data");
      f->setValue(17);

      f = data2->getField("boolData");
      f->setValue(false);
      collection->getField("mylist")->addListItemObject(data2);

      if(collection->mylist->size() != 2) {
        TEST_FAIL("Reflect ArrayList Field Write test1-------[FAIL]");
        break;
      }

      ArrayDataLLL2 d1 = collection->mylist->get(0);
      if(d1->intData != 1) {
        TEST_FAIL("Reflect ArrayList Field Write test1_1-------[FAIL] \n");
        break;
      }

      if(d1->byteData != 2) {
        TEST_FAIL("Reflect ArrayList Field Write test2-------[FAIL] \n");
        break;
      }

      if(d1->doubleData != 1.1) {
        TEST_FAIL("Reflect ArrayList Field Write test3-------[FAIL] \n");
        break;
      }

      if(st(Float)::Compare(d1->floatData,2.2) != 0) {
        TEST_FAIL("Reflect ArrayList Field Write test4-------[FAIL] \n");
        break;
      }

      if(d1->longData != 3) {
        TEST_FAIL("Reflect ArrayList Field Write test5-------[FAIL] \n");
        break;
      }

      if(!d1->stringData->sameAs("a")) {
        TEST_FAIL("Reflect ArrayList Field Write test6-------[FAIL] \n");
        break;
      }

      if(d1->uint8Data != 4) {
        TEST_FAIL("Reflect ArrayList Field Write test7-------[FAIL] \n");
        break;
      }

      if(d1->uint16Data != 5) {
        TEST_FAIL("Reflect ArrayList Field Write test8-------[FAIL] \n");
        break;
      }

      if(d1->uint32Data != 6) {
        TEST_FAIL("Reflect ArrayList Field Write test9-------[FAIL] \n");
        break;
      }

      if(d1->uint64Data != 7) {
        TEST_FAIL("Reflect ArrayList Field Write test10-------[FAIL] \n");
        break;
      }

      if(d1->boolData) {
        TEST_FAIL("Reflect ArrayList Field Write test11-------[FAIL] \n");
        break;
      }

      ArrayDataLLL2 d2 = collection->mylist->get(1);
      if(d2->intData != 11) {
        TEST_FAIL("Reflect ArrayList Field Write test12-------[FAIL] \n");
        break;
      }

      if(d2->byteData != 12) {
        TEST_FAIL("Reflect ArrayList Field Write test13-------[FAIL] \n");
        break;
      }

      if(d2->doubleData != 11.1) {
        TEST_FAIL("Reflect ArrayList Field Write test14-------[FAIL] \n");
        break;
      }

      if(st(Float)::Compare(d2->floatData,12.2) != 0) {
        TEST_FAIL("Reflect ArrayList Field Write test15-------[FAIL] \n");
        break;
      }

      if(d2->longData != 13) {
        TEST_FAIL("Reflect ArrayList Field Write test16-------[FAIL] \n");
        break;
      }

      if(!d2->stringData->sameAs("b")) {
        TEST_FAIL("Reflect ArrayList Field Write test17-------[FAIL] \n");
        break;
      }

      if(d2->uint8Data != 14) {
        TEST_FAIL("Reflect ArrayList Field Write test18-------[FAIL] \n");
        break;
      }

      if(d2->uint16Data != 15) {
        TEST_FAIL("Reflect ArrayList Field Write test19-------[FAIL] \n");
        break;
      }

      if(d2->uint32Data != 16) {
        TEST_FAIL("Reflect ArrayList Field Write test20-------[FAIL] \n");
        break;
      }

      if(d2->uint64Data != 17) {
        TEST_FAIL("Reflect ArrayList Field Write test21-------[FAIL] \n");
        break;
      }

      if(d2->boolData) {
        TEST_FAIL("Reflect ArrayList Field Write test22-------[FAIL] \n");
        break;
      }

      TEST_OK("Reflect ArrayList Field Write test23");
      break;
    }
}
