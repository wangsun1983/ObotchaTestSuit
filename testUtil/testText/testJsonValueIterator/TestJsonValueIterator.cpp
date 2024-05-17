#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"
#include "TestLog.hpp"
#include "Log.hpp"

using namespace obotcha;

int testJsonValueIterator() {
    JsonReader reader = JsonReader::New()->loadFile(File::New("abc.json"));
    //String getTag();
    JsonValueIterator iterator = reader->get()->getIterator();
    while(1) {
      if(!iterator->getTag()->sameAs("a")) {
        TEST_FAIL("[JsonValueIterator Test {getTag()} case1]");
        break;
      }
      TEST_OK("[JsonValueIterator Test {getTag()} case2]");
      break;
    }

    //bool hasValue();
    while(1) {
      if(!iterator->hasValue()) {
        TEST_FAIL("[JsonValueIterator Test {hasValue()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {hasValue()} case2]");
      break;
    }

    //bool isInt();
    while(1) {
      if(!iterator->isInt()) {
        TEST_FAIL("[JsonValueIterator Test {isInt()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {isInt()} case2]");
      break;
    }

    //Integer getInteger();
    while(1) {
      Integer v1 = iterator->getInteger();
      if(v1 == nullptr || v1->toValue() != 1) {
        TEST_FAIL("[JsonValueIterator Test {getInteger()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {getInteger()} case2]");
      break;
    }

    //bool isArray();
    while(1) {
      iterator->next();
      if(!iterator->isArray()) {
        TEST_FAIL("[JsonValueIterator Test {isArray()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {isArray()} case2]");
      break;
    }

    //sp<_JsonArray> getArray();
    while(1) {
      JsonValue v1 = iterator->getValue();
      if(v1 == nullptr || v1->size() != 3) {
        TEST_FAIL("[JsonValueIterator Test {getArray()} case1]");
        break;
      }

      String a1 = v1->getStringAt(0);
      if(a1 == nullptr ||!a1->sameAs("abc1")) {
        TEST_FAIL("[JsonValueIterator Test {getArray()} case2]");
        break;
      }

      String a2 = v1->getStringAt(1);
      if(a2 == nullptr ||!a2->sameAs("abc2")) {
        TEST_FAIL("[JsonValueIterator Test {getArray()} case3]");
        break;
      }

      String a3 = v1->getStringAt(2);
      if(a3 == nullptr ||!a3->sameAs("abc3")) {
        TEST_FAIL("[JsonValueIterator Test {getArray()} case4]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {getArray()} case5]");
      break;
    }

    //bool isObject();
    while(1) {
        iterator->next();
        if(!iterator->isObject()) {
          TEST_FAIL("[JsonValueIterator Test {isObject()} case1]");
          break;
        }

        TEST_OK("[JsonValueIterator Test {isObject()} case2]");
        break;
    }

    //sp<_JsonValue> getObject();
    while(1) {
      JsonValue v1 = iterator->getObject();
      if(v1 == nullptr) {
        TEST_FAIL("[JsonValueIterator Test {getObject()} case1]");
        break;
      }

      Integer t1 = v1->getInteger("v1");
      if(t1 == nullptr || t1->toValue() != 1) {
        TEST_FAIL("[JsonValueIterator Test {getObject()} case2]");
        break;
      }

      String t2 = v1->getString("vv");
      if(t2 == nullptr || !t2->sameAs("v1")) {
        TEST_FAIL("[JsonValueIterator Test {getObject()} case3]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {getObject()} case4]");
      break;
    }

    //bool isString();
    while(1) {
      iterator->next();
      //String tag = iterator->getTag();
      //TEST_FAIL("tag2 is %s ",tag->toChars());

      if(!iterator->isString()) {
        TEST_FAIL("[JsonValueIterator Test {isString()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {isString()} case2]");
      break;
    }

    //String getString();
    while(1) {
      String v1 = iterator->getString();
      if(v1 == nullptr ||!v1->sameAs("nihao")) {
        TEST_FAIL("[JsonValueIterator Test {getString()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {getString()} case2]");
      break;
    }

    //bool isBool();
    while(1) {
      iterator->next();
      //String tag = iterator->getTag();
      //TEST_FAIL("tag2 is %s ",tag->toChars());

      if(!iterator->isBool()) {
        TEST_FAIL("[JsonValueIterator Test {isBool()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {isBool()} case2]");
      break;
    }

    //Boolean getBoolean();
    while(1) {
      Boolean v1 = iterator->getBoolean();
      if(v1 == nullptr ||v1->toValue() != true) {
        TEST_FAIL("[JsonValueIterator Test {getBoolean()} case1]");
        break;
      }

      TEST_OK("[JsonValueIterator Test {getBoolean()} case2]");
      break;
    }

    return 0;
}
