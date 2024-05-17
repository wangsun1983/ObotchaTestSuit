#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Boolean.hpp"
#include "Boolean.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TestHashKey) {
public:
  int value;

  bool equals(TestHashKey v) {
    return value == v->value;
  }

  uint64_t hashcode() {
    return value;
  }
};

DECLARE_CLASS(TestHashKey2) {
public:
  int value;

  bool equals(TestHashKey2 v) {
    return value == v->value;
  }
};

DECLARE_CLASS(TestHashKey3) {
public:
  int value;

  uint64_t hashcode() {
    return value;
  }
};

void testHashMapHashKey() {
    while(1) {
      HashMap<TestHashKey,String> map = HashMap<TestHashKey,String>::New();
      TestHashKey key = TestHashKey::New();
      key->value = 1;
      map->put(key,String::New("aaa"));

      TestHashKey key2 = TestHashKey::New();
      key2->value = 1;
      map->put(key2,String::New("aaa"));

      if(map->size() != 1) {
        TEST_FAIL("[HashMap test HashKey} test1]");
        break;
      }

      TestHashKey key3 = TestHashKey::New();
      key3->value = 1;
      String str = map->get(key3);
      if(str == nullptr) {
        TEST_FAIL("[HashMap test HashKey} test2]");
        break;
      }

      if(!str->sameAs("aaa")) {
        TEST_FAIL("[HashMap test HashKey} test3]");
        break;
      }

      break;
    }

    while(1) {
      HashMap<TestHashKey2,String> map = HashMap<TestHashKey2,String>::New();
      TestHashKey2 key = TestHashKey2::New();
      key->value = 1;
      map->put(key,String::New("aaa"));

      TestHashKey2 key2 = TestHashKey2::New();
      key2->value = 1;
      map->put(key2,String::New("aaa"));

      if(map->size() != 2) {
        TEST_FAIL("[HashMap test HashKey} test4]");
        break;
      }

      TestHashKey2 key3 = TestHashKey2::New();
      key3->value = 1;
      if(map->get(key3)!= nullptr) {
        TEST_FAIL("[HashMap test HashKey} test5]");
        break;
      }

      String str1 = map->get(key);
      if(str1 == nullptr || !str1->sameAs("aaa")) {
        TEST_FAIL("[HashMap test HashKey} test6]");
        break;
      }

      String str2 = map->get(key2);
      if(str2 == nullptr || !str2->sameAs("aaa")) {
        TEST_FAIL("[HashMap test HashKey} test7]");
        break;
      }

      break;
    }

    while(1) {
      HashMap<TestHashKey3,String> map = HashMap<TestHashKey3,String>::New();
      TestHashKey3 key = TestHashKey3::New();
      key->value = 1;
      map->put(key,String::New("aaa"));

      TestHashKey3 key2 = TestHashKey3::New();
      key2->value = 1;
      map->put(key2,String::New("bbb"));

      if(map->size() != 2) {
        TEST_FAIL("[HashMap test HashKey} test8] [FAIL],map size is %d ",map->size());
        break;
      }

      TestHashKey3 key3 = TestHashKey3::New();
      key3->value = 1;
      if(map->get(key3)!= nullptr) {
        TEST_FAIL("[HashMap test HashKey} test9]");
        break;
      }

      String str1 = map->get(key);
      if(str1 == nullptr || !str1->sameAs("aaa")) {
        TEST_FAIL("[HashMap test HashKey} test10]str1 is %s ",str1->toChars());
        break;
      }

      String str2 = map->get(key2);
      if(str2 == nullptr || !str2->sameAs("bbb")) {
        TEST_FAIL("[HashMap test HashKey} test11]str2 is %s ",str2->toChars());
        break;
      }

      break;
    }

    

    TEST_OK("[HashMap test HashKey} test100]");
}
