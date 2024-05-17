#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ArrayList.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(ContainerData) {
public:
  int i;
};

DECLARE_CLASS(ContainerData2) IMPLEMENTS(ContainerData) {
public:
  int j;
};

void testReferenceArraylist() {
  //case 1
  while(1) {
    ContainerData ref = ContainerData::New();
    ArrayList<ContainerData> list = ArrayList<ContainerData>::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceArraylistCount test1");
      break;
    }

    list->add(ref);
    if(ref->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceArraylistCount test2");
      break;
    }

    list->clear();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceArraylistCount test3");
      break;
    }

    break;
  }

  //case 1
  while(1) {
    ContainerData2 ref = ContainerData2::New();
    ArrayList<ContainerData> list = ArrayList<ContainerData>::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceArraylistCount test4");
      break;
    }

    list->add(Cast<ContainerData>(ref));
    if(ref->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceArraylistCount test5");
      break;
    }

    list->clear();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceArraylistCount test6");
      break;
    }

    break;
  }


  TEST_OK("Object ReferenceArraylistCount test100");
}
