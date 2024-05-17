#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

DECLARE_CLASS(Lambda1) {
public:
  int i;
};

void testHashMapLambda() {
  HashMap<int,Lambda1> map = HashMap<int,Lambda1>::New();
  Lambda1 t1 = Lambda1::New();
  t1->i = 123;

  Lambda1 t2 = Lambda1::New();
  t2->i = 456;

  Lambda1 t3 = Lambda1::New();
  t3->i = 789;

  map->put(1,t1);
  map->put(2,t2);
  map->put(3,t3);

  //map->foreach([](int key,Lambda1 value) {
  //  TEST_FAIL("key is %d,value is %d ",key,value->i);
  //  return 1;
  //});
  ForEveryOne(pair,map) {
    auto value = map->get(pair->getKey());
    if(value->i != pair->getValue()->i) {
      TEST_FAIL("testHashMapLambda,value is %d,pair value is %d",value->i,pair->getValue()->i);
    }
  }

  TEST_OK("testHashMapLambda case100");

}
