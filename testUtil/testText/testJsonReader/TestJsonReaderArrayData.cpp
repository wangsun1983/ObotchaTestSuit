#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int arrayDataTest() {
    //String getString(String tag);
    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_01.json"));
      JsonValue value = reader->get();
      if(value != nullptr && value->size() != 0) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case1] [FAILED],value size is %d ",value->size());
        break;
      }

      TEST_OK("[JsonReader SimpleRead {data test} case5]  ");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_02.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case6]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case7]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case8]");
        break;
      }

      if(value->size() != 1) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case9]");
        break;
      }

      Integer v = value->getIntegerAt(0);
      if(v == nullptr || v->toValue() != 1) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case10]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {data test} case11]  ");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_03.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case12]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case13]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case14]");
        break;
      }

      if(value->size() != 5) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case15]");
        break;
      }

      Integer v0 = value->getIntegerAt(0);
      Integer v1 = value->getIntegerAt(1);
      Integer v2 = value->getIntegerAt(2);
      Integer v3 = value->getIntegerAt(3);
      Integer v4 = value->getIntegerAt(4);
      if(v0 == nullptr || v0->toValue() != 1
        ||v1 == nullptr || v1->toValue() != 2
        ||v2 == nullptr || v2->toValue() != 3
        ||v3 == nullptr || v3->toValue() != 4
        ||v4 == nullptr || v4->toValue() != 5) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case16]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {data test} case17]  ");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_04.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case18]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case19]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case20]");
        break;
      }

      if(value->size() != 4) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case21]");
        break;
      }

      Integer v0 = value->getIntegerAt(0);
      String v1 = value->getStringAt(1);
      Double v2 = value->getDoubleAt(2);
      Integer v3 = value->getIntegerAt(3);
      if(v0 == nullptr || v0->toValue() != 1
        ||v2 == nullptr || v2->toValue() != 12.3
        ||v1 == nullptr || !v1->sameAs("abc")
        ||v3 == nullptr || v3->toValue() != -4) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case22]");
        break;
      }

      if(value->getIntegerAt(4) != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case22_1]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {data test} case23]  ");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_05.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case24]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case25]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case25]");
        break;
      }

      if(value->size() != 99) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case26]");
        break;
      }

      for(int i = 0;i < 99;i++) {
        Integer vv = value->getIntegerAt(i);
        if(vv == nullptr || vv->toValue() != (i+1)) {
          TEST_FAIL("case27 vv is %d,index is %d ",vv->toValue(),i);
          TEST_FAIL("[JsonReader SimpleRead {data test} case27]");
          break;
        }
      }

      TEST_OK("[JsonReader SimpleRead {data test} case28]  ");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_06.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case29]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case30]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case31]");
        break;
      }

      if(value->size() != 4) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case32]");
        break;
      }

      String str1 = value->getStringAt(0);
      String str2 = value->getStringAt(1);
      String str3 = value->getStringAt(2);
      String str4 = value->getStringAt(3);

      if(str1 == nullptr || !str1->sameAs("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")
        ||str2 == nullptr || !str2->sameAs("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")
        ||str3 == nullptr || !str3->sameAs("ccccccccccccccccccccccc")
        ||str4 == nullptr || !str4->sameAs("dddddddddddddddddddddddddddddddddddddddddddddddddddd")) {
          TEST_FAIL("[JsonReader SimpleRead {data test} case33]");
          break;
      }


      TEST_OK("[JsonReader SimpleRead {data test} case28]  ");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_array_07.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case30]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case31]");
        break;
      }

      if(!value->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case32]");
        break;
      }

      if(value->size() != 1) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case33]");
        break;
      }

      JsonValue vv1 = value->getValueAt(0);
      if(!vv1->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case34]");
        break;
      }

      String vv1Value = vv1->getStringAt(0);
      if(vv1Value == nullptr || !vv1Value->sameAs("A")) {
        TEST_FAIL("[JsonReader SimpleRead {data test} case35]");
        break;
      }

      for(int index = 1;index<2120;index++) {
          Integer vInt = vv1->getIntegerAt(index);
          if(vInt->toValue() != (index-1)) {
            TEST_FAIL("[JsonReader SimpleRead {data test} case36]");
            break;
          }
      }

      TEST_OK("[JsonReader SimpleRead {data test} case37]  ");
      break;
    }

    return 0;
}
