#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testMapRead();
extern void testMapWrite();
extern void testMapGetInputStream();
extern void testSize();

int main() {
  testSize();
  testMapRead();
  testMapWrite();
  testMapGetInputStream();
  return 0;
}
