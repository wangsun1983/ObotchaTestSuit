#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Long.hpp"
#include "Long.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TT4) {
public:
  long i;
};

void testHashMapLong() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
        Long tag = Long::New(1);
        TT4 tt = TT4::New();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap Long Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        TT4 tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap Long Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(Long::New(2),nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap Long Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TT4 TT4 = map->get(nullptr);
        if(TT4 != nullptr) {
          TEST_FAIL("[HashMap Long Test {put(T t,U u)/get(T t)} case4]");
          break;
        }

        TEST_OK("[HashMap Long Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      Long tag = Long::New(1);
      TT4 tt = TT4::New();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(Long::New(1));
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap Long Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      map->remove(nullptr);
      if(map->size() != 1) {
        TEST_FAIL("[HashMap Long Test {remove(T t)} case2]");
        break;
      }

      map->remove(Long::New(1));
      if(map->size() != 0) {
        TEST_FAIL("[HashMap Long Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap Long Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      Long tag = Long::New(1);
      TT4 tt = TT4::New();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap Long Test {isEmpty()} case1]");
        break;
      }

      map->remove(Long::New(1));
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap Long Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap Long Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      Long tag = Long::New(1);
      TT4 tt = TT4::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(Long::New(2),tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap Long Test {clear()} case1]");
        break;
      }

      HashMap<Long,TT4> map2 = HashMap<Long,TT4>::New();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap Long Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap Long Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      Long tag = Long::New(1);
      TT4 tt = TT4::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(Long::New(2),tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap Long Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap Long Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      for(int index = 0;index < 100;index++) {
        TT4 tt = TT4::New();
        tt->i = index;
        map->put(Long::New(index),tt);
      }

      ArrayList<Long> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap Long Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        Long key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap Long Test {keySet()} case2]");
          break;
        }
      }

      HashMap<Long,TT4> map2 = HashMap<Long,TT4>::New();
      ArrayList<Long>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap Long Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap Long Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      for(int index = 0;index < 100;index++) {
        TT4 tt = TT4::New();
        tt->i = index;
        map->put(Long::New(index),tt);
      }

      ArrayList<TT4> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        TT4 key1 = keys->get(index);
        if(map->get(Long::New(key1->i)) == nullptr) {
          TEST_FAIL("[HashMap Long Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<Long,TT4> map2 = HashMap<Long,TT4>::New();
      ArrayList<TT4>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap Long Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap Long Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<Long,TT4> map = HashMap<Long,TT4>::New();
      for(int index = 0;index < 100;index++) {
        TT4 tt = TT4::New();
        tt->i = index;
        map->put(Long::New(index),tt);
      }

      int index = 0;
      MapIterator<Long,TT4> iterator = map->getIterator();
      while(iterator->hasValue()) {
          Long key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator Long Test {getKey/getValue()} case1]");
            break;
          }

          TT4 t1 = iterator->getValue();
          if(t1->i != key->toValue()) {
            TEST_FAIL("[MapIterator Long Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator Long Test {getKey/getValue()} case3]");
      break;

    }


}
