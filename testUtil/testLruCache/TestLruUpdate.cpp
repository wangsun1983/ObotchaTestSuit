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

DECLARE_CLASS(MyUpdateData) {
public:
  int i;

  ~_MyUpdateData() {
    //TEST_FAIL("release mydata : %d ",i);
  }
};

int testLruUpdate() {
    //case 1
    while(1) {
      LruCache<String,MyUpdateData> lru = LruCache<String,MyUpdateData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyUpdateData d = MyUpdateData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {update()} case1]");
        return 1;
      }

      //[14,13,12]
      MyUpdateData data1 = MyUpdateData::New();
      data1->i = 15;
      lru->put(String::New(15),data1);
      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {update()} case2]");
        return 1;
      }

      MyUpdateData m1 = lru->at(0); //15
      MyUpdateData m2 = lru->at(1); //14
      MyUpdateData m3 = lru->at(2); //13

      if(m1 == nullptr || m2 == nullptr || m3 == nullptr) {
        TEST_FAIL("[LruCache Test {update()} case3]");
        return 1;
      }

      if(m1->i != 15 || m2->i != 14 || m3->i != 13) {
        TEST_FAIL("[LruCache Test {update()} case4],m1->i is %d,m2->i is %d,m3->i is %d ",m1->i,m2->i,m3->i);
        
        return 0;
      }
      TEST_OK("[LruCache Test {update()} case4]");
      break;
    }

    //case 2
    while(1) {
      LruCache<String,MyUpdateData> lru = LruCache<String,MyUpdateData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyUpdateData d = MyUpdateData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {update()} case5]");
        return 1;
      }

      //[14,13,12]
      MyUpdateData data1 = lru->get(String::New(12)); //->[12,14,13]

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {update()} case6]");
        return 1;
      }

      MyUpdateData m1 = lru->at(0); //12
      MyUpdateData m2 = lru->at(1); //14
      MyUpdateData m3 = lru->at(2); //13

      if(m1 == nullptr || m2 == nullptr || m3 == nullptr) {
        TEST_FAIL("[LruCache Test {update()} case7]");
        return 1;
      }

      if(m1->i != 12 || m2->i != 14 || m3->i != 13) {
        TEST_FAIL("[LruCache Test {update()} case8],m1->i is %d,m2->i is %d,m3->i is %d ",m1->i,m2->i,m3->i);
        
        return 0;
      }
      TEST_OK("[LruCache Test {update()} case9]");
      break;
    }

    //case 3
    while(1) {
      LruCache<String,MyUpdateData> lru = LruCache<String,MyUpdateData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyUpdateData d = MyUpdateData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {update()} case10]");
        return 1;
      }

      //[14,13,12]
      MyUpdateData data1 = lru->get(String::New(14)); //->[14,13,12]

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {update()} case11]");
        return 1;
      }

      MyUpdateData m1 = lru->at(0); //12
      MyUpdateData m2 = lru->at(1); //14
      MyUpdateData m3 = lru->at(2); //13

      if(m1 == nullptr || m2 == nullptr || m3 == nullptr) {
        TEST_FAIL("[LruCache Test {update()} case12]");
        return 1;
      }

      if(m1->i != 14 || m2->i != 13 || m3->i != 12) {
        TEST_FAIL("[LruCache Test {update()} case13],m1->i is %d,m2->i is %d,m3->i is %d ",m1->i,m2->i,m3->i);
        
        return 0;
      }
      TEST_OK("[LruCache Test {update()} case14] [OK]");
      break;
    }

    return 0;
}
