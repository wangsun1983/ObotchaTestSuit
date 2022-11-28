#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"

using namespace obotcha;

//extern void testOrpcSimpleCase();
extern void testOrpcArrayList();
extern void testOrpcHashMap();
extern void testInnerClass();
extern void testByteArray();
extern void testOrpcSimpleNullCase();
extern void testSimpleMsg();
extern void testOrpcDifferentClass();
extern void testSimpleCase();

int main() {
  testSimpleMsg();
  testOrpcSimpleNullCase();
  //testOrpcSimpleCase();
  testOrpcArrayList();
  testOrpcHashMap();
  testInnerClass();
  testByteArray();
  //testSimpleCase();
}
