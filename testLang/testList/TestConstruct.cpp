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

DECLARE_CLASS(ConstructData) {
public:
  int i;
  int j;
};

void testConstruct() {
  //construct1
  while(1) {
    List<ConstructData> mylist1 = createList<ConstructData>(4);
    ConstructData data1 = createConstructData();
    data1->i = 1;
    data1->j = 1;

    ConstructData data2 = createConstructData();
    data2->i = 2;
    data2->j = 2;

    ConstructData data3 = createConstructData();
    data3->i = 3;
    data3->j = 3;

    mylist1[0] = data1;
    mylist1[1] = data2;
    mylist1[2] = data3;

    List<ConstructData> mylist2 = createList<ConstructData>(mylist1);
    if(mylist2[0]->i != 1 || mylist2[0]->j != 1) {
      TEST_FAIL("List construct test");
      break;
    }

    if(mylist2[1]->i != 2 || mylist2[1]->j != 2) {
      TEST_FAIL("List construct test1");
      break;
    }

    if(mylist2[2]->i != 3 || mylist2[2]->j != 3) {
      TEST_FAIL("List construct test");
      break;
    }

    TEST_OK("List construct test");
    break;
  }
}
