#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestNullMember) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;
    DECLARE_REFLECT_FIELD(MyTestNullMember,m1,m2);
};

DECLARE_CLASS(MyNullMembers) IMPLEMENTS(Serializable) {
public:
    MyTestNullMember m1;
    MyTestNullMember m2;
    MyTestNullMember m3;
    DECLARE_REFLECT_FIELD(MyNullMembers,m1,m2,m3);
};

void testOrpcSimpleNullCase() {
  MyTestNullMember data1 = MyTestNullMember::New();
  data1->m1 = "this is m1";
  data1->m2 = 100;


  MyTestNullMember data2 = MyTestNullMember::New();
  data2->m2 = 12;

  MyNullMembers members = MyNullMembers::New();
  members->m1 = data1;
  members->m2 = data2;

  ByteArray data = members->serialize();

  MyNullMembers newMembers = MyNullMembers::New();
  newMembers->deserialize(data);

  //printf("data1 m1 is %s,m2 is %d \n",newMembers->m1->m1->toChars(),newMembers->m1->m2);
  
  if(newMembers->m2->m1 != nullptr) {
    TEST_FAIL("Serializable testNullCase case1");
  }

  if(!newMembers->m1->m1->sameAs("this is m1") || newMembers->m1->m2 != 100) {
    TEST_FAIL("Serializable testNullCase case2");
  }

  if(newMembers->m2->m2 != 12) {
    TEST_FAIL("Serializable testNullCase case3");
  }

  if(newMembers->m3 != nullptr) {
    TEST_FAIL("Serializable testNullCase case4");
  }

  TEST_OK("Serializable testNullCase case100");
  
}
