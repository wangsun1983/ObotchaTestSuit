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
extern void TestBinaryInt();
extern void TestStringStartsWith();
extern void TestStringFloatToString();
extern void TestStringStaticIgnoreCase();
extern void TestStringRegionMatches();
extern void TestStringregionMatchesIgnoreCase();
extern void TestHexInt();
extern void TestOctInt();
extern void TestStringEndsWith();

int main() {

  TestStringEndsWith();

  TestOctInt();
  
  TestHexInt();
  
  TestStringregionMatchesIgnoreCase();
  
  TestStringRegionMatches();
  
  TestStringFloatToString();

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
  
  TestBinaryInt();
  
  TestStringStartsWith();

  TestStringStaticIgnoreCase();

  return 0;
}
