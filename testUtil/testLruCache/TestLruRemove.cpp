#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "LruCache.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestData) {
public:
  int i;

  ~_MyTestData() {
    //TEST_FAIL("release mydata : %d ",i);
  }
};

int testLruRemove() {

    //case 1
    while(1) {
      LruCache<String,MyTestData> lru = LruCache<String,MyTestData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyTestData d = MyTestData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {remove()} case1]");
        return 1;
      }
      //[14,13,12]
      lru->remove(String::New(14));
      if(lru->size() != 2) {
        TEST_FAIL("[LruCache Test {remove()} case2]");
        return 1;
      }

      MyTestData m1 = lru->at(0); //13
      MyTestData m2 = lru->at(1); //12
      if(m1 == nullptr || m2 == nullptr) {
        TEST_FAIL("[LruCache Test {remove()} case3]");
        return 1;
      }

      if(m1->i != 13 || m2->i != 12) {
        TEST_FAIL("[LruCache Test {remove()} case4],m1->i is %d,m2->i is %d ",m1->i,m2->i);
        return 1;
      }
      TEST_OK("[LruCache Test {remove()} case4]");
      break;
    }

    //case 2
    while(1) {
      LruCache<String,MyTestData> lru = LruCache<String,MyTestData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyTestData d = MyTestData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {remove()} case5]");
        return 1;
      }
      //[14,13,12]
      lru->remove(String::New(13));
      if(lru->size() != 2) {
        TEST_FAIL("[LruCache Test {remove()} case6]");
        return 1;
      }

      MyTestData m1 = lru->at(0); //14
      MyTestData m2 = lru->at(1); //12
      if(m1 == nullptr || m2 == nullptr) {
        TEST_FAIL("[LruCache Test {remove()} case7]");
        return 1;
      }

      if(m1->i != 14 || m2->i != 12) {
        TEST_FAIL("[LruCache Test {remove()} case8],m1->i is %d,m2->i is %d ",m1->i,m2->i);
        
        return 1;
      }
      TEST_OK("[LruCache Test {remove()} case9]");
      break;
    }

    //case 3
    while(1) {
      LruCache<String,MyTestData> lru = LruCache<String,MyTestData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyTestData d = MyTestData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {remove()} case10]");
        return 1;
      }
      //[14,13,12]
      lru->remove(String::New(12));
      if(lru->size() != 2) {
        TEST_FAIL("[LruCache Test {remove()} case11]");
        return 1;
      }

      MyTestData m1 = lru->at(0); //14
      MyTestData m2 = lru->at(1); //13
      if(m1 == nullptr || m2 == nullptr) {
        TEST_FAIL("[LruCache Test {remove()} case12]");
        return 1;
      }

      if(m1->i != 14 || m2->i != 13) {
        TEST_FAIL("[LruCache Test {remove()} case13],m1->i is %d,m2->i is %d ",m1->i,m2->i);
        
        return 1;
      }

      TEST_OK("[LruCache Test {remove()} case14]");
      break;
    }
    return 0;
}
