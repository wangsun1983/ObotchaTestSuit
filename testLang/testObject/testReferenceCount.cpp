#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(TestDataRef) {
public:
  int i;
};

DECLARE_CLASS(TestDataRef2) IMPLEMENTS(TestDataRef) {
public:
  int j;
};

void testReferenceCount() {
  //case 1
  while(1) {
    TestDataRef ref = TestDataRef::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceCount test1");
      break;
    }

    TestDataRef ref2 = ref;
    if(ref->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceCount test2");
      break;
    }

    {
      TestDataRef ref3 = ref;
      if(ref->getStrongCount() != 3) {
        TEST_FAIL("Object ReferenceCount test3");
        break;
      }
    }

    if(ref->getStrongCount() != 2) {
        TEST_FAIL("Object ReferenceCount test4");
        break;
    }

    break;
  }

  //case 2
  while(1) {
    TestDataRef2 ref = TestDataRef2::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceCount test5");
      break;
    }

    TestDataRef ref2 = ref;
    if(ref2->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceCount test6");
      break;
    }

    {
      TestDataRef ref3 = ref;
      if(ref->getStrongCount() != 3) {
        TEST_FAIL("Object ReferenceCount test7");
        break;
      }
    }

    if(ref->getStrongCount() != 2 || ref2->getStrongCount() != 2) {
        TEST_FAIL("Object ReferenceCount test8");
        break;
    }
    break;
  }

  //case 3
  while(1) {
    TestDataRef ref = TestDataRef::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceCount test9");
      break;
    }

    TestDataRef ref2 = AutoClone(ref.get_pointer());
    if(ref2->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceCount test10");
      break;
    }

    TestDataRef ref3 = ref.get_pointer();
    if(ref2->getStrongCount() != 3) {
      TEST_FAIL("Object ReferenceCount test11");
      break;
    }

    if(ref3 == ref2) {
      if(ref3->getStrongCount() != 3) {
        TEST_FAIL("Object ReferenceCount test10");
        break;
      }
    }
    break;
  }

  //case 3
  while(1) {
    TestDataRef ref = TestDataRef::New();
    if(ref->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceCount test11");
      break;
    }

    TestDataRef ref2 = TestDataRef::New();
    if(ref2->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceCount test12");
      break;
    }

    TestDataRef ref3 = ref;
    if(ref3->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceCount test13");
      break;
    }

    ref = ref2;
    if(ref3->getStrongCount() != 1) {
      TEST_FAIL("Object ReferenceCount test14");
      break;
    }

    if(ref2->getStrongCount() != 2) {
      TEST_FAIL("Object ReferenceCount test15");
      break;
    }

    break;
  }

  TEST_OK("Object ReferenceCount test100");
}
