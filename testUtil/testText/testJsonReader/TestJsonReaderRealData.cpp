#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"
#include "Math.hpp"

using namespace obotcha;

int realDataTest() {
    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_01.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case1]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 8589934592) {
        TEST_FAIL("[JsonReader Real Data Test case2]");
        break;
      }

      TEST_OK("[JsonReader Real Data Test case3]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_02.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case4]");
        break;
      }

      Long v_int = value->getLong();
      if(v_int == nullptr || v_int->toValue() != -4294967295) {
        TEST_FAIL("[JsonReader Real Data Test case5]");
        break;
      }

      TEST_OK("[JsonReader Real Data Test case6]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_03.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case7]");
        break;
      }

      Long v_int = value->getLong();
      if(v_int == nullptr || v_int->toValue() != -4294967295) {
        TEST_FAIL("[JsonReader Real Data Test case8]");
        break;
      }

      TEST_OK("[JsonReader Real Data Test case9]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_04.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case10]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || v_int->toValue() != 1.2345678) {
        TEST_FAIL("[JsonReader Real Data Test case11],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case12]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_05.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case10]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || v_int->toValue() != 1234567.8) {
        TEST_FAIL("[JsonReader Real Data Test case11] [FAILED],v is %lf ",v_int->toValue());
        break;
      }

      TEST_OK("[JsonReader Real Data Test case12]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_06.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case13]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || v_int->toValue() != -1.2345678) {
        TEST_FAIL("[JsonReader Real Data Test case14],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case15]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_07.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case13]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || v_int->toValue() != -1234567.8) {
        TEST_FAIL("[JsonReader Real Data Test case14],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case15]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_07.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case13]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || v_int->toValue() != -1234567.8) {
        TEST_FAIL("[JsonReader Real Data Test case14],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case15]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_08.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case16]");
        break;
      }

      Uint64 v_int = value->getUint64();
      if(v_int == nullptr || v_int->toValue() != 4300000001) {
        TEST_FAIL("[JsonReader Real Data Test case17],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case18]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_09.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case19]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || st(Math)::compareDouble(v_int->toValue(),1.9e+19) != st(Math)::AlmostEqual) {
        TEST_FAIL("[JsonReader Real Data Test case20],v_int is %lf,v2 is %lf ",v_int->toValue(),1.9e+19);
        break;
      }

      TEST_OK("[JsonReader Real Data Test case21]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_10.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case22]");
        break;
      }

      Long v_int = value->getLong();
      if(v_int == nullptr || st(Math)::compareDouble(v_int->toValue(),-2200000001) != st(Math)::AlmostEqual) {
        TEST_FAIL("[JsonReader Real Data Test case23],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case21]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_real_11.json"));
      JsonValue value = reader->get();
      if(value == nullptr) {
        TEST_FAIL("[JsonReader Real Data Test case19]");
        break;
      }

      Double v_int = value->getDouble();
      if(v_int == nullptr || st(Math)::compareDouble(v_int->toValue(),-9.3e+18) != st(Math)::AlmostEqual) {
        TEST_FAIL("[JsonReader Real Data Test case20],v_int is %lf ",v_int->toValue());

        break;
      }

      TEST_OK("[JsonReader Real Data Test case21]");
      break;
    }

    return 0;
}
