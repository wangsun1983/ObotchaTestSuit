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

DECLARE_CLASS(IteratorData) {
public:
  int i;
  int j;
};

void testIterator() {
  //construct1
  while(1) {
    List<IteratorData> mylist1 = createList<IteratorData>(4);
    IteratorData data1 = createIteratorData();
    data1->i = 1;
    data1->j = 10;

    IteratorData data2 = createIteratorData();
    data2->i = 2;
    data2->j = 20;

    IteratorData data3 = createIteratorData();
    data3->i = 3;
    data3->j = 30;

    mylist1[0] = data1;
    mylist1[1] = data2;
    mylist1[2] = data3;

    auto iterator = mylist1->getIterator();
    int count = 0;
    while(iterator->hasValue()) {
        auto value = iterator->getValue();
        switch(count) {
            case 0:
                if(value->i != 1 || value->j != 10) {
                    TEST_FAIL("List Iterator case1,i is %d,j is %d",value->i,value->j);
                }
                break;
                
            case 1:
                if(value->i != 2 || value->j != 20) {
                    TEST_FAIL("List Iterator case2,i is %d,j is %d",value->i,value->j);
                }
                break;
            
            case 2:
                if(value->i != 3 || value->j != 30) {
                    TEST_FAIL("List Iterator case3,i is %d,j is %d",value->i,value->j);
                }
                break;
        }
        count++;
        iterator->next();
        break;
    }

    TEST_OK("List Iterator case100");
    break;
  }
}
