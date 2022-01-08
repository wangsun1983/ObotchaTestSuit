#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Boolean.hpp"
#include "Boolean.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(SimpleTestData) {
public:
  bool i;
};

void testHashMapSimpleBoolean() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
        SimpleTestData tt = createSimpleTestData();
        tt->i = true;
        map->put(true,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap Simple bool Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        SimpleTestData tt2 = map->get(true);
        if(tt2 == nullptr || tt2->i != true) {
          TEST_FAIL("[HashMap Simple bool Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(false,nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap Simple bool Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TEST_OK("[HashMap Simple bool Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      bool tag = true;
      SimpleTestData tt = createSimpleTestData();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(true);
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap Simple bool Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      if(map->size() != 1) {
        TEST_FAIL("[HashMap Simple bool Test {remove(T t)} case2]");
        break;
      }

      map->remove(true);
      if(map->size() != 0) {
        TEST_FAIL("[HashMap Simple bool Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap Simple bool Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      bool tag = true;
      SimpleTestData tt = createSimpleTestData();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap Simple bool Test {isEmpty()} case1]");
        break;
      }

      map->remove(true);
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap Simple bool Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap Simple bool Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      bool tag = true;
      SimpleTestData tt = createSimpleTestData();
      tt->i = true;
      map->put(tag,tt);
      map->put(false,tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap Simple bool Test {clear()} case1]");
        break;
      }

      HashMap<bool,SimpleTestData> map2 = createHashMap<bool,SimpleTestData>();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap Simple bool Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap Simple bool Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      bool tag = true;
      SimpleTestData tt = createSimpleTestData();
      tt->i = true;
      map->put(tag,tt);
      map->put(false,tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap Simple bool Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap Simple bool Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      SimpleTestData tt1 = createSimpleTestData();
      tt1->i = true;
      map->put(true,tt1);

      SimpleTestData tt2 = createSimpleTestData();
      tt2->i = false;
      map->put(false,tt2);

      ArrayList<bool> keys = map->keySet();
      int size = keys->size();
      if(size != 2) {
        TEST_FAIL("[HashMap Simple bool Test {keySet()} case1]");
        break;
      }

      HashMap<bool,SimpleTestData> map2 = createHashMap<bool,SimpleTestData>();
      ArrayList<bool>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap Simple bool Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap Simple bool Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      SimpleTestData tt1 = createSimpleTestData();
      tt1->i = true;
      map->put(true,tt1);

      SimpleTestData tt2 = createSimpleTestData();
      tt2->i = false;
      map->put(false,tt2);

      ArrayList<SimpleTestData> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        SimpleTestData key1 = keys->get(index);
        if(map->get(key1->i) == nullptr) {
          TEST_FAIL("[HashMap Simple bool Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<Boolean,SimpleTestData> map2 = createHashMap<Boolean,SimpleTestData>();
      ArrayList<SimpleTestData>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap Simple bool Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap Simple bool Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<bool,SimpleTestData> map = createHashMap<bool,SimpleTestData>();
      SimpleTestData tt1 = createSimpleTestData();
      tt1->i = true;
      map->put(true,tt1);

      SimpleTestData tt2 = createSimpleTestData();
      tt2->i = false;
      map->put(false,tt2);

      int index = 0;
      MapIterator<bool,SimpleTestData> iterator = map->getIterator();
      while(iterator->hasValue()) {
          bool key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator Boolean Test {getKey/getValue()} case1]");
            break;
          }

          SimpleTestData t1 = iterator->getValue();
          if(t1->i != key) {
            TEST_FAIL("[MapIterator Boolean Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator Boolean Test {getKey/getValue()} case3]");
      break;
    }


}
