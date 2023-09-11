#include <stdio.h>
#include <unistd.h>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"
#include "TestLog.hpp"

#include "Log.hpp"

using namespace obotcha;

int testJsonArrayIterator() {
    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("stringarray.json"));
      JsonValue value = reader->get();
      auto iterator = value->getIterator();
      ArrayList<String> list = createArrayList<String>();
      list->add(S("abc1"));
      list->add(S("abc2"));
      list->add(S("abc3"));

      int index = 0;
      while(iterator->hasValue()) {
        auto str = iterator->getString();
        if(!str->equals(list->get(index))) {
          TEST_FAIL("[JsonArrayIterator Test case1]");
          break;
        }

        iterator->next();
        index++;
      }

      if(index != 3){
        TEST_FAIL("[JsonArrayIterator Test case2]");
        break;
      }
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("intarray.json"));
      JsonValue value = reader->get();
      auto iterator = value->getIterator();
      int array[] = {1, 100, 123};

      int index = 0;
      while(iterator->hasValue()) {
        auto str = iterator->getInteger();
        if(str->toValue() != array[index]) {
          TEST_FAIL("[JsonArrayIterator Test case3]");
          break;
        }
        iterator->next();
        index++;
      }

      if(index != 3){
        TEST_FAIL("[JsonArrayIterator Test case4]");
        break;
      }
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("booljson.json"));
      JsonValue value = reader->get();
      auto iterator = value->getIterator();
      bool array[] = {true, false, true};

      int index = 0;
      while(iterator->hasValue()) {
        auto str = iterator->getBoolean();
        if(str->toValue() != array[index]) {
          TEST_FAIL("[JsonArrayIterator Test case5]");
          break;
        }
        iterator->next();
        index++;
      }

      if(index != 3){
        TEST_FAIL("[JsonArrayIterator Test case6]");
        break;
      }
      break;
    }

    while(1) {
      JsonReader reader = createJsonReader()->loadFile(createFile("object.json"));
      JsonValue value = reader->get();
      auto iterator = value->getIterator();
      int val_array[] = {1, 2, 3};
      std::string tag_value[] = {"a","b","c"};

      int index = 0;
      while(iterator->hasValue()) {
        String tag  = iterator->getTag();
        if(!tag->sameAs(tag_value[index])) {
          TEST_FAIL("[JsonArrayIterator Test case7]");
          break;
        }

        Integer val = iterator->getInteger();
        if(val->toValue() != val_array[index]) {
          TEST_FAIL("[JsonArrayIterator Test case8]");
          break;
        }

        iterator->next();
        index++;
      }

      if(index != 3){
        TEST_FAIL("[JsonArrayIterator Test case9]");
        break;
      }
      break;
    }

    TEST_OK("[JsonArrayIterator Test case100]");
    return 0;
}
