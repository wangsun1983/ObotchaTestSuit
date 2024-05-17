#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int integerDataTest() {
    //String getString(String tag);
    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_01.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case1]");
        break;
      }

      Integer v_int = value->getInteger();
      if(v_int == nullptr || v_int->toValue() != 2147483647) {
        TEST_FAIL("[JsonReader Integer Data Test case1]");
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case2]");
      break;
    }

    //String getString(String tag);
    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_02.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case3]");
        break;
      }

      Integer v_int = value->getInteger();
      if(v_int == nullptr || v_int->toValue() != -2147483648) {
        TEST_FAIL("[JsonReader Integer Data Test case4]");
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case5]");
      break;
    }

    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_03.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case6]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 4294967295) {
        TEST_FAIL("[JsonReader Integer Data Test case7]");
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case8]");
      break;
    }

    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_04.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case9]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 0) {
        TEST_FAIL("[JsonReader Integer Data Test case10]");
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case11]");
      break;
    }

    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_05.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case11]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 1) {
        TEST_FAIL("[JsonReader Integer Data Test case12],v_int is %lld ",v_int->toValue());
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case13]");
      break;
    }

    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_06_64bits.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case14]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 9223372036854775808) {
        TEST_FAIL("[JsonReader Integer Data Test case15],v_int is %llld ",v_int->toValue());
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case16]");
      break;
    }

    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_07_64bits.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case17]");
        break;
      }

      Long v_int = value->getLong();
      if(v_int == nullptr || v_int->toValue() != -9223372036854775808) {
        TEST_FAIL("[JsonReader Integer Data Test case18],v_int is %llld ",v_int->toValue());
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case19]");
      break;
    }

    while(1) {
      JsonReader reader = JsonReader::New()->loadFile(File::New("./test/data/test_integer_08_64bits.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Integer Data Test case20]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 18446744073709551615) {
        TEST_FAIL("[JsonReader Integer Data Test case21],v_int is %llld ",v_int->toValue());
        break;
      }

      TEST_OK("[JsonReader Integer Data Test case22]");
      break;
    }
    return 0;
}
