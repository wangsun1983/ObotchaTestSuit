#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

int basetest() {
    JsonReader reader = createJsonReader()->loadFile(createFile("abc.json"));
    JsonValue value = reader->get();

    //String getString(String tag);
    while(1) {
        Integer v1 = value->getInteger("a");
        if(v1->toValue() != 1) {
          TEST_FAIL("[JsonReader SimpleRead {getString()} case1]");
          break;
        }

        Integer v2 = value->getInteger("b");
        if(v2 ==nullptr || v2->toValue() != 2) {
          TEST_FAIL("[JsonReader SimpleRead {getInteger()} case7]");
          break;
        }

        String str1 = value->getString("c");
        if(str1 == nullptr || !str1->sameAs("nihao")) {
          TEST_FAIL("[JsonReader SimpleRead {getString()} case8]");
          break;
        }

        JsonValue arr3 = value->getValue("arr2");
        JsonValue vv1 = arr3->getValueAt(0);
        String strvv1 = vv1->getString("vv");
        Integer intvv1 = vv1->getInteger("v1");
        if(strvv1 == nullptr || !strvv1->sameAs("v1")
           ||intvv1 == nullptr || intvv1->toValue() != 1) {
             TEST_FAIL("[JsonReader SimpleRead {getValue()} case9]");
             break;
        }

        JsonValue vv2 = arr3->getValueAt(1);
        String strvv2 = vv2->getString("vv");
        Integer intvv2 = vv2->getInteger("v1");
        if(strvv2 == nullptr || !strvv2->sameAs("v2")
           ||intvv2 == nullptr || intvv2->toValue() != 2) {
             TEST_FAIL("[JsonReader SimpleRead {getValue()} case10]");
             break;
        }

        Boolean b1 = value->getBoolean("ret");
        Boolean b2 = value->getBoolean("ret2");
        if(b1 == nullptr || b2 == nullptr
          || b1->toValue() != true || b2->toValue() != false) {
            TEST_FAIL("[JsonReader SimpleRead {getValue()} case10]");
            break;
        }

        TEST_OK("[JsonReader SimpleRead {getString()} case9]");
        break;
    }

    //bool isInt();
    while(1) {
      JsonValue v1 = value->getValue("a");
      if(!v1->isInt()) {
        TEST_FAIL("[JsonReader SimpleRead {isInt()} case1]");
        break;
      }

      JsonValue v2 = value->getValue("arr");
      if(v2->isInt()) {
        TEST_FAIL("[JsonReader SimpleRead {isInt()} case2]");
        break;
      }
      TEST_OK("[JsonReader SimpleRead {isInt()} case3]");
      break;
    }

    //bool isBool();
    while(1) {
      JsonValue v1 = value->getValue("ret");
      if(!v1->isBool()) {
        TEST_FAIL("[JsonReader SimpleRead {isBool()} case1]");
        break;
      }

      JsonValue v2 = value->getValue("arr");
      if(v2->isBool()) {
        TEST_FAIL("[JsonReader SimpleRead {isBool()} case2]");
        break;
      }
      TEST_OK("[JsonReader SimpleRead {isBool()} case3]");
      break;
    }

    //bool isString();
    while(1) {
      JsonValue v1 = value->getValue("c");
      if(!v1->isString()) {
        TEST_FAIL("[JsonReader SimpleRead {isString()} case1]");
        break;
      }

      JsonValue v2 = value->getValue("arr");
      if(v2->isString()) {
        TEST_FAIL("[JsonReader SimpleRead {isString()} case2]");
        break;
      }
      TEST_OK("[JsonReader SimpleRead {isString()} case3]");
      break;
    }

    //bool isDouble();
    while(1) {
      JsonValue v1 = value->getValue("b");
      if(!v1->isDouble()) {
        TEST_FAIL("[JsonReader SimpleRead {isDouble()} case1]");
        break;
      }

      JsonValue v2 = value->getValue("arr");
      if(v2->isDouble()) {
        TEST_FAIL("[JsonReader SimpleRead {isDouble()} case2]");
        break;
      }
      TEST_OK("[JsonReader SimpleRead {isDouble()} case3]");
      break;
    }

    //bool isArray();
    while(1) {
      JsonValue v1 = value->getValue("arr2");
      if(!v1->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {isArray()} case1]");
        break;
      }

      JsonValue v2 = value->getValue(S("a"));
      if(v2->isArray()) {
        TEST_FAIL("[JsonReader SimpleRead {isArray()} case2]");
        break;
      }
      TEST_OK("[JsonReader SimpleRead {isArray()} case3]");
      break;
    }

    //void put(String tag,String value);
    while(1) {
      value->put(S("test1"),createString("test1"));

      String test1 = value->getString("test1");
      if(test1 == nullptr || !test1->sameAs("test1")) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case1]");
        break;
      }

      value->put(S("test2"),nullptr);
      String test2 = value->getString("test2");
      if(test2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case2]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case3]");
      break;
    }

    //void put(String tag,char *value);
    while(1) {
      value->put(S("test3"),(char *)"test3");

      String test1 = value->getString("test3");
      if(test1 == nullptr || !test1->sameAs("test3")) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case4]");
        break;
      }

      value->put(S("test4"),(char *)nullptr);
      String test2 = value->getString("test4");
      if(test2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case5]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case6]");
      break;
    }

    //void put(String tag,std::string value);
    while(1) {
      std::string t = "test5";
      value->put(S("test5"),t);

      String test1 = value->getString("test5");
      if(test1 == nullptr || !test1->sameAs("test5")) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case7]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case8]");
      break;
    }

    //void put(String tag,Integer value);
    while(1) {
      value->put(S("int1"),createInteger(1));
      Integer test1 = value->getInteger("int1");

      if(test1 == nullptr || test1->toValue() != 1) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case9]");
        break;
      }

      Integer int2;
      value->put(S("int2"),int2);
      Integer test2 = value->getInteger("int2");
      if(test2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case10]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case11]");
      break;
    }

    //void put(String tag,int value);
    while(1) {
      value->put(S("int2"),2);
      Integer test1 = value->getInteger("int2");

      if(test1 == nullptr || test1->toValue() != 2) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case12]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case13]");
      break;
    }

    //void put(String tag,Boolean value);
    while(1) {
      value->put(S("bool1"),createBoolean(true));
      Boolean test1 = value->getBoolean("bool1");

      if(test1 == nullptr || test1->toValue() != true) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case14]");
        break;
      }

      Boolean int2;
      value->put(S("bool2"),int2);
      Boolean test2 = value->getBoolean("bool2");
      if(test2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case15]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case16]");
      break;
    }

    //void put(String tag,bool value);
    while(1) {
      value->put(S("bool3"),true);
      Boolean test1 = value->getBoolean("bool3");

      if(test1 == nullptr || test1->toValue() != true) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case17]");
        break;
      }
      TEST_OK("[JsonReader SimpleRead {put()} case18]");
      break;
    }

    //void put(String tag,Double value);
    while(1) {
      value->put(S("double1"),createDouble(1.1));
      Double test1 = value->getDouble("double1");

      if(test1 == nullptr || test1->toValue() != 1.1) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case19]");
        break;
      }

      Double int2;
      value->put(S("double2"),int2);
      Double test2 = value->getDouble("double2");
      if(test2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case20]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case21]");
      break;
    }

    //void put(String tag,double value);
    while(1) {
      value->put(S("double3"),1.1);
      Double test1 = value->getDouble("double3");

      if(test1 == nullptr || test1->toValue() != 1.1) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case22]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case23]");
      break;
    }

    //put(sp<_JsonValue> value);
    while(1) {
      //create a array attr
      JsonValue array = createJsonValue();
      array->append((char *)"abc1");
      array->append(100);
      JsonValue jvalue = createJsonValue();
      jvalue->put(S("jv1"),(char *)"jv1");
      jvalue->put(S("jv2"),2);
      //TEST_FAIL("jvalue size is %d ",jvalue->size());
      array->append(jvalue);
      value->put(S("testarr1"),array);

      //start check
      JsonValue testArray = value->getValue("testarr1");
      String t1 = testArray->getStringAt(0);
      if(!t1->sameAs("abc1")) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case24]");
        break;
      }

      Integer t2 = testArray->getIntegerAt(1);
      //TEST_FAIL("t2 is %d ",t2->toValue());
      if(t2->toValue() != 100) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case25]");
        break;
      }

      JsonValue v3 = testArray->getValueAt(2);
      //TEST_FAIL("v3 is %d ",v3->size());
      if(!v3->getString("jv1")->sameAs("jv1")) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case26]");
        break;
      }

      //Integer t4 = testArray->getValue(3)->getInteger();
      if(v3->getInteger("jv2")->toValue()!= 2) {
        TEST_FAIL("[JsonReader SimpleRead {put()} case27]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {put()} case27]");
      break;
    }

    //void remove(String tag);
    while(1) {
      JsonValue array = createJsonValue();
      array->append((char *)"abc1");
      array->append(100);
      value->put(S("testarr2"),array);

      bool formexist = false;
      if(value->contains(S("testarr2"))) {
        //TEST_FAIL("remove testArr2 exists ");
        formexist = true;
      }

      value->remove(S("testarr2"));
      if(value->contains(S("testarr2")) && formexist) {
        TEST_FAIL("[JsonReader SimpleRead {remove()} case１]");
        break;
      }

      value->remove("tt");

      TEST_OK("[JsonReader SimpleRead {remove()} case2]");
      break;
    }

    //String getString(String tag);
    while(1) {
      String v1 = value->getString("c");
      if(v1 == nullptr || !v1->sameAs("nihao")) {
        TEST_FAIL("[JsonReader SimpleRead {getString()} case１]");
        break;
      }

      String v2 = value->getString("what");
      if(v2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {getString()} case2]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getString()} case3]");
      break;
    }

    //String getString();
    while(1) {
      JsonValue v1 = value->getValue(createString("c"));
      String str1 = v1->getString();
      if(str1 == nullptr || !str1->sameAs("nihao")) {
        TEST_FAIL("[JsonReader SimpleRead {getString()} case4]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getString()} case5]  ");
      break;
    }

    //Integer getInteger(String tag);
    while(1) {
      Integer v1 = value->getInteger("a");
      if(v1 == nullptr || v1->toValue() != 1) {
        TEST_FAIL("[JsonReader SimpleRead {getInteger()} case１]");
        break;
      }

      Integer v2 = value->getInteger("what");
      if(v2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {getInteger()} case2]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getInteger()} case3]  ");
      break;
    }

    //Integer getInteger();
    while(1) {
      JsonValue v1 = value->getValue("a");
      Integer str1 = v1->getInteger();
      if(str1 == nullptr || str1->toValue() != 1) {
        TEST_FAIL("[JsonReader SimpleRead {getInteger()} case4]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getInteger()} case5]  ");
      break;
    }

    //getBoolean(String tag)
    while(1) {
      Boolean v1 = value->getBoolean("ret");
      if(v1 == nullptr || v1->toValue() != true) {
        TEST_FAIL("[JsonReader SimpleRead {getBoolean()} case１]");
        break;
      }

      Boolean v2 = value->getBoolean("what");
      if(v2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {getBoolean()} case2]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getBoolean()} case3]  ");
      break;
    }

    //Boolean getBoolean();
    while(1) {
      JsonValue v1 = value->getValue("ret");
      Boolean str1 = v1->getBoolean();
      if(str1 == nullptr || str1->toValue() != true) {
        TEST_FAIL("[JsonReader SimpleRead {getBoolean()} case4]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getBoolean()} case5]  ");
      break;
    }

    //getDouble(String tag)
    while(1) {
      Double v1 = value->getDouble("b");
      if(v1 == nullptr || v1->toValue() != 2) {
        TEST_FAIL("[JsonReader SimpleRead {getDouble()} case１]");
        break;
      }

      Double v2 = value->getDouble("what");
      if(v2 != nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {getDouble()} case2]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getDouble()} case3]  ");
      break;
    }

    //getDouble();
    while(1) {
      JsonValue v1 = value->getValue("b");
      Double str1 = v1->getDouble();
      if(str1 == nullptr || str1->toValue() != 2) {
        TEST_FAIL("[JsonReader SimpleRead {getDouble()} case4]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getDouble()} case5]  ");
      break;
    }

    //sp<_JsonValue> getValue(String tag);
    while(1) {
      JsonValue arr1 = value->getValue(createString("arr"));
      if(arr1 == nullptr) {
        TEST_FAIL("[JsonReader SimpleRead {getValue()} case１]");
        break;
      }

      //TEST_FAIL("arr1->size is %d ",arr1->size());
      if(arr1->size() != 3) {
        TEST_FAIL("[JsonReader SimpleRead {getValue()} case2]");
        break;
      }

      String str1 = arr1->getStringAt(0);
      //TEST_FAIL("str1 is %s ",str1->toChars());
      if(!str1->sameAs("abc1")) {
        TEST_FAIL("[JsonReader SimpleRead {getValue()} case3]");
        break;
      }

      str1 = arr1->getStringAt(1);
      //TEST_FAIL("str1 is %s ",str1->toChars());
      if(!str1->sameAs("abc2")) {
        TEST_FAIL("[JsonReader SimpleRead {getValue()} case4]");
        break;
      }

      str1 = arr1->getStringAt(2);
      //TEST_FAIL("str1 is %s ",str1->toChars());
      if(!str1->sameAs("abc3")) {
        TEST_FAIL("[JsonReader SimpleRead {getValue()} case5]");
        break;
      }

      TEST_OK("[JsonReader SimpleRead {getValue()} case6]  ");
      break;
    }

    return 0;
}
