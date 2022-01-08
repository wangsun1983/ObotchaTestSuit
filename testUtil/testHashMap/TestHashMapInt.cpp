#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TTInt) {
public:
  int i;
};

void testHashMapInt() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<int,TTInt> map = createHashMap<int,TTInt>();
        int tag = 1;
        TTInt tt = createTTInt();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap int Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        TTInt TTInt = map->get(tag);
        if(TTInt == nullptr || TTInt->i != 100) {
          TEST_FAIL("[HashMap int Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(2,nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap int Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        TEST_OK("[HashMap int Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      int tag = 1;
      TTInt tt = createTTInt();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(1);
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap int Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();

      map->remove(1);
      if(map->size() != 0) {
        TEST_FAIL("[HashMap int Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap int Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      int tag = 1;
      TTInt tt = createTTInt();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap int Test {isEmpty()} case1]");
        break;
      }

      map->remove(1);
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap int Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap int Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      int tag = 1;
      TTInt tt = createTTInt();
      tt->i = 100;
      map->put(tag,tt);
      map->put(2,tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap int Test {clear()} case1]");
        break;
      }

      HashMap<int,TTInt> map2 = createHashMap<int,TTInt>();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap int Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap int Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      int tag = 1;
      TTInt tt = createTTInt();
      tt->i = 100;
      map->put(tag,tt);
      map->put(2,tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap int Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap int Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      for(int index = 0;index < 100;index++) {
        TTInt tt = createTTInt();
        tt->i = index;
        map->put(index,tt);
      }

      ArrayList<int> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap int Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        int key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap int Test {keySet()} case2]");
          break;
        }
      }

      HashMap<int,TTInt> map2 = createHashMap<int,TTInt>();
      ArrayList<int>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap int Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap int Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      for(int index = 0;index < 100;index++) {
        TTInt tt = createTTInt();
        tt->i = index;
        map->put(index,tt);
      }

      ArrayList<TTInt> keys = map->entrySet();
      int size = keys->size();
      for(int index = 0;index < size;index++) {
        TTInt key1 = keys->get(index);
        if(map->get(key1->i) == nullptr) {
          TEST_FAIL("[HashMap int Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<int,TTInt> map2 = createHashMap<int,TTInt>();
      ArrayList<TTInt>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap int Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap int Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<int,TTInt> map = createHashMap<int,TTInt>();
      for(int index = 0;index < 100;index++) {
        TTInt tt = createTTInt();
        tt->i = index;
        map->put(index,tt);
      }

      int index = 0;
      MapIterator<int,TTInt> iterator = map->getIterator();
      while(iterator->hasValue()) {
          int key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator int Test {getKey/getValue()} case1]");
            break;
          }

          TTInt t1 = iterator->getValue();
          if(t1->i != key) {
            TEST_FAIL("[MapIterator int Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator int Test {getKey/getValue()} case3]");
      break;

    }
}
