#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TestData1) {
public:
  _TestData1(int i) {
    value = i;
  }

  uint64_t hashcode() {
    return 1;
  }

  bool equals(const TestData1 t1) {
      return true;
  }

private:
  int value;
};

DECLARE_CLASS(TestData2) {
public:
  int j;

  bool equals(TestData2 v) {
    return j == v->j;
  }
};

DECLARE_CLASS(TestData3) {
public:
  int j;

  bool equals(TestData3 v) {
    return false;
  }
};

DECLARE_CLASS(DataTT) {
public:
  int j;
};

DECLARE_CLASS(Student) {
public:
  int j;

  bool equals(DataTT v) {
    return j == v->j;
  }
};

void testEqual() {
  while(1) {
    TestData1 d1 = TestData1::New(1);
    TestData1 d2 = TestData1::New(2);
    if(d1 != d2) {
      TEST_FAIL("Object Equal test1");
      break;
    }

    TestData2 d3 = TestData2::New();
    d3->j = 10;
    TestData2 d4 = TestData2::New();
    d4->j = 10;
    if(d3 != d4) {
      TEST_FAIL("Object Equal test2");
      break;
    }

    //inline bool operator == (const sp<U>& o) const {
    TestData3 d5 = TestData3::New();
    d3->j = 10;
    TestData3 d6 = TestData3::New();
    d4->j = 10;
    if(d5 == d6) {
      TEST_FAIL("Object Equal test3");
      break;
    }

    // Student s1 = createStudent();
    // s1->j = 100;

    // DataTT s2 = createDataTT();
    // s2->j = 100;

    // if(s1 != s2) {
    //   TEST_FAIL("Object Equal test4");
    //   break;
    // }

    //inline bool operator == (const T* o) const {
    TestData1 data1 = TestData1::New(1);
    _TestData1 *data2 = new _TestData1(1);
    if(data1 != data2) {
      TEST_FAIL("Object Equal test5");
      break;
    }

    //inline bool operator == (const U* o) const {
    // _DataTT *data3 = new _DataTT();
    // data3->j = 100;

    // Student data4 = createStudent();
    // data4->j = 100;

    // if(data4 != data3) {
    //   TEST_FAIL("Object Equal test6");
    //   break;
    // }

    TEST_OK("Object Equal test5");
    break;
  }
}
