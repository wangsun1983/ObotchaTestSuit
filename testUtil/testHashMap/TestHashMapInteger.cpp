#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Integer.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TT2) {
public:
  int i;
};

void testHashMapInteger() {
    //test null and 0
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      TT2 tt = TT2::New();
      tt->i = 100;
      map->put(nullptr,tt);

      TT2 tt2 = TT2::New();
      tt2->i = 1;
      map->put(Integer::New(0),tt2);

      if(map->get(Integer::New(0))->i != 1) {
        TEST_FAIL("[HashMap Integer Test {null test} case1]");
        break;
      }

      TEST_OK("[HashMap Integer Test {null test} case2]");
      break;
    }

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
        Integer tag = Integer::New(1);
        TT2 tt = TT2::New();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap Integer Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        TT2 tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap Integer Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(Integer::New(2),nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap Integer Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TT2 tt3 = map->get(nullptr);
        if(tt3 != nullptr) {
          TEST_FAIL("[HashMap Integer Test {put(T t,U u)/get(T t)} case4]");
          break;
        }

        TEST_OK("[HashMap Integer Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      Integer tag = Integer::New(1);
      TT2 tt = TT2::New();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(Integer::New(1));
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap Integer Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      map->remove(nullptr);
      if(map->size() != 1) {
        TEST_FAIL("[HashMap Integer Test {remove(T t)} case2]");
        break;
      }

      map->remove(Integer::New(1));
      if(map->size() != 0) {
        TEST_FAIL("[HashMap Integer Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap Integer Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      Integer tag = Integer::New(1);
      TT2 tt = TT2::New();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap Integer Test {isEmpty()} case1]");
        break;
      }

      map->remove(Integer::New(1));
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap Integer Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap Integer Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      Integer tag = Integer::New(1);
      TT2 tt = TT2::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(Integer::New(2),tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap Integer Test {clear()} case1]");
        break;
      }

      HashMap<Integer,TT2> map2 = HashMap<Integer,TT2>::New();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap Integer Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap Integer Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      Integer tag = Integer::New(1);
      TT2 tt = TT2::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(Integer::New(2),tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap Integer Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap Integer Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      for(int index = 0;index < 100;index++) {
        TT2 tt = TT2::New();
        tt->i = index;
        map->put(Integer::New(index),tt);
      }

      ArrayList<Integer> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap Integer Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        Integer key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap Integer Test {keySet()} case2]");
          break;
        }
      }

      HashMap<Integer,TT2> map2 = HashMap<Integer,TT2>::New();
      ArrayList<Integer>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap Integer Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap Integer Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      for(int index = 0;index < 100;index++) {
        TT2 tt = TT2::New();
        tt->i = index;
        map->put(Integer::New(index),tt);
      }

      ArrayList<TT2> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        TT2 key1 = keys->get(index);
        if(map->get(Integer::New(key1->i)) == nullptr) {
          TEST_FAIL("[HashMap Integer Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<Integer,TT2> map2 = HashMap<Integer,TT2>::New();
      ArrayList<TT2>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap Integer Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap Integer Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<Integer,TT2> map = HashMap<Integer,TT2>::New();
      for(int index = 0;index < 100;index++) {
        TT2 tt = TT2::New();
        tt->i = index;
        map->put(Integer::New(index),tt);
      }

      int index = 0;
      MapIterator<Integer,TT2> iterator = map->getIterator();
      while(iterator->hasValue()) {
          Integer key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator Integer Test {getKey/getValue()} case1]");
            break;
          }

          TT2 t1 = iterator->getValue();
          if(t1->i != key->toValue()) {
            TEST_FAIL("[MapIterator Integer Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator Integer Test {getKey/getValue()} case3]");
      break;

    }

    while(1) {
      HashMap<Integer,String> map = HashMap<Integer,String>::New();
      map->put(Integer::New(1),String::New("hello"));
      map->put(Integer::New(1),String::New("hello3"));
      String str = map->get(Integer::New(1));
      if(str == nullptr) {
        TEST_FAIL("[MapIterator Integer Test special equal case1] [FAIL] ");
        break;
      }

      if(!str->sameAs("hello3")) {
        TEST_FAIL("[MapIterator Integer Test special equal case2] [FAIL] ");
        break;
      }

      TEST_OK("[MapIterator Integer Test special equal case3]");
      break;
    }
}
