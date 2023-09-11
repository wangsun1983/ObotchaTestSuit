#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int stringDataTest() {
    //String getString(String tag);
    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("./test/data/test_string_01.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Data Test case1]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~")) {
        TEST_FAIL("[JsonReader String Data Test case2]");
        break;
      }

      TEST_OK("[JsonReader String Data Test case3]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("./test/data/test_string_02.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Data Test case4]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~")) {
        TEST_FAIL("[JsonReader String Data Test case5]");
        break;
      }

      TEST_OK("[JsonReader String Data Test case6]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("./test/data/test_string_03.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Data Test case7]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("http:\/\/jsoncpp.sourceforge.net\/")) {
        TEST_FAIL("[JsonReader String Data Test case8]");
        break;
      }

      TEST_OK("[JsonReader String Data Test case9]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("./test/data/test_string_04.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Data Test case10]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("\"abc\\def\"")) {
        TEST_FAIL("[JsonReader String Data Test case11]");
        break;
      }

      TEST_OK("[JsonReader String Data Test case12]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("./test/data/test_string_05.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader String Data Test case13]");
        break;
      }

      String v_int = value->getString();
      if(v_int == nullptr || !v_int->sameAs("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\")) {
        TEST_FAIL("[JsonReader String Data Test case14]");
        break;
      }

      TEST_OK("[JsonReader String Data Test case15]");
      break;
    }

    return 0;

}
