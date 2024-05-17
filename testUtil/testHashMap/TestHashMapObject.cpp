#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"


using namespace obotcha;

DECLARE_CLASS(MyKey) {
public:
  int i;
  _MyKey(int v) {
    i = v;
  }

  int toValue() {
    return i;
  }

  bool equals(MyKey s) {
    return s->i == i;
  }

  bool equals(_MyKey *s) {
    return s->i == i;
  }

  uint64_t hashcode() {
    return i;
  }
};

DECLARE_CLASS(MyValue) {
public:
  int i;

};

void testHashMapObject() {

    //void put(T t,U u)/get(T t)
    while(1) {
        HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
        MyKey tag = MyKey::New(1);
        MyValue tt = MyValue::New();
        tt->i = 100;
        map->put(tag,tt);
        if(map->size() != 1) {
            TEST_FAIL("[HashMap MyKey Test {put(T t,U u)/get(T t)} case1]");
            break;
        }

        MyValue tt2 = map->get(tag);
        if(tt2 == nullptr || tt2->i != 100) {
          TEST_FAIL("[HashMap MyKey Test {put(T t,U u)/get(T t)} case2]");
          break;
        }

        map->put(MyKey::New(2),nullptr);
        if(map->size() != 2) {
          TEST_FAIL("[HashMap MyKey Test {put(T t,U u)/get(T t)} case3]");
          break;
        }

        MyValue MyValue = map->get(nullptr);
        if(MyValue != nullptr) {
          TEST_FAIL("[HashMap MyKey Test {put(T t,U u)/get(T t)} case4]");
          break;
        }

        TEST_OK("[HashMap MyKey Test {put(T t,U u)/get(T t)} case5]");
        break;
    }

    //void remove(T t)
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      MyKey tag = MyKey::New(1);
      MyValue tt = MyValue::New();
      tt->i = 100;
      map->put(tag,tt);

      int size = map->size();
      map->remove(MyKey::New(1));
      if(size != 1 && map->size() != 0) {
        TEST_FAIL("[HashMap MyKey Test {remove(T t)} case1]");
        break;
      }

      map->put(tag,tt);
      size = map->size();
      map->remove(nullptr);
      if(map->size() != 1) {
        TEST_FAIL("[HashMap MyKey Test {remove(T t)} case2]");
        break;
      }

      map->remove(MyKey::New(1));
      if(map->size() != 0) {
        TEST_FAIL("[HashMap MyKey Test {remove(T t)} case3]");
        break;
      }

      TEST_OK("[HashMap MyKey Test {remove(T t)} case4]");
      break;
    }

    //bool isEmpty()
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      MyKey tag = MyKey::New(1);
      MyValue tt = MyValue::New();
      tt->i = 100;
      map->put(tag,tt);

      if(map->isEmpty()) {
        TEST_FAIL("[HashMap MyKey Test {isEmpty()} case1]");
        break;
      }

      map->remove(MyKey::New(1));
      if(!map->isEmpty()) {
        TEST_FAIL("[HashMap MyKey Test {isEmpty()} case2]");
        break;
      }

      TEST_OK("[HashMap MyKey Test {isEmpty()} case3]");
      break;
    }

    //void clear()
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      MyKey tag = MyKey::New(1);
      MyValue tt = MyValue::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(MyKey::New(2),tt);

      int size = map->size();
      map->clear();
      if(size != 2 || map->size() != 0) {
        TEST_FAIL("[HashMap MyKey Test {clear()} case1]");
        break;
      }

      HashMap<MyKey,MyValue> map2 = HashMap<MyKey,MyValue>::New();
      map2->clear();
      if(map2->size() != 0) {
        TEST_FAIL("[HashMap MyKey Test {clear()} case2]");
        break;
      }

      TEST_OK("[HashMap MyKey Test {clear()} case3]");
      break;
    }

    //int size()
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      MyKey tag = MyKey::New(1);
      MyValue tt = MyValue::New();
      tt->i = 100;
      map->put(tag,tt);
      map->put(MyKey::New(2),tt);
      if(map->size() != 2 ) {
        TEST_FAIL("[HashMap MyKey Test {size()} case1]");
        break;
      }

      TEST_OK("[HashMap MyKey Test {size()} case1]");
      break;
    }

    //ArrayList<V> keySet()
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      for(int index = 0;index < 100;index++) {
        MyValue tt = MyValue::New();
        tt->i = index;
        map->put(MyKey::New(index),tt);
      }

      ArrayList<MyKey> keys = map->keySet();
      int size = keys->size();
      if(size != 100) {
        TEST_FAIL("[HashMap MyKey Test {keySet()} case1]");
        break;
      }

      for(int index = 0;index < size;index++) {
        MyKey key1 = keys->get(index);
        if(map->get(key1) == nullptr) {
          //TEST_FAIL("key1->int is %d,index is %d ",key1->toValue(),index);
          TEST_FAIL("[HashMap MyKey Test {keySet()} case2]");
          break;
        }
      }

      HashMap<MyKey,MyValue> map2 = HashMap<MyKey,MyValue>::New();
      ArrayList<MyKey>keys2 = map2->keySet();
      if(keys2->size() != 0) {
          TEST_FAIL("[HashMap MyKey Test {keySet()} case3]");
          break;
      }

      TEST_OK("[HashMap MyKey Test {keySet()} case4]");
      break;
    }

    //ArrayList<V> entrySet()
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      for(int index = 0;index < 100;index++) {
        MyValue tt = MyValue::New();
        MyKey kk = MyKey::New(index);
        tt->i = index;
        map->put(kk,tt);
      }

      ArrayList<MyKey> keys = map->keySet();
      int size = keys->size();

      for(int index = 0;index < size;index++) {
        MyKey key1 = keys->get(index);
        MyValue v1 = map->get(MyKey::New(key1->i));
        if(v1 == nullptr) {
          TEST_FAIL("[HashMap MyKey Test {entrySet()} case1]");
          break;
        }
      }

      HashMap<MyKey,MyValue> map2 = HashMap<MyKey,MyValue>::New();
      ArrayList<MyValue>values = map2->entrySet();
      if(values->size() != 0) {
          TEST_FAIL("[HashMap MyKey Test {entrySet()} case2]");
          break;
      }

      TEST_OK("[HashMap MyKey Test {entrySet()} case3]");
      break;
    }


    //_MapIterator(getKey/getValue)
    while(1) {
      HashMap<MyKey,MyValue> map = HashMap<MyKey,MyValue>::New();
      for(int index = 0;index < 100;index++) {
        MyValue tt = MyValue::New();
        tt->i = index;
        map->put(MyKey::New(index),tt);
      }

      int index = 0;
      MapIterator<MyKey,MyValue> iterator = map->getIterator();
      while(iterator->hasValue()) {
          MyKey key = iterator->getKey();
          if(map->get(key) == nullptr) {
            TEST_FAIL("[MapIterator MyKey Test {getKey/getValue()} case1]");
            break;
          }

          MyValue t1 = iterator->getValue();
          if(t1->i != key->toValue()) {
            TEST_FAIL("[MapIterator MyKey Test {getKey/getValue()} case2]");
            break;
          }
          iterator->next();
          index++;
      }

      TEST_OK("[MapIterator MyKey Test {getKey/getValue()} case3]");
      break;

    }


}
