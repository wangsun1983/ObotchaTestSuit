#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Double.hpp"
#include "Double.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(SimpleDoubleData) {
public:
  double i;
};

void testHashMapSimpleDouble() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
        double tag = 1;
        SimpleDoubleData tt = SimpleDoubleData::New();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap Simple Double Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        SimpleDoubleData tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap Simple Double Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(2,nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap Simple Double Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TEST_OK("[HashMap Simple Double Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      double tag = 1;
      SimpleDoubleData tt = SimpleDoubleData::New();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(1);
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap Simple Double Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      if(map->size() != 1) {
        TEST_FAIL("[HashMap Simple Double Test {remove(T t)} case2]");
        break;
      }

      map->remove(1);
      if(map->size() != 0) {
        TEST_FAIL("[HashMap Simple Double Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap Simple Double Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      double tag = 1;
      SimpleDoubleData tt = SimpleDoubleData::New();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap Simple Double Test {isEmpty()} case1]");
        break;
      }

      map->remove(1);
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap Simple Double Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap Simple Double Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      double tag = 1;
      SimpleDoubleData tt = SimpleDoubleData::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(2,tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap Simple Double Test {clear()} case1]");
        break;
      }

      HashMap<double,SimpleDoubleData> map2 = HashMap<double,SimpleDoubleData>::New();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap Simple Double Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap Simple Double Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      double tag = 1;
      SimpleDoubleData tt = SimpleDoubleData::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(2,tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap Simple Double Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap Simple Double Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      for(int index = 0;index < 100;index++) {
        SimpleDoubleData tt = SimpleDoubleData::New();
        tt->i = index;
        map->put(index,tt);
      }

      ArrayList<double> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap Simple Double Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        double key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap Simple Double Test {keySet()} case2]");
          break;
        }
      }

      HashMap<double,SimpleDoubleData> map2 = HashMap<double,SimpleDoubleData>::New();
      ArrayList<double>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap Simple Double Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap Simple Double Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      for(int index = 0;index < 100;index++) {
        SimpleDoubleData tt = SimpleDoubleData::New();
        tt->i = index;
        map->put(index,tt);
      }

      ArrayList<SimpleDoubleData> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        SimpleDoubleData key1 = keys->get(index);
        if(map->get(key1->i) == nullptr) {
          TEST_FAIL("[HashMap Simple Double Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<double,SimpleDoubleData> map2 = HashMap<double,SimpleDoubleData>::New();
      ArrayList<SimpleDoubleData>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap Simple Double Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap Simple Double Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<double,SimpleDoubleData> map = HashMap<double,SimpleDoubleData>::New();
      for(int index = 0;index < 100;index++) {
        SimpleDoubleData tt = SimpleDoubleData::New();
        tt->i = index;
        map->put(index,tt);
      }

      int index = 0;
      MapIterator<double,SimpleDoubleData> iterator = map->getIterator();
      while(iterator->hasValue()) {
          double key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator Double Test {getKey/getValue()} case1]");
            break;
          }

          SimpleDoubleData t1 = iterator->getValue();
          if(t1->i != key) {
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
