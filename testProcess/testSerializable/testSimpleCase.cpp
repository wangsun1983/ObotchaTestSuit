#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestMember) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;
    DECLARE_REFLECT_FIELD(MyTestMember,m1,m2);
};

DECLARE_CLASS(MyTestData) IMPLEMENTS(Serializable) {
public:
    String t1;
    int t2;
    Integer t3;

    MyTestMember member1;
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

  printf("d1 size is %d\n",d1->size());
  for(int i = 0;i < d1->size();i++) {
    printf("%x \n",d1->at(i));
  }

  MyTestData data2 = createMyTestData();
  data2->deserialize(d1);
  printf("t1 is %s \n",data2->t1->toChars());
  printf("t2 is %d \n",data2->t2);
  printf("t3 is %d \n",data2->t3->toValue());

  printf("m1 is %s \n",data2->member1->m1->toChars());
  printf("m22 is %d \n",data2->member1->m2);
}
