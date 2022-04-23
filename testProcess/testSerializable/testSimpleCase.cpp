#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestMember) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;
    
    bool equals(MyTestMember s) {
      return m2 == s->m2 && m1->equals(s->m1);
    }

    DECLARE_REFLECT_FIELD(MyTestMember,m1,m2);
};

DECLARE_CLASS(MyTestData) IMPLEMENTS(Serializable) {
public:
    String t1;
    int t2;
    Integer t3;

    MyTestMember member1;

    bool equals(MyTestData s) {
      return t1->equals(s->t1) && t2 == s->t2 && t3->toValue() == s->t3->toValue();
    }

    DECLARE_REFLECT_FIELD(MyTestData,t1,t2,t3,member1);
};

void testOrpcSimpleCase() {
  MyTestData data1 = createMyTestData();
  data1->member1 = createMyTestMember();
  data1->member1->m1 = createString("hello,this is m1");
  data1->member1->m2 = 1000;

  data1->t1 = createString("hello");
  data1->t2 = 88;
  data1->t3 = createInteger(2211);
  ByteArray d1 = data1->serialize();

  MyTestData data2 = DeSerialize<MyTestData>(d1);
  if(!data2->equals(data1)) {
    TEST_FAIL("testSerializable testSimpleCase case1");
  }

  TEST_OK("testSerializable testSimpleCase case100");
  
}
