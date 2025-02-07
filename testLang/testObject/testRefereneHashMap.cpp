#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "HashMap<String,HashMapData>.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(HashMapData) {
public:
  int i;
};

DECLARE_CLASS(HashMapData2) IMPLEMENTS(HashMapData) {
public:
  int j;
};

void testReferenceHashMap() {
  //case 1
  while(1) {
    HashMapData ref = HashMapData::New();
    HashMap<String,HashMapData> list = HashMap<String,HashMapData>::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceHashMap<String,HashMapData>Count test1");
      break;
    }

    list->put(String::New("tag"),ref);
    if(ref->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceHashMap<String,HashMapData>Count test2");
      break;
    }

    list->clear();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceHashMap<String,HashMapData>Count test3");
      break;
    }

    break;
  }

  //case 1
  while(1) {
    HashMapData2 ref = HashMapData2::New();
    HashMap<String,HashMapData> list = HashMap<String,HashMapData>::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceHashMap<String,HashMapData>Count test4");
      break;
    }

    list->put(String::New("tag"),Cast<HashMapData>(ref));
    if(ref->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceHashMap<String,HashMapData>Count test5");
      break;
    }

    list->clear();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceHashMap<String,HashMapData>Count test6");
      break;
    }

    break;
  }

  TEST_OK("Object ReferenceHashMap<String,HashMapData>Count test100");
}
