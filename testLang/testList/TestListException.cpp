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

void testExceptoin() {
  //construct1
  while(1) {
    bool isException = false;
    List<int> values = List<int>::New(3);
    values[0] = 1;
    values[1] = 2;
    values[2] = 3;
    try {
      values[3] = 100;
    } catch(ArrayIndexOutOfBoundsException e){
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("List Exception test");
      break;
    }

    TEST_OK("List construct test");
    break;
  }
}
