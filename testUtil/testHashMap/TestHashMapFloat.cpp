#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Float.hpp"
#include "Float.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TT5) {
public:
  float i;
};

void testHashMapFloat() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
        Float tag = Float::New(1);
        TT5 tt = TT5::New();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap Float Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        TT5 tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap Float Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(Float::New(2),nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap Float Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TT5 TT5 = map->get(nullptr);
        if(TT5 != nullptr) {
          TEST_FAIL("[HashMap Float Test {put(T t,U u)/get(T t)} case4]");
          break;
        }

        TEST_OK("[HashMap Float Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      Float tag = Float::New(1);
      TT5 tt = TT5::New();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(Float::New(1));
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap Float Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      map->remove(nullptr);
      if(map->size() != 1) {
        TEST_FAIL("[HashMap Float Test {remove(T t)} case2]");
        break;
      }

      map->remove(Float::New(1));
      if(map->size() != 0) {
        TEST_FAIL("[HashMap Float Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap Float Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      Float tag = Float::New(1);
      TT5 tt = TT5::New();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap Float Test {isEmpty()} case1]");
        break;
      }

      map->remove(Float::New(1));
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap Float Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap Float Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      Float tag = Float::New(1);
      TT5 tt = TT5::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(Float::New(2),tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap Float Test {clear()} case1]");
        break;
      }

      HashMap<Float,TT5> map2 = HashMap<Float,TT5>::New();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap Float Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap Float Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      Float tag = Float::New(1);
      TT5 tt = TT5::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(Float::New(2),tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap Float Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap Float Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      for(int index = 0;index < 100;index++) {
        TT5 tt = TT5::New();
        tt->i = index;
        map->put(Float::New(index),tt);
      }

      ArrayList<Float> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap Float Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        Float key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap Float Test {keySet()} case2]");
          break;
        }
      }

      HashMap<Float,TT5> map2 = HashMap<Float,TT5>::New();
      ArrayList<Float>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap Float Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap Float Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      for(int index = 0;index < 100;index++) {
        TT5 tt = TT5::New();
        tt->i = index;
        map->put(Float::New(index),tt);
      }

      ArrayList<TT5> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        TT5 key1 = keys->get(index);
        if(map->get(Float::New(key1->i)) == nullptr) {
          TEST_FAIL("[HashMap Float Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<Float,TT5> map2 = HashMap<Float,TT5>::New();
      ArrayList<TT5>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap Float Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap Float Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<Float,TT5> map = HashMap<Float,TT5>::New();
      for(int index = 0;index < 100;index++) {
        TT5 tt = TT5::New();
        tt->i = index;
        map->put(Float::New(index),tt);
      }

      int index = 0;
      MapIterator<Float,TT5> iterator = map->getIterator();
      while(iterator->hasValue()) {
          Float key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator Float Test {getKey/getValue()} case1]");
            break;
          }

          TT5 t1 = iterator->getValue();
          if(t1->i != key->toValue()) {
            TEST_FAIL("[MapIterator Float Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator Float Test {getKey/getValue()} case3]");
      break;

    }


}
