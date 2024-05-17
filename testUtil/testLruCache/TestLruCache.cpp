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

DECLARE_CLASS(MyData) {
public:
  int i;

  ~_MyData() {
    //TEST_FAIL("release mydata : %d ",i);
  }
};

int testLruAdd() {

    //case 1
    while(1) {
      LruCache<String,MyData> lru = LruCache<String,MyData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyData d = MyData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      if(lru->size() != 3) {
        TEST_FAIL("[LruCache Test {put()} case1]");
        return 1;
      }

      MyData m1 = lru->get(String::New(14));
      MyData m2 = lru->get(String::New(13));
      MyData m3 = lru->get(String::New(12));

      if(m1 == nullptr || m2 == nullptr || m3 == nullptr) {
        TEST_FAIL("[LruCache Test {put()} case2]");
        return 1;
      }

      if(m1->i != 14 && m2->i != 13 && m3->i != 12) {
        TEST_FAIL("[LruCache Test {put()} case3]");
        return 1;
      }

      TEST_OK("[LruCache Test {put()} case4]");
      break;
    }

    //case 2
    while(1) {
      LruCache<String,MyData> lru = LruCache<String,MyData>::New(3);
      for(int i = 0;i < 15;i++) {
        MyData d = MyData::New();
        d->i = i;
        lru->put(String::New(i),d);
      }

      MyData m1 = lru->at(0); //14
      MyData m2 = lru->at(1); //13
      MyData m3 = lru->at(2); //12
      if(m1->i != 14 && m2->i != 13 && m3->i != 12) {
        TEST_FAIL("[LruCache Test {put()} case5]");
        return 1;
      }

      lru->get(String::New(13));
      m1 = lru->at(0); //13
      m2 = lru->at(1); //14
      m3 = lru->at(2); //12
      if(m1->i != 13 && m2->i != 14 && m3->i != 12) {
        TEST_FAIL("[LruCache Test {put()} case6]");
        return 1;
      }

      lru->get(String::New(12));
      m1 = lru->at(0); //12
      m2 = lru->at(1); //13
      m3 = lru->at(2); //14
      if(m1->i != 12 && m2->i != 13 && m3->i != 14) {
        TEST_FAIL("[LruCache Test {put()} case7]");
        return 1;
      }

      lru->get(String::New(14));
      m1 = lru->at(0); //14
      m2 = lru->at(1); //12
      m3 = lru->at(2); //13
      if(m1->i != 14 && m2->i != 12 && m3->i != 13) {
        TEST_FAIL("[LruCache Test {put()} case8]");
        return 1;
      }

      TEST_OK("[LruCache Test {put()} case9]");
      break;
    }

    return 0;
}
