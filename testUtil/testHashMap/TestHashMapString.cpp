#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TT1) {
public:
  int i;
};

void testHashMapString() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<String,TT1> map = HashMap<String,TT1>::New();
        String tag = String::New("tag1");
        TT1 tt = TT1::New();
        tt->i = 100;
        map->put(tag,tt);

        if(map->size() != 1) {
            TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case1]");
            break;
        }
        TT1 tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put("tag2",nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case3]");
          break;
        }
        TT1 tt3 = map->get(nullptr);
        if(tt3 != nullptr) {
          TEST_FAIL("[HashMap String Test {put(T t,U u)/get(T t)} case4]");
          break;
        }

        TEST_OK("[HashMap String Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      String tag = String::New("tag1");
      TT1 tt = TT1::New();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(String::New("tag1"));
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap String Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      map->remove(nullptr);
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
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      String tag = String::New("tag1");
      TT1 tt = TT1::New();
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
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      String tag = String::New("tag1");
      TT1 tt = TT1::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(String::New("tag2"),tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap String Test {clear()} case1]");
        break;
      }

      HashMap<String,TT1> map2 = HashMap<String,TT1>::New();
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
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      String tag = String::New("tag1");
      TT1 tt = TT1::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(String::New("tag2"),tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap String Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap String Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      for(int index = 0;index < 100;index++) {
        TT1 tt = TT1::New();
        tt->i = index;
        //TEST_FAIL("put index is %d ",index);
        map->put(String::New(index),tt);
      }

      ArrayList<String> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap String Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        String key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toBasicInt(),index);
          TEST_FAIL("[HashMap String Test {keySet(),index is %d} case2]",index);
          break;
        }
      }

      HashMap<String,TT1> map2 = HashMap<String,TT1>::New();
      ArrayList<String>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap String Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap String Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      for(int index = 0;index < 100;index++) {
        TT1 tt = TT1::New();
        tt->i = index;
        map->put(String::New(index),tt);
      }

      ArrayList<TT1> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        TT1 key1 = keys->get(index);
        if(map->get(String::New(key1->i)) == nullptr) {
          TEST_FAIL("[HashMap String Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<String,TT1> map2 = HashMap<String,TT1>::New();
      ArrayList<TT1>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap String Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap String Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<String,TT1> map = HashMap<String,TT1>::New();
      for(int index = 0;index < 100;index++) {
        TT1 tt = TT1::New();
        tt->i = index;
        map->put(String::New(index),tt);
      }

      int index = 0;
      MapIterator<String,TT1> iterator = map->getIterator();
      while(iterator->hasValue()) {
          String key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator String Test {getKey/getValue()} case1]");
            break;
          }

          TT1 t1 = iterator->getValue();
          if(t1->i != key->toBasicInt()) {
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
