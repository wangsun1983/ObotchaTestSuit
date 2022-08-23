#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "HashMap<String,HashMapData>.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ClassData) {
public:
  int i;
};

void testAutoCreator() {
  ClassData d = AutoCreate<ClassData>();
  d->i = 100;
  if(d->i != 100) {
    TEST_FAIL("testAutoCreator case1");
  }
  TEST_OK("testAutoCreator case1");
}
