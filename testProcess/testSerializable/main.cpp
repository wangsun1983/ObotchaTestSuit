#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"

using namespace obotcha;

extern void testOrpcSimpleCase();
extern void testOrpcArrayList();
extern void testOrpcHashMap();
extern void testInnerClass();
extern void testByteArray();

int main() {
  //testOrpcSimpleCase();
  //testOrpcArrayList();
  // testOrpcHashMap();
  //testInnerClass();
  testByteArray();
}