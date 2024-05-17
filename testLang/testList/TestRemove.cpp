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

DECLARE_CLASS(TestRemoveData) {
public:
  int i;
  int j;
};

void testRemove() {
  //construct1
  while(1) {
    List<TestRemoveData> mylist1 = List<TestRemoveData>::New(4);
    TestRemoveData data1 = TestRemoveData::New();
    data1->i = 1;
    data1->j = 10;

    TestRemoveData data2 = TestRemoveData::New();
    data2->i = 2;
    data2->j = 20;

    TestRemoveData data3 = TestRemoveData::New();
    data3->i = 3;
    data3->j = 30;

    mylist1[0] = data1;
    mylist1[1] = data2;
    mylist1[2] = data3;

    auto iterator = mylist1->getIterator();
    int count = 0;
    while(iterator->hasValue()) {
        if(count%2 == 0) {
			iterator->remove();
		}
        iterator->next();
    }
	
	int nextCount = 0;
	auto iterator2 = mylist1->getIterator();
	while(iterator->hasValue()) {
		if(nextCount%2 == 0 && iterator2->getValue() != nullptr) {
			TEST_FAIL("List Iterator Remove case1");
		}
		
		if(nextCount%2 != 0 && iterator2->getValue() == nullptr) {
			TEST_FAIL("List Iterator Remove case2");
		}
		iterator2->next();
	}

    TEST_OK("List Iterator Remove case100");
    break;
  }
}
