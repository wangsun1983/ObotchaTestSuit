#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "OrpcSerializable.hpp"
#include "Reflect.hpp"

using namespace obotcha;


DECLARE_CLASS(MyTestData) IMPLEMENTS(OrpcSerializable) {
public:
    String t1;
    int t2;
    DECLARE_REFLECT_FIELD(MyTestData,t1,t2);
};

int main() {
  MyTestData data1 = createMyTestData();
  data1->t1 = createString("hello");
  data1->t2 = 0x12;
  ByteArray d1 = data1->toByteArray();

  printf("d1 size is %d\n",d1->size());
  for(int i = 0;i < d1->size();i++) {
    printf("%x \n",d1->at(i));
  }

  MyTestData data2 = createMyTestData();
  data2->import(d1);
  printf("t1 is %s \n",data1->t1->toChars());
  printf("t2 is %d \n",data1->t2);
}
