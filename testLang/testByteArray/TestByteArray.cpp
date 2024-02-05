#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"

using namespace obotcha;

extern void basetest();
extern void operatortest();
extern void dumptest();
extern void testgrow();
extern void testappend();
extern void testsafemode();
extern void testForeach();
extern void testConstruct();
extern void testByteArrayClear();
extern void testByteArrayStruct();
extern void testByteArrayStringConvert();
extern void testPriority();
extern void testByteArrayEquals();
extern void testByteArrayCombine();
extern void testByteArrayToValue();
extern void testByteArrayClone();
extern void testByteArrayQuickRestore();
extern void testByteArrayFillFrom();
extern void testByteArrayIsOverFlow();
extern void testByteArrayslice();
extern void testByteArrayTranslate();

int main() {
  testByteArrayTranslate();
  testByteArrayslice();
  testByteArrayIsOverFlow();
  testByteArrayFillFrom();
  testByteArrayQuickRestore();
  testByteArrayClone();
  testByteArrayToValue();
  testByteArrayCombine();
  testByteArrayEquals();
  testByteArrayStringConvert();
  testByteArrayStruct();
  basetest();
  operatortest();
  dumptest();
  testgrow();
  testappend();
  testsafemode();
  testForeach();
  testConstruct();
  testByteArrayClear();
  testPriority();

  return 0;
}
