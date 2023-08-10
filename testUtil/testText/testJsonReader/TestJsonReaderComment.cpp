#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int commentTest() {
    //String getString(String tag);
    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_comment_01.json"));
      JsonValue root = reader->get();
      JsonValue v = root->getValue("test");
      JsonValue vv1 = v->getValueAt(0);
      String vv1_str = vv1->getString("a");
      if(vv1_str == nullptr || !vv1_str->sameAs("aaa")) {
        TEST_FAIL("[JsonReader commonTest case1]");
        break;
      }

      JsonValue vv2 = v->getValueAt(1);
      String vv2_str = vv2->getString("b");
      if(vv2_str == nullptr || !vv2_str->sameAs("bbb")) {
        TEST_FAIL("[JsonReader commonTest case2]");
        break;
      }

      JsonValue vv3 = v->getValueAt(2);
      String vv3_str = vv3->getString("c");
      if(vv3_str == nullptr || !vv3_str->sameAs("ccc")) {
        TEST_FAIL("[JsonReader commonTest case3]");
        break;
      }

      TEST_OK("[JsonReader commonTest case4]");
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader(createFile("./test/data/test_preserve_comment_01.json"));
      JsonValue root = reader->get();
      Integer v1 = root->getInteger("first");
      if(v1 == nullptr || v1->toValue() != 1) {
        TEST_FAIL("[JsonReader commonTest case5]");
        break;
      }

      Integer v2 = root->getInteger("second");
      if(v2 == nullptr || v2->toValue() != 2) {
        TEST_FAIL("[JsonReader commonTest case6]");
        break;
      }

      TEST_OK("[JsonReader commonTest case7]");
      break;
    }

    TEST_OK("[JsonReader commonTest case100]");
    return 0;
}
