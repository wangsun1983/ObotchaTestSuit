#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Double.hpp"
#include "Double.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TT3) {
public:
  double i;
};

void testHashMapDouble() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<Double,TT3> map = createHashMap<Double,TT3>();
        Double tag = createDouble(1);
        TT3 tt = createTT3();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap Double Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        TT3 tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap Double Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(createDouble(2),nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap Double Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TT3 tt3 = map->get(nullptr);
        if(tt3 != nullptr) {
          TEST_FAIL("[HashMap Double Test {put(T t,U u)/get(T t)} case4]");
          break;
        }

        TEST_OK("[HashMap Double Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      Double tag = createDouble(1);
      TT3 tt = createTT3();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(createDouble(1));
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap Double Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      map->remove(nullptr);
      if(map->size() != 1) {
        TEST_FAIL("[HashMap Double Test {remove(T t)} case2]");
        break;
      }

      map->remove(createDouble(1));
      if(map->size() != 0) {
        TEST_FAIL("[HashMap Double Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap Double Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      Double tag = createDouble(1);
      TT3 tt = createTT3();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap Double Test {isEmpty()} case1]");
        break;
      }

      map->remove(createDouble(1));
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap Double Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap Double Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      Double tag = createDouble(1);
      TT3 tt = createTT3();
      tt->i = 100;
      map->put(tag,tt);
      map->put(createDouble(2),tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap Double Test {clear()} case1]");
        break;
      }

      HashMap<Double,TT3> map2 = createHashMap<Double,TT3>();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap Double Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap Double Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      Double tag = createDouble(1);
      TT3 tt = createTT3();
      tt->i = 100;
      map->put(tag,tt);
      map->put(createDouble(2),tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap Double Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap Double Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      for(int index = 0;index < 100;index++) {
        TT3 tt = createTT3();
        tt->i = index;
        map->put(createDouble(index),tt);
      }

      ArrayList<Double> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap Double Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        Double key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap Double Test {keySet()} case2]");
          break;
        }
      }

      HashMap<Double,TT3> map2 = createHashMap<Double,TT3>();
      ArrayList<Double>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap Double Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap Double Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      for(int index = 0;index < 100;index++) {
        TT3 tt = createTT3();
        tt->i = index;
        map->put(createDouble(index),tt);
      }

      ArrayList<TT3> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        TT3 key1 = keys->get(index);
        if(map->get(createDouble(key1->i)) == nullptr) {
          TEST_FAIL("[HashMap Double Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<Double,TT3> map2 = createHashMap<Double,TT3>();
      ArrayList<TT3>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap Double Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap Double Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<Double,TT3> map = createHashMap<Double,TT3>();
      for(int index = 0;index < 100;index++) {
        TT3 tt = createTT3();
        tt->i = index;
        map->put(createDouble(index),tt);
      }

      int index = 0;
      MapIterator<Double,TT3> iterator = map->getIterator();
      while(iterator->hasValue()) {
          Double key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator Double Test {getKey/getValue()} case1]");
            break;
          }

          TT3 t1 = iterator->getValue();
          if(t1->i != key->toValue()) {
            TEST_FAIL("[MapIterator Double Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator Double Test {getKey/getValue()} case3]");
      break;

    }


}
