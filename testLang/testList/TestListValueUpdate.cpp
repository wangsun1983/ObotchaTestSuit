#include <stdio.h>
#include <unistd.h>
#include <vector>
//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint8.hpp"
#include "StrongPointer.hpp"
#include "Uint8.hpp"
#include "List.hpp"
#include "TestLog.hpp"

using namespace std;
using namespace obotcha;

DECLARE_CLASS(TestUpdateData) {
public:
  int i;
  int j;
};

void testListValueUpdate() {
  //construct1
  while(1) {
    List<TestUpdateData> values =  createList<TestUpdateData>(5);
    TestUpdateData data1 = createTestUpdateData();
    values[0] = data1;
    data1->i = 123;
    data1->j = 456;

    TestUpdateData data2 = values[0];
    if(data2->i != 123 ||data2->j != 456) {
      TEST_FAIL("List ValueUpdate test1");
      break;
    }

    TEST_OK("List ValueUpdate test100");
    break;
  }
}
