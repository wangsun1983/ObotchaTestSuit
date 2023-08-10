#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int basicDataTest() {
    //String getString(String tag);
    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_01.json"));
      JsonValue value = reader->get();
      Integer v = value->getInteger();
      if(v == nullptr || v->toValue() != 123456789) {
        TEST_FAIL("[JsonReader basicDataTest case1]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case2]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_02.json"));
      JsonValue value = reader->get();
      Integer v = value->getInteger();
      if(v == nullptr || v->toValue() != -123456789) {
        TEST_FAIL("[JsonReader basicDataTest case3]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case4]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_03.json"));
      JsonValue value = reader->get();
      Double v = value->getDouble();
      if(v == nullptr || v->toValue() != 1.2345678) {
        TEST_FAIL("[JsonReader basicDataTest case5]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case6]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_04.json"));
      JsonValue value = reader->get();
      String v = value->getString();
      if(v == nullptr || !v->sameAs("abcdef")) {
        TEST_FAIL("[JsonReader basicDataTest case7]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case8]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_05.json"));
      JsonValue value = reader->get();
      if(value != nullptr) {
        TEST_FAIL("[JsonReader basicDataTest case9]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case11]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_06.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader basicDataTest case12]");
        break;
      }

      Boolean b = value->getBoolean();
      if(b == nullptr || !b->toValue()) {
        TEST_FAIL("[JsonReader basicDataTest case13]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case14]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_07.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader basicDataTest case15]");
        break;
      }

      Boolean b = value->getBoolean();
      if(b == nullptr || b->toValue()) {
        TEST_FAIL("[JsonReader basicDataTest case16]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case17]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_08.json"));
      JsonValue value = reader->get();
      if(value != nullptr) {
        TEST_FAIL("[JsonReader basicDataTest case18]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case20]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_basic_09.json"));
      JsonValue value = reader->get();
      if(value != nullptr) {
        TEST_FAIL("[JsonReader basicDataTest case21]");
        break;
      }

      TEST_OK("[JsonReader basicDataTest case23]");
      break;
    }

    TEST_OK("[JsonReader basicDataTest case24]");
    return 0;
}
