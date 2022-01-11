#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int objectDataTest() {
    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_object_01.json"));
      JsonValue value = reader->get();
      if(value != nullptr) {
        TEST_FAIL("[JsonReader Object Data Test case1]");
        break;
      }

      JsonValue v = value->getValue(0);
      if(v != nullptr) {
        TEST_FAIL("[JsonReader Object Data Test case1]");
        break;
      }

      TEST_OK("[JsonReader Object Data Test case2]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_object_02.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Object Data Test case3]");
        break;
      }

      Integer v = value->getInteger("count");
      if(v == nullptr || v->toValue() != 1234) {
        TEST_FAIL("[JsonReader Object Data Test case4]");
        break;
      }

      TEST_OK("[JsonReader Object Data Test case5]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_object_03.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Object Data Test case3]");
        break;
      }

      Integer v = value->getInteger("count");
      if(v == nullptr || v->toValue() != 1234) {
        TEST_FAIL("[JsonReader Object Data Test case4]");
        break;
      }

      String v2 = value->getString("name");
      if(v2 == nullptr || !v2->equals("test")) {
        TEST_FAIL("[JsonReader Object Data Test case5]");
        break;
      }

      String v3 = value->getString("attribute");
      if(v3 == nullptr || !v3->equals("random")) {
        TEST_FAIL("[JsonReader Object Data Test case6]");
        break;
      }

      TEST_OK("[JsonReader Object Data Test case5]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_object_04.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Object Data Test case6]");
        break;
      }

      String v2 = value->getString("");
      if(v2 == nullptr || !v2->equals("1234")) {
        TEST_FAIL("[JsonReader Object Data Test case7]");
        break;
      }

      TEST_OK("[JsonReader Object Data Test case8]");
      break;
    }
    return 0;
}
