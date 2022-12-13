#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "TransformException.hpp"

using namespace obotcha;

extern void basetest();
extern void ignorecasetest();
extern void trimtest();
extern void appendtest();
extern void splittest();
extern void equaltest();
extern void formattest();
extern void StringConstructTest();
extern void TestStringUpdate();
extern void TestStringToChars();
extern void TestStringCharAt();
extern void TestStringSubString();
extern void TestStringTrim();
extern void TestStringTrimAll();
extern void TestStringSize();
extern void TestStringContains();
extern void TestStringIndexOf();
extern void TestStringEquals();
extern void TestCounts();
extern void trimPerformance();
extern void StringContentEqualsTest();
extern void testStringFind();
extern void TestStringHashcode();
extern void TestStringStartsWithIgnoreCase();
extern void TestStringToUint();

int main() {
  TestStringToUint();

  testStringFind();

  StringContentEqualsTest();
  
  basetest();

  ignorecasetest();

  trimtest();

  appendtest();

  splittest();

  equaltest();

  formattest();

  StringConstructTest();

  TestStringUpdate();

  TestStringToChars();

  TestStringCharAt();

  TestStringSubString();

  TestStringTrim();

  TestStringTrimAll();

  TestStringSize();

  TestStringContains();

  TestStringIndexOf();

  TestStringEquals();

  TestCounts();
  
  TestStringHashcode();
  
  TestStringStartsWithIgnoreCase();

  return 0;
}
