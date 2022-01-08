#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(SimpleStringData) {
public:
  int i;
};

void testHashMapSimpleString() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
        std::string tag = "tag1";
        SimpleStringData tt = createSimpleStringData();
        tt->i = 100;
        map->put(tag,tt);

        if(map->size() != 1) {
            TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case1]");
            break;
        }
        SimpleStringData tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put("tag2",nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TEST_OK("[HashMap String Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      std::string tag = "tag1";
      SimpleStringData tt = createSimpleStringData();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove("tag1");
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap String Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      if(map->size() != 1) {
        TEST_FAIL("[HashMap String Test {remove(T t)} case2]");
        break;
      }

      map->remove("tag2");
      if(map->size() != 1) {
        TEST_FAIL("[HashMap String Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap String Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      std::string tag = "tag1";
      SimpleStringData tt = createSimpleStringData();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap String Test {isEmpty()} case1]");
        break;
      }

      map->remove("tag1");
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap String Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap String Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      std::string tag = "tag1";
      SimpleStringData tt = createSimpleStringData();
      tt->i = 100;
      map->put(tag,tt);
      map->put("tag2",tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap String Test {clear()} case1]");
        break;
      }

      HashMap<std::string,SimpleStringData> map2 = createHashMap<std::string,SimpleStringData>();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap String Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap String Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      std::string tag = "tag1";
      SimpleStringData tt = createSimpleStringData();
      tt->i = 100;
      map->put(tag,tt);
      map->put("tag2",tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap String Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap String Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      for(int index = 0;index < 100;index++) {
        SimpleStringData tt = createSimpleStringData();
        tt->i = index;
        //TEST_FAIL("put index is %d ",index);
        map->put(std::to_string(index),tt);
      }

      ArrayList<std::string> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap String Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        std::string key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toBasicInt(),index);
          TEST_FAIL("[HashMap String Test {keySet(),index is %d} case2]",index);
          break;
        }
      }

      HashMap<std::string,SimpleStringData> map2 = createHashMap<std::string,SimpleStringData>();
      ArrayList<std::string>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap String Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap String Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      for(int index = 0;index < 100;index++) {
        SimpleStringData tt = createSimpleStringData();
        tt->i = index;
        map->put(std::to_string(index),tt);
      }

      ArrayList<SimpleStringData> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        SimpleStringData key1 = keys->get(index);
        if(map->get(std::to_string(key1->i)) == nullptr) {
          TEST_FAIL("[HashMap String Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<std::string,SimpleStringData> map2 = createHashMap<std::string,SimpleStringData>();
      ArrayList<SimpleStringData>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap String Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap String Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<std::string,SimpleStringData> map = createHashMap<std::string,SimpleStringData>();
      for(int index = 0;index < 100;index++) {
        SimpleStringData tt = createSimpleStringData();
        tt->i = index;
        map->put(std::to_string(index),tt);
      }

      int index = 0;
      MapIterator<std::string,SimpleStringData> iterator = map->getIterator();
      while(iterator->hasValue()) {
          std::string key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator String Test {getKey/getValue()} case1]");
            break;
          }

          SimpleStringData t1 = iterator->getValue();
          if(t1->i != atoi(key.c_str())) {
            TEST_FAIL("[MapIterator String Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator String Test {getKey/getValue()} case3]");
      break;

    }

}
