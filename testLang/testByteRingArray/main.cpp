#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"

using namespace obotcha;

extern void normal_test();
extern void push_test();
extern void testByteRingArrayPush2();
extern void testByteRingArrayPop();
extern void testStartIndex();
extern void testPopAll();
extern void testPopTo();
extern void testByteRingArrayPopWithParam();
extern void testByteArrayCapacity();
extern void testSetStartIndex();
extern void testSetNextIndex();
extern void testBytRingArrayEdgeDetection();
extern void testByteRingArrayPushOne();

int main() {
  //testByteRingArrayPushOne();

  testBytRingArrayEdgeDetection();
  testSetStartIndex();
  testSetNextIndex();
  testByteArrayCapacity();
  testStartIndex();
  normal_test();
  push_test();
  testByteRingArrayPush2();
  testByteRingArrayPop();
  testPopAll();
  testPopTo();
  testByteRingArrayPopWithParam();

  return 0;
}
