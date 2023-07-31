#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int stringUnicodeDataTest() {
    //String getString(String tag);
    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_string_unicode_01.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Unicode Data Test case1]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("a")) {
        TEST_FAIL("[JsonReader String Unicode Data Test case2]");
        break;
      }

      TEST_OK("[JsonReader String Unicode Data Test case3]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_string_unicode_02.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Unicode Data Test case4]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("¢")) {
        TEST_FAIL("[JsonReader String Unicode Data Test case5]");
        break;
      }

      TEST_OK("[JsonReader String Unicode Data Test case6]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_string_unicode_03.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Unicode Data Test case7]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("€")) {
        TEST_FAIL("[JsonReader String Unicode Data Test case8],v_int is %s ",v_int->toChars());
        break;
      }

      TEST_OK("[JsonReader String Unicode Data Test case9]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_string_unicode_04.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Unicode Data Test case10]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("𝄞")) {
		TEST_FAIL("[JsonReader String Unicode Data Test case11]");
        break;
      }

      TEST_OK("[JsonReader String Unicode Data Test case12]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_string_unicode_05.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Unicode Data Test case13]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("Zażółć gęślą jaźń")) {
        TEST_FAIL("[JsonReader String Unicode Data Test case14]");
        break;
      }

      TEST_OK("[JsonReader String Unicode Data Test case15]");
      break;
    }
    return 0;
}
